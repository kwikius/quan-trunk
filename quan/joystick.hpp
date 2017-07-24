#ifndef QUAN_LINUX_JOYSTICK_HPP_INCLUDED
#define QUAN_LINUX_JOYSTICK_HPP_INCLUDED

#include <cstdint>
#include <cstdlib>
#include <cstdio>

#include <unistd.h>
#include <fcntl.h>
#include <linux/joystick.h>
#if ! defined QUAN_NO_EXCEPTIONS
#include <stdexcept>
#endif
#include <thread>    
#include <chrono> 
#include <atomic> 

/*
  link with pthread
*/

namespace quan{

   struct joystick{
      static constexpr uint8_t num_channels = 8;
      
      joystick(const char* device_name) // e.g device_name = "/dev/input/js0"
      : m_fd{open(device_name, O_RDONLY | O_NONBLOCK)}, m_thread_running{false}, m_want_thread_quit{true}
      {
#if ! defined QUAN_NO_EXCEPTIONS
         if (m_fd < 0){
            throw std::runtime_error("failed to open joystick device");
           return;
         }
#else
        if ( m_fd < 0){
           perror("quan::joystick : ");
           return;
        }
#endif
         for (auto & v : m_channel){v = 0;}
         m_thread_running = true;
         m_want_thread_quit = false;
         m_update_thread = std::thread{std::bind(&joystick::update,this)};
      }
      ~joystick(){ end_thread(); if (m_fd >= 0) { close(m_fd);} }

      bool is_running() const { return m_thread_running == true;}

      int32_t get_channel(uint8_t channel)const
      {
         if ( channel < num_channels){
            return m_channel[channel];
         }else{
            return 0;
         }
      }

      void end_thread()
      {
         m_want_thread_quit = true;
         while (m_thread_running){;}
         m_update_thread.join();
      }

   private:
      void update()
      {
         for(;;){
            while (read (m_fd, &m_event, sizeof(m_event)) == sizeof(m_event)) {
               if ((m_event.type & JS_EVENT_AXIS)==JS_EVENT_AXIS){
                  set_channel();
               }
            }
            if( (errno != EAGAIN) || m_want_thread_quit) {
               if ( errno != EAGAIN){
                  printf("joystick device read failed\n");
               }
               m_thread_running = false;
               return;
            }
            std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds{10});
         }
      }
     
      void set_channel()
      {
         if ( m_event.number < num_channels){
            m_channel[m_event.number] = m_event.value;
         }
      }
      std::atomic<int32_t>   m_channel[num_channels];
      std::atomic<int>       m_fd;
      std::atomic<bool>      m_thread_running;
      std::atomic<bool>      m_want_thread_quit;
      js_event               m_event;
      std::thread            m_update_thread;
      joystick (const joystick &)= delete;
      joystick & operator = (const joystick &)= delete;
   };

} // quan

#endif // QUAN_LINUX_JOYSTICK_HPP_INCLUDED
