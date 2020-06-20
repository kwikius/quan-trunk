#ifndef QUAN_ASM_EXTENDED_REG_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_REG_HPP_INCLUDED
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

#include <quan/asm/get_bit.hpp>
#include <quan/meta/numbits.hpp>
#include <quan/meta/max.hpp>
#include <type_traits>

namespace quan{ namespace asm_{

   /*
      T is always unsigned
      sign of value is represented in sign bit
   */
   template <typename T>
   struct extended_reg{

      static_assert(std::is_unsigned<T>::value,"");
      constexpr extended_reg() : hi{0},lo{0},sign{1}{}
      constexpr extended_reg(T const & hiIn, T const & loIn,int signIn = 1)
      : hi{hiIn},lo{loIn},sign{(loIn || hiIn)?signIn:1}{}

      constexpr extended_reg(extended_reg const &) = default;
      constexpr extended_reg(extended_reg &&) = default;

      constexpr extended_reg & operator = (extended_reg const &) = default;
      constexpr extended_reg & operator = (extended_reg &&) = default;

      enum sign_enum{ undefined =0, positive = 1,negative = -1};
      T hi;
      T lo; 
      int sign; // 1 == +, -1 == -  n.b 0 is always positive

      bool shift_left()
      {
         int constexpr nT = quan::meta::numbits<T>::value;
         bool const res = quan::asm_::get_bit<nT-1>(hi);
         hi <<= 1;
         if ( quan::asm_::get_bit<nT-1>(lo)){
            hi |= 1;
         }
         lo <<= 1;
         return res;
      }

      constexpr bool get_bit( unsigned i) const
      {
         auto constexpr nT = quan::meta::numbits<T>::value;

         return ( i < nT)
            ? quan::asm_::get_bit(lo,i)
            : ( (i < (2U * nT))
                 ? quan::asm_::get_bit(hi,i - nT)
                 : false
               )
          ;
      }

      void set_bit( unsigned i)
      {
         auto constexpr nT = quan::meta::numbits<T>::value;
         if ( i < nT){
            lo |= (1U << i);
         }else{
            if ( i < 2U * nT){
               hi |= ( 1U << ( i - nT));
            }
         }
      }
      
      int compare(T const & v) const
      {
         // sign of v is always positive
         if ( sign == 1){
            if ( hi == 0){
               return (lo > v)
                  ? 1 
                  : ((lo < v) ? -1 : 0);
            }else{
               return 1;
            }
         }else{
            return -1;
         }
      }

      int compare(extended_reg<T> const & v) const
      {
         // TODO sign
         if ( hi == v.hi){
            return (lo > v.lo)
               ? 1 
               : ((lo < v.lo) ? -1 : 0);
         }else{
            return (hi > v.hi)? 1 : -1; 
         }
      }

      extended_reg & operator -= (T const & v)
      {
         // TODO sign
         if( *this >= v){
             if ( v <= lo){
               lo -= v;
             }else{
               lo = quan::meta::max_<T>::value - v + (lo + 1);
               hi -= 1;
             }
          }else{
              assert(false && "todo");
          }
          return *this;
      }

      extended_reg & operator -= (extended_reg<T> const & v)
      {
          // TODO sign
          if( *this >= v){
             if( v.lo <= lo){
                lo -= v.lo;
                hi -= v.hi;
             }else{
                lo = quan::meta::max_<T>::value - v.lo + (lo + 1);
                hi -= (v.hi + 1);
             }
          }else{
              assert(false && "todo");
          }
          return *this;
      }

      bool operator < (T const & v)const
      {
         return compare(v) < 0;
      }

      bool operator < (extended_reg<T> const & v)const
      {
         return compare(v) < 0;
      }

      bool operator <= (T const & v)const
      {
         return compare(v) <= 0;
      }

      bool operator <= (extended_reg<T> const & v)const
      {
         return compare(v) <= 0;
      }

      bool operator  == (T const & v)const
      {
         return compare(v) == 0;
      }

      bool operator == (extended_reg<T> const & v)const
      {
         return compare(v) == 0;
      }

      bool operator != (T const & v)const
      {
         return compare(v) != 0;
      }

      bool operator != (extended_reg<T> const & v)const
      {
         return compare(v) != 0;
      }

      bool operator >= (T const & v)const
      {
         return compare(v) >= 0;
      }

      bool operator >= (extended_reg<T> const & v)const
      {
         return compare(v) >= 0;
      }

      bool operator > (T const & v)const
      {
         return compare(v) > 0;
      }

      bool operator > (extended_reg<T> const & v)const
      {
         return compare(v) > 0;
      }
   };
}}//quan::asm_

#endif
