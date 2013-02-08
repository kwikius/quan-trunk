#ifndef QUAN_STM32F4_TIM_HPP_INCLUDED
#define QUAN_STM32F4_TIM_HPP_INCLUDED

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

     // add enable disable tim
}}

#endif // QUAN_STM32F4_TIM_HPP_INCLUDED
