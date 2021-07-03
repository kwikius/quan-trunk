#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef QUAN_TIMER_HPP_INCLUDED
#define QUAN_TIMER_HPP_INCLUDED



/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    construction starts timing
    restart resets and then continues timing
    stop stops or holds onto finish time
    operator ()() 
    gives either duration to last stop(0 if stopped
    or duration from init or start() if running;

   *** now templated on required time units ***
    
*/

#include <quan/time.hpp>
#if defined (__cpp_lib_chrono)
#define QUAN_USE_CHRONO_TIMER
#endif
#if defined (QUAN_USE_CHRONO_TIMER)
   #include <quan/conversion/chrono.hpp>
#else
   #include <quan/meta/eval_rational.hpp>
   #include <quan/static_assert.hpp>
   #include <type_traits>
   #include <ctime>
#endif

namespace quan{

#if defined (QUAN_USE_CHRONO_TIMER)

   template <typename TimeType = quan::time::ms>
   struct timer{
    static_assert(std::is_convertible<TimeType,quan::time::ms>::value, "TimeType must be a quan::time type");
      timer()
      :start_time{std::chrono::system_clock::now()}
      ,stop_time{std::chrono::system_clock::now()}
      ,running {true}
      {}

      TimeType operator()()const
      {
         return quan::from_chrono(std::chrono::system_clock::now() - start_time);
      }

      void restart() 
      {
         running = true;
         start_time = std::chrono::system_clock::now();
      }

      void stop() 
      {
         if (running){
            stop_time = std::chrono::system_clock::now();
            running = false;
         }
      }

      bool is_running() const {return running;}
      bool is_stopped() const {return !running;}
   private:
      std::chrono::system_clock::time_point start_time, stop_time;
      bool running;
   };

#else
    // old v using std::clock
    template <typename TimeType = quan::time::ms>
    class timer{
        
    static_assert(std::is_convertible<TimeType,quan::time::ms>::value, "TimeType must be a quan::time type");

    public:
        timer(): running(true)
        {
            start_time = std::clock();
        }

        void restart() 
        {
            running = true;
            start_time = std::clock();
        }

        void stop() 
        {
            if (running){
                stop_time = std::clock();
                running = false;
            }
        }
        
        TimeType operator ()()const
        {
            std::clock_t const wanted = running ? std::clock() : stop_time;

            typedef typename quan::meta::rational<
                1000,CLOCKS_PER_SEC
            >::type divider;
   
            quan::meta::eval_rational<divider> eval;
            
            return typename quan::time_<
                typename TimeType::value_type
            >::ms( 
                difftime(wanted , start_time) 
            ) * eval();
        }
        bool is_running() const {return running;}
        bool is_stopped() const {return !running;}
    private:
        bool running;
        std::clock_t start_time,stop_time;
    };
#endif

}//quan

#endif // QUAN_TIMER_HPP_INCLUDED
