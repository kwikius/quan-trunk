#ifndef QUAN_STM32_FLASH_CONVERT_VECT3F_HPP_INCLUDED
#define QUAN_STM32_FLASH_CONVERT_VECT3F_HPP_INCLUDED

#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert.hpp>

namespace quan{ namespace stm32{ namespace flash{

   template <> struct flash_convert<quan::three_d::vect<float> >{
      typedef quan::three_d::vect<float> type;
      static bool set (const char* str,type const & value);
      static bool get (const char* str, type & value);
      static bool text_to_bytestream(
         quan::dynarray<uint8_t>& dest
         , quan::dynarray<char> const & src
         , bool (*pfn_check)(void* value)
      );
      static bool bytestream_to_text(quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src);
   };

      // requires implementation by the app
   template<> struct get_flash_typeid_impl<quan::three_d::vect<float> > 
   { static uint32_t apply();};

}}} // quan::stm32::flash

#endif // QUAN_STM32_FLASH_CONVERT_VECT3F_HPP_INCLUDED
