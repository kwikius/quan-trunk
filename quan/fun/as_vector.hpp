#ifndef QUAN_FUN_AS_VECTOR_HPP_INCLUDED
#define QUAN_FUN_AS_VECTOR_HPP_INCLUDED
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

#include <quan/fun/size_seq.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/same_size_seq.hpp>
#include <quan/meta/bool.hpp>
#include <quan/fun/vector3_fwd.hpp>
#include <quan/fun/vector4_fwd.hpp>
#include <quan/fun/vector7_fwd.hpp>
#include <quan/fun/vector9_fwd.hpp>
#include <quan/fun/vector16_fwd.hpp>

namespace quan{namespace fun{

 template <
      typename  Seq,
      typename F = quan::fun::as_value, 
      int Size = size_seq<Seq>::value
   >
   struct as_vector;

   template <typename Seq, typename F>
   struct as_vector<Seq,F,3>
   {
      static_assert(is_fun_sequence<Seq>::value ==true ,"error");
      static_assert(quan::meta::bool_<(size_seq<Seq>::value ==3)>::value ==true ,"error");
      static_assert(size_seq<Seq>::value ==3,"error");
      typedef quan::fun::vector3<
         typename at_seq<0,Seq>::type,
         typename at_seq<1,Seq>::type,
         typename at_seq<2,Seq>::type,
         F
      > type;
   };
   
   template <typename Seq, typename F>
   struct as_vector<Seq,F,4>
   {
     static_assert(is_fun_sequence<Seq>::value ==true ,"error");
      static_assert(quan::meta::bool_<(size_seq<Seq>::value ==4)>::value ==true ,"error");
      
      typedef quan::fun::vector4<
         typename at_seq<0,Seq>::type,
         typename at_seq<1,Seq>::type,
         typename at_seq<2,Seq>::type,
         typename at_seq<3,Seq>::type,
         F
      > type;
   };

   template <typename Seq, typename F>
   struct as_vector<Seq,F,7>
   {
      static_assert(is_fun_sequence<Seq>::value ==true ,"error");
      static_assert(quan::meta::bool_<(size_seq<Seq>::value ==7)>::value ==true ,"error");
      
      typedef quan::fun::vector7<
         typename at_seq<0,Seq>::type,
         typename at_seq<1,Seq>::type,
         typename at_seq<2,Seq>::type,
         typename at_seq<3,Seq>::type,
         typename at_seq<4,Seq>::type,
         typename at_seq<5,Seq>::type,
         typename at_seq<6,Seq>::type,
         F
      > type;
   };

   template <typename Seq, typename F>
   struct as_vector<Seq,F,9>
   {
      static_assert(is_fun_sequence<Seq>::value ==true ,"error");
      static_assert(quan::meta::bool_<(size_seq<Seq>::value ==9)>::value ==true ,"error");
      
      typedef quan::fun::vector9<
         typename at_seq<0,Seq>::type,
         typename at_seq<1,Seq>::type,
         typename at_seq<2,Seq>::type,
         typename at_seq<3,Seq>::type,
         typename at_seq<4,Seq>::type,
         typename at_seq<5,Seq>::type,
         typename at_seq<6,Seq>::type,
         typename at_seq<7,Seq>::type,
         typename at_seq<8,Seq>::type,
         F
      > type;
   };

   template <typename Seq, typename F>
   struct as_vector<Seq,F,16>
   {
      static_assert(is_fun_sequence<Seq>::value ==true ,"error");
      static_assert(quan::meta::bool_<(size_seq<Seq>::value ==16)>::value ==true ,"error");
      
      typedef quan::fun::vector16<
         typename at_seq<0,Seq>::type,
         typename at_seq<1,Seq>::type,
         typename at_seq<2,Seq>::type,
         typename at_seq<3,Seq>::type,
         typename at_seq<4,Seq>::type,
         typename at_seq<5,Seq>::type,
         typename at_seq<6,Seq>::type,
         typename at_seq<7,Seq>::type,
         typename at_seq<8,Seq>::type,
         typename at_seq<9,Seq>::type,
         typename at_seq<10,Seq>::type,
         typename at_seq<11,Seq>::type,
         typename at_seq<12,Seq>::type,
         typename at_seq<13,Seq>::type,
         typename at_seq<14,Seq>::type,
         typename at_seq<15,Seq>::type,
         F
      > type;
   };


}}//quan::fun

#endif
