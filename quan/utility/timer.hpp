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
    Nominally Correct for one overflow period of system timer.
    ( using difftime )
   *** now templated on required time units ***
    
*/

#include <quan/time.hpp>
#include <quan/meta/eval_rational.hpp>
#include <quan/static_assert.hpp>
#include <type_traits>
#include <ctime>

namespace quan{
 
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

}//quan

#endif
