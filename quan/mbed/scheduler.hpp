#ifndef QUAN_MBED_SCHEDULER_HPP_INCLUDED
#define QUAN_MBED_SCHEDULER_HPP_INCLUDED

// This class uses asserts
// for release define NDEBUG

//define for scheduler to use a std::list elses uses intrusive list 
//#define QUAN_MBED_SCHEDULER_USE_STD_LIST

#include <quan/time.hpp>
#include <cassert>
#if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
#include <list>
#else
#include <quan/mbed/dlist_element.hpp>
#endif

namespace  quan{ namespace mbed{

   /*
      A scheduler for executing arbitrary tasks within a thread.
      This scheduler was originally designed to provide access to the spi/i2c busses for reading the sensors on a flight controller
      In the bus scenario
      Only one sensor can be active on the bus at one time.
      Operations consist mainly of a read or a write or come combination.
      The length of an operation is therefore quite predictable as it is dominated by the bus frequency
      and the amount of data read or written to the bus.

      The scheduler has a number of slots and a slot time.
      For example you might have 10 slots and each slot would last for 2 milliseconds.
      Each slot can have an arbitrary number of tasks in it. (The tasks in a slot are held in a linked list)
      The time taken to go round all the slots (round_robin_time) then is number_of_slots * slot_time.
      Tasks have, as one constructor argument, the update rate in milliseconds. The update rate can be very long;
      It is not confined to the round_robin_time.

      If the scheduler has more slots, then it doesnt have to wake up so often, but more slots do use more memory.
      
      Tasks can specify that they would like to repeat once or a fixed number of time or run forever.
      To keep it simple, tasks all have the same priority

      TODO: 
      load balancing or simply spreading tasks evenly around
      priority, sorting tasks to put higher priority ones first
      Optionally deleting a task once it is done(calling its dtor and freeing memory)
   */

   template <
      typename Task,
      uint32_t NSlots,
      uint32_t SlotTime_ms,
      void(*sleep_until_fun)(quan::time_<uint32_t>::ms const & )>
   struct scheduler ;


   // should be templated on callback function
   // compat with mbed Callback ?
   // e.g task<void()>
   // or derived ?
   // wont lose much

#if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
   struct task 
#else
   struct task : quan::mbed::dlist_element<task,2>
#endif  
   {
      typedef void (*task_fun)();
      task( const char * name, task_fun fun, quan::time_<uint32_t>::ms update_rate, int32_t num_repeats = -1)
      : m_name{name}, m_task_fun{fun}, m_update_rate{update_rate}, m_loopcount{0}, m_num_repeats{num_repeats}

      { assert(update_rate >= quan::time_<uint32_t>::ms{1U});}

      const char* get_name() const { return m_name;}
      int32_t get_num_repeats() const { return m_num_repeats;}
      quan::time_<uint32_t>::ms get_update_rate() const { return m_update_rate;}
      void run() { m_task_fun();}
      
      void set_task_fun(task_fun fun){ m_task_fun = fun;}
     private:
      template <
            typename Task,
            uint32_t NSlots, 
            uint32_t SlotTime_ms,
            void(*sleep_until_fun)(quan::time_<uint32_t>::ms const & )
      >
      friend struct scheduler;
      const char* const m_name;
      task_fun m_task_fun;
      quan::time_<uint32_t>::ms const m_update_rate;
      uint32_t m_loopcount;
      int32_t  m_num_repeats;
      void dec_loopcount() { if (m_loopcount > 0) { -- m_loopcount;} }
      int32_t dec_num_repeats() { 
         if (m_num_repeats > 0) { --m_num_repeats;}
         return m_num_repeats;
      } 

      uint32_t get_loopcount()const {return m_loopcount;}
      void set_loopcount(uint32_t val){m_loopcount = val;}

      void destroy () {std::cout << m_name << " destroy called\n";} // cleanup if necessary
 
      task (task const &) = delete;
      task& operator = (task const &) = delete;
   };


   inline void execute(task & t)
   {
      t.run();
   }

   template <
      typename Task
      ,uint32_t NSlots
      ,uint32_t SlotTime_ms
      ,void(*sleep_until)( quan::time_<uint32_t>::ms const & )
   >
   struct scheduler {

      static constexpr uint32_t m_num_slots = NSlots;
      static constexpr quan::time_<uint32_t>::ms m_slot_time{SlotTime_ms};

      typedef Task task;

      scheduler()
      : 
        m_elapsed{quan::time_<uint32_t>::ms{0U}}
        ,m_current_slot{0}
      {
      #if ! (defined QUAN_MBED_SCHEDULER_USE_STD_LIST)
         memset(m_slots, 0, m_num_slots * sizeof(task*));
      #endif
      }

      ~scheduler()
      {
      }

      void run()
      {
         uint32_t const old_slot = m_current_slot;
         if ( find_next_slot(m_current_slot)){
            quan::time_<uint32_t>::ms const interval = get_slot_diff(old_slot,m_current_slot) * m_slot_time;
            sleep_until(m_elapsed + interval );
            m_elapsed += interval + m_slot_time;
            process_next_task();
         }
      }

