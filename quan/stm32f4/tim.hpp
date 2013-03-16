#ifndef QUAN_STM32F4_TIM_HPP_INCLUDED
#define QUAN_STM32F4_TIM_HPP_INCLUDED
/*
 Copyright (c) 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/stm32f4/tim/module.hpp>
#include <quan/stm32f4/tim_typedefs.hpp>
#include <quan/stm32f4/tim/detail/module_enable_disable.hpp>

namespace quan{namespace stm32f4{

    template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Tim,T> >::type 
     module_enable()
     {    
            quan::stm32f4::tim::detail::module_enable<T>{}();
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Tim,T> >::type 
     module_disable()
     {    
            quan::stm32f4::tim::detail::module_disable<T>{}();
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Tim,T> >::type 
     module_reset()
     {    
            quan::stm32f4::tim::detail::module_reset<T>{}();
     }

    template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Tim,T> >::type 
     enable()
     {    
            T::get()->cr1.template bb_setbit<0>(); //(CEN)
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Tim,T> >::type 
     disable()
     {    
            T::get()->cr1.template bb_clearbit<0>(); //(CEN)
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Tim,T>,bool >::type 
     update_interrupt()
     {
         return tim3::get()->sr.bb_getbit<0>();
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Tim,T> >::type 
     clear_update_interrupt()
     {
         tim3::get()->sr.bb_clearbit<0>();
     }

     // add enable disable tim
}}

#endif // QUAN_STM32F4_TIM_HPP_INCLUDED
