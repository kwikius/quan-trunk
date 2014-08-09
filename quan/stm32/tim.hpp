#ifndef QUAN_STM32_TIM_HPP_INCLUDED
#define QUAN_STM32_TIM_HPP_INCLUDED
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
#include <quan/stm32/config.hpp>
#include <quan/stm32/tim/module.hpp>
#include <quan/stm32/tim/typedefs.hpp>
#include <quan/stm32/tim/detail/module_enable_disable.hpp>

namespace quan{namespace stm32{

    template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32::Tim,T> >::type 
     module_enable()
     {    
            quan::stm32::tim::detail::module_enable<T>{}();
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32::Tim,T> >::type 
     module_disable()
     {    
            quan::stm32::tim::detail::module_disable<T>{}();
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32::Tim,T> >::type 
     module_reset()
     {    
            quan::stm32::tim::detail::module_reset<T>{}();
     }

    template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32::Tim,T> >::type 
     enable()
     {    
#if QUAN_STM32_HAS_BITBANDING
            T::get()->cr1.template bb_setbit<0>(); //(CEN)
#else
            T::get()->cr1.template setbit<0>();
#endif
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32::Tim,T> >::type 
     disable()
     {   
#if QUAN_STM32_HAS_BITBANDING 
            T::get()->cr1.template bb_clearbit<0>(); //(CEN)
#else
           T::get()->cr1.template clearbit<0>(); //(CEN)
#endif
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32::Tim,T>,bool >::type 
     update_interrupt()
     {
#if QUAN_STM32_HAS_BITBANDING 
         return T::get()->sr. template bb_getbit<0>();
#else
         return T::get()->sr. template getbit<0>();
#endif
     }

     template<typename T> inline
     typename quan::where_<quan::is_model_of< quan::stm32::Tim,T> >::type 
     clear_update_interrupt()
     {
#if QUAN_STM32_HAS_BITBANDING 
         T::get()->sr. template bb_clearbit<0>();
#else
         T::get()->sr. template clearbit<0>();
#endif
     }

     // add enable disable tim
}}

#endif // QUAN_STM32_TIM_HPP_INCLUDED