      void show_slots(std::ostream & out)const
      {
         out << "--------slot state---------------\n";

         for ( uint32_t i = 0; i < m_num_slots; ++i){
            out << "slot[" << i <<"] = ";
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
            if ( m_slots[i].empty())
   #else
            if (m_slots[i] == nullptr)
   #endif
            {
                out << "null";
            }else{
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
                for ( ev : m_slots[i])
   #else
                for ( task* ev = m_slots[i]; ev != nullptr; ev = ev-> template get_next_dlist_element<0>())
   #endif
                {
                   out << ev->get_name() << ",";
                }
               }
               out << "\n";
            }
            out << "---------------------------------\n";
      }

      /*
         put the task in the slot to give first firing at the update_rate interval from current_slot
         TODO add an offset to the start position, so that tasks are spread out
      */
      void insert_task(task* ptask, quan::time_<uint32_t>::ms const offset = quan::time_<uint32_t>::ms{0U})
      {
         assert(ptask);

         uint32_t const task_interval = (ptask->get_update_rate() + offset)/m_slot_time ;
         uint32_t const loopcount = task_interval / m_num_slots;
         auto const slot_idx = slot_incr(m_current_slot, task_interval );
        
         assert(slot_idx < m_num_slots);
         assert(slot_idx >=0);
         ptask->set_loopcount(loopcount);
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
         m_slots[slot_idx].push_front(ptask);
   #else
         quan::mbed::dlist_push_front<0>(m_slots[slot_idx],ptask);
   #endif
      }

    private:
      scheduler (scheduler const &) = delete;
      scheduler& operator = (scheduler const &) = delete;
      quan::time_<uint32_t>::ms        m_elapsed;
      uint32_t                         m_current_slot;
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
      std::list<task*>               m_slots[m_num_slots];
   #else
      task *                         m_slots[m_num_slots];
   #endif

   /*
      circular buffer increment of slot
   */
      uint32_t slot_incr(uint32_t slot_idx, uint32_t n_slots = 1)const
      {
         return (slot_idx + n_slots) % m_num_slots;
      }

      /*
         find next non-empty slot
      */
      bool find_next_slot(uint32_t & result)const
      {
          uint32_t next = m_current_slot;
          for (uint32_t i = 0; i < m_num_slots; ++i){

   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
             if (!m_slots[next].empty())
   #else
             if (m_slots[next] != nullptr)    
   #endif
             {
                 result = next;
                 return true;
             }else{
                 next = slot_incr(next);
             }
          }
          return false;
      }

      uint32_t get_slot_diff(uint32_t first, uint32_t second)const
      {
         if ( first <= second){
            return second - first;
         }else{
            return (second + m_num_slots ) - first;
         }
      }

      bool process_next_task()
      {
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
         std::list<task*> temp_list;
         std::list<task*> & task_list = m_slots[m_current_slot];
   #else
         task* temp_list = nullptr;
         task*& task_list = m_slots[m_current_slot];
   #endif

   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
        for( auto iter = task_list.begin(); iter != task_list.end();)
   #else
        for ( task* iter = task_list; iter != nullptr;)
   #endif
        {
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
            task * ptask = *iter;
   #else 
            task * ptask = iter;
   #endif
            assert(ptask);
            if ( ptask->get_loopcount() > 0U){
               ptask->dec_loopcount();
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
               ++iter;
   #else
               iter = iter-> template get_next_dlist_element<0>();
   #endif
            }else{
               execute(*ptask);
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
               iter = task_list.erase(iter);
   #else
               ptask = dlist_extract<0>(task_list,iter);     
   #endif   
               if ( ptask->dec_num_repeats() != 0U) {
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
                  temp_list.push_front(ptask);
   #else
                  quan::mbed::dlist_push_front<1>(temp_list,ptask);                   
   #endif
              }else {
                  ptask->destroy();
              }
           }      
        }
         // move the tasks on the temp_list back into the scheduler
         // in position for next firing
   #if defined QUAN_MBED_SCHEDULER_USE_STD_LIST
         for (item : temp_list)
   #else
         for ( task* item = quan::mbed::dlist_pop_front<1>(temp_list);
                  item != nullptr; 
                     item = quan::mbed::dlist_pop_front<1>(temp_list))
   #endif
         {
            
            insert_task(item);
            uint32_t const task_interval = item->get_update_rate()/m_slot_time;
            uint32_t const mod_part = task_interval % m_num_slots;
            if ( mod_part == 0){
               item->dec_loopcount();
            }
         }

         m_current_slot = slot_incr(m_current_slot); // bump the slot
         return true;

      }
   }; // ~struct

   template < typename Task,uint32_t NSlots, uint32_t SlotTime,void(*sleep_until_fun)(quan::time_<uint32_t>::ms const & )>
   constexpr quan::time_<uint32_t>::ms  scheduler<Task,NSlots,SlotTime,sleep_until_fun>::m_slot_time;
    
}}// quan::mbed

#endif // QUAN_MBED_SCHEDULER_HPP_INCLUDED

