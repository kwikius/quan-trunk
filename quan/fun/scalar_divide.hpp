#ifndef QUAN_FUN_SCALAR_DIVIDE_HPP_INCLUDED
#define QUAN_FUN_SCALAR_DIVIDE_HPP_INCLUDED
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

#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/partial_binary.hpp>
#include <quan/fun/make_fun_seq1.hpp>
#include <quan/fun/fun_seq1.hpp>
#include <quan/meta/is_scalar.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>

namespace quan{ namespace meta{

   /*template <typename TL, typename SeqR>
   struct binary_op<
      TL,
      quan::meta::divides,
      SeqR,      
      typename quan::where_<
         quan::meta::and_<
            quan::meta::is_scalar<TL>,
            quan::fun::is_fun_sequence<SeqR>
         >
      >::type
   >{
      
      typedef quan::fun::binary_op<
         TL,
         quan::operator_divides,
         quan::fun::_
      > left_part;

      typedef typename quan::fun::make_fun_seq1<left_part,SeqR>::type type;
   };*/
   
   namespace impl{
      template <typename SeqL, typename TR>
      struct binary_op_impl<
         SeqL,
         quan::meta::divides,
         TR,      
         typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_sequence<SeqL>,
               quan::meta::is_scalar<TR>
            >
         >::type
      >{
         typedef quan::fun::binary_op<
            quan::fun::_,
            quan::operator_divides,
            TR
         > right_part;

         typedef typename quan::fun::make_fun_seq1<right_part,SeqL>::type type;
      };
   }
}}

namespace quan { namespace fun{

   //template <typename TL, typename SeqR>
   //typename quan::where_<
   //   quan::meta::and_<
   //      quan::meta::is_scalar<TL>,
   //      quan::fun::is_fun_sequence<SeqR>
   //   >,
   //   typename quan::meta::binary_op<
   //      TL,
   //      quan::meta::divides,
   //      SeqR
   //   >::type
   //>::type
   //operator * (TL const & lhs, SeqR const & rhs)
   //{
   //   typedef quan::fun::binary_op<
   //      TL,
   //      quan::operator_divides,
   //      quan::fun::_
   //   > left_part;
   //  // left_part lhs_f(lhs);
   //   
   //   typedef quan::fun::fun_seq1<left_part,SeqR> func;
   //  // func f(lhs_f,rhs);
   //   
   //   typedef typename quan::fun::make_fun_seq1<left_part,SeqR>::type result_type;
   //  // return result_type(f);
   //   return result_type(func(left_part(lhs),rhs));
   //}
   
   template <typename SeqL, typename TR>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::fun::is_fun_sequence<SeqL>,
         quan::meta::is_scalar<TR>
      >,
      typename quan::meta::binary_op<
         SeqL,
         quan::meta::divides,
         TR
      >::type
   >::type
   operator / (SeqL & lhs, TR const & rhs)
   {
      typedef quan::fun::binary_op<
         quan::fun::_,
         quan::operator_divides,
         TR
      > right_part;
     // right_part rhs_f(rhs);
      
      typedef quan::fun::fun_seq1<right_part,SeqL> func;
     // func f(rhs_f,lhs);
      
      typedef typename quan::fun::make_fun_seq1<right_part,SeqL>::type result_type;
     // return result_type(f);
     return result_type(func(right_part(rhs),lhs));
   }
   
}}

#endif
