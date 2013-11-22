#ifndef QUAN_STM32_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
#define QUAN_STM32_GET_ALTERNATE_FUNCTION_HPP_INCLUDED

#include <quan/undefined.hpp>

namespace quan{ namespace stm32{ 

   template <typename Pin, typename Module, typename Function, typename Where = void>
   struct get_alternate_function{
         typedef quan::undefined type;
   };

}}

#endif //QUAN_STM32_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
