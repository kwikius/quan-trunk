#ifndef QUAN_FUN_STATIC_MONOID_HPP_INCLUDED
#define QUAN_FUN_STATIC_MONOID_HPP_INCLUDED
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

#include <quan/meta/rational.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fusion/static_value/static_value.hpp>

namespace quan{ namespace fun{

      template <typename F, typename T, typename Enable = void>
      struct static_monoid;

//plus
      template <typename T>
      struct static_monoid<
         quan::operator_plus,T,
         typename quan::where_<
            quan::meta::is_valid_binary_op<T,quan::meta::plus,T>
         >::type
      > : quan::fusion::static_value<
         typename quan::fusion::to_runtime::template result<T>::type,
         quan::meta::rational<0>
      > {};

      template <typename T>
      struct static_monoid<
         quan::operator_minus,T,
         typename quan::where_<
            quan::meta::is_valid_binary_op<T,quan::meta::minus,T>
         >::type
      > : quan::fusion::static_value<
         typename quan::fusion::to_runtime::template result<T>::type,
         quan::meta::rational<0>
      > {};

      template <>
      struct static_monoid<
         quan::operator_logical_or,bool
      > : quan::fusion::static_bool<false>{};

      template <bool B>
      struct static_monoid<
         quan::operator_logical_or,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<false> {};

      template <>
      struct static_monoid<
         quan::operator_bit_or,bool
      > : quan::fusion::static_bool<false>{};

      template <bool B>
      struct static_monoid<
         quan::operator_bit_or,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<false> {};

      template <typename T>
      struct static_monoid<
         quan::operator_times,T,
         typename quan::where_<
            quan::meta::is_valid_binary_op<T,quan::meta::times,int>
         >::type
      > : quan::fusion::static_value<int,quan::meta::rational<1> >{};

      template <>
      struct static_monoid<
         quan::operator_logical_and,bool
      > : quan::fusion::static_bool<true>{};

      template <bool B>
      struct static_monoid<
         quan::operator_logical_and,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<true> {};

      template <>
      struct static_monoid<
         quan::operator_bit_and,bool
      > : quan::fusion::static_bool<true>{};

      template <bool B>
      struct static_monoid<
         quan::operator_bit_and,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<true> {};
}}

#endif
