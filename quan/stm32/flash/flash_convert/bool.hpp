#ifndef QUAN_STM32_FLASH_CONVERT_BOOL_HPP_INCLUDED
#define QUAN_STM32_FLASH_CONVERT_BOOL_HPP_INCLUDED

#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert.hpp>

namespace quan{ namespace stm32{ namespace flash{

   template <typename T>
   struct flash_convert;

   template <> struct flash_convert<bool>{
      typedef bool type;
      static bool set (const char* str, type const & value);
      static bool get (const char* str, type& value);
      static bool text_to_bytestream(
         quan::dynarray<uint8_t>& dest
         , quan::dynarray<char> const & src
         , bool (*pfn_check)(void* value)
      );
      static bool bytestream_to_text(quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src);
   };

   // requires implementation by the app
   template<> struct get_flash_typeid_impl<bool> 
   { static uint32_t apply();};

}}}

#endif // QUAN_STM32_FLASH_CONVERT_BOOL_HPP_INCLUDED
