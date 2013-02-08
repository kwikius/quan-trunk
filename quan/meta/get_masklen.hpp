#ifndef QUAN_META_GET_MASKLEN_HPP_INCLUDED
#define QUAN_META_GET_MASKLEN_HPP_INCLUDED

#include <stdint.h>
#include <quan/meta/get_lowest_set_bit.hpp>
#include <quan/meta/get_highest_set_bit.hpp>

/*
 returns bit pos of lowest set bit or -1 if input is 0;
*/
namespace quan{
   namespace meta{
     
    template<uin32_t Val> struct get_masklen{
      static const int value = (quan::meta::get_highest_set_bit<Val>::value - quan::meta::get_lowest_set_bit<Val>::value)+1;
    };

    template<> struct get_masklen<0>{
      static const int value =0;
    };

}}

#endif // QUAN_META_GET_HIGHEST_SET_BIT_HPP_INCLUDED
