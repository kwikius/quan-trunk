#ifndef QUAN_META_GET_HIGHEST_SET_BIT_HPP_INCLUDED
#define QUAN_META_GET_HIGHEST_SET_BIT_HPP_INCLUDED

#include <stdint.h>

/*
 returns bit pos of lowest set bit or -1 if input is 0;
*/
namespace quan{
   namespace meta{
      namespace detail{
          template<uint32_t Val,uint32_t Pos,bool istrue = ((Val & ( 0x80000000  >> Pos)) != 0 )>
          struct get_highest_set_bit_impl;

           template<uint32_t Val,uint32_t Pos>
           struct get_highest_set_bit_impl<Val,Pos,true>{
              static const int value = 31-Pos;
           };

           template<uint32_t Val,uint32_t Pos>
           struct get_highest_set_bit_impl<Val,Pos,false>{
              static const int value = get_highest_set_bit_impl<Val,(Pos+1)>::value;
           }

           template<uint32_t Pos>
           struct get_highest_set_bit_impl<0,Pos,false>{
              static const int value = -1;
           };
      }//detail

    template< Val> struct get_highest_set_bit{
      static const int value = quan::meta::detail::get_highest_set_bit_impl<Val,0>::value;
    };

}}

#endif // QUAN_META_GET_HIGHEST_SET_BIT_HPP_INCLUDED
