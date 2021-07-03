#ifndef QUAN_UTILITY_REAL_TIMER_HPP_INCLUDED
#define QUAN_UTILITY_REAL_TIMER_HPP_INCLUDED

#include <quan/time.hpp>
#include <sys/times.h>

namespace quan{
   
   /*
     world as in not per process 
   */
   template <typename TimeType>
   struct real_timer{

      real_timer()
      {
         clock_gettime(CLOCK_MONOTONIC,&start_time);
      }

      TimeType operator()()const
      {
         timespec ts;
         clock_gettime(CLOCK_MONOTONIC,&ts);

         auto const s = (ts.tv_nsec <= start_time.tv_nsec)
         ?(ts.tv_sec - (start_time.tv_sec + 1))
         :(ts.tv_sec - start_time.tv_sec)
         ;

         auto const ns = (ts.tv_nsec <= start_time.tv_nsec)
         ? ((ts.tv_nsec - start_time.tv_nsec) + 1000000000 )
         : ( ts.tv_nsec - start_time.tv_nsec )
         ;
         return quan::time::ms{static_cast<double>(s) * 1000  + static_cast<double>(ns)/1000000};
      }

      private:
      timespec start_time;
   };
}

#endif // QUAN_UTILITY_REAL_TIMER_HPP_INCLUDED
