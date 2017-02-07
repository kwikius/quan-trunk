#ifndef QUAN_IRQ_ATOMIC_BUFFER_HPP_INCLUDED
#define QUAN_IRQ_ATOMIC_BUFFER_HPP_INCLUDED

/*
  For objects larger than a register
  write from non irq context
  but want consistent read in irq
  so use a 2 object buffer
  to write ex irq write the not in use buffer then switch buffers atonically
  
*/
namespace quan{

   template <typename T> 
   struct irq_atomic_buffer
   {
      irq_atomic_buffer(T const & a, T const & b) 
      : u{a,b}, m_index{0}{}

      T const & in_irq_get() const 
      {
         return u.m_arr[m_index];
      }

      void ex_irq_set(T const & in)
      {
         u.m_arr[m_index ^ 1U] = in;
         m_index ^= 1U;
      }

   private:
         union u_t{
            u_t(T const & a, T const & b): n{a,b}{}
            struct n_t{
               n_t(T const & a, T const & b):m_first{a},m_second{b}{}
               T m_first;
               T m_second;
            } n;
            T m_arr[2];
         }u ; 
         uint8_t m_index;
   };

}

#endif

