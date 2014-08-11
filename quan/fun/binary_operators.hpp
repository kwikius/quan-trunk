#ifndef QUAN_FUN_BINARY_OPERATORS_HPP_INCLUDED
#define QUAN_FUN_BINARY_OPERATORS_HPP_INCLUDED
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
#include <quan/fun/fun_concepts.hpp>
#include <quan/fun/access_modifiers.hpp>
#include <type_traits>
#include <quan/meta/int32.hpp>

namespace quan{ namespace fun{

   using quan::operator_plus;
   using quan::operator_minus;
   using quan::operator_times;
   using quan::operator_divides;

   using quan::operator_equals;
   using quan::operator_plus_equals;
   using quan::operator_minus_equals;
   using quan::operator_times_equals;
   using quan::operator_divide_equals;

   template <>
   struct is_fun<operator_plus> : std::true_type{};
   template <>
   struct num_args<operator_plus> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_plus,1> : as_const_ref{};
   template<>
   struct arg_mod<operator_plus,2> : as_const_ref{};
   template <>
   struct returns_result<operator_plus> : std::true_type{};
   template<>
   struct result_mod<operator_plus> : as_value{};
   
   
   template <>
   struct is_fun<operator_minus> : std::true_type{};
   template <>
   struct num_args<operator_minus> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_minus,1> : as_const_ref{};
   template<>
   struct arg_mod<operator_minus,2> : as_const_ref{};
   template <>
   struct returns_result<operator_minus> : std::true_type{};
   template<>
   struct result_mod<operator_minus> : as_value{};
  
   template <>
   struct is_fun<operator_times> : std::true_type{};
   template <>
   struct num_args<operator_times> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_times,1> : as_const_ref{};
   template<>
   struct arg_mod<operator_times,2> : as_const_ref{};
   template<>
   struct result_mod<operator_times> : as_value{};
   template <>
   struct returns_result<operator_times> : std::true_type{};

   template <>
   struct is_fun<operator_divides> : std::true_type{};
   template <>
   struct num_args<operator_divides> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_divides,1> : as_const_ref{};
   template<>
   struct arg_mod<operator_divides,2> : as_const_ref{};
   template<>
   struct result_mod<operator_divides> : as_value{};
   template <>
   struct returns_result<operator_divides> : std::true_type{};

   template <>
   struct is_fun<operator_equals> : std::true_type{};
   template <>
   struct num_args<operator_equals> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_equals,1> : as_ref{};
   template<>
   struct arg_mod<operator_equals,2> : as_const_ref{};
   template<>
   struct result_mod<operator_equals> : as_ref{};
   template <>
   struct returns_result<operator_equals> : std::true_type{};

   template <>
   struct is_fun<operator_plus_equals> : std::true_type{};
   template <>
   struct num_args<operator_plus_equals> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_plus_equals,1> : as_ref{};
   template<>
   struct arg_mod<operator_plus_equals,2> : as_const_ref{};
   template<>
   struct result_mod<operator_plus_equals> : as_ref{};
   template <>
   struct returns_result<operator_plus_equals> : std::true_type{};

   template <>
   struct is_fun<operator_minus_equals> : std::true_type{};
   template <>
   struct num_args<operator_minus_equals> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_minus_equals,1> : as_ref{};
   template<>
   struct arg_mod<operator_minus_equals,2> : as_const_ref{};
   template<>
   struct result_mod<operator_minus_equals> : as_ref{};
   template <>
   struct returns_result<operator_minus_equals> : std::true_type{};

   template <>
   struct is_fun<operator_times_equals> : std::true_type{};
   template <>
   struct num_args<operator_times_equals> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_times_equals,1> : as_ref{};
   template<>
   struct arg_mod<operator_times_equals,2> : as_const_ref{};
   template<>
   struct result_mod<operator_times_equals> : as_ref{};
   template <>
   struct returns_result<operator_times_equals> : std::true_type{};

   template <>
   struct is_fun<operator_divide_equals> : std::true_type{};
   template <>
   struct num_args<operator_divide_equals> : quan::meta::int32<2>{};
   template<>
   struct arg_mod<operator_divide_equals,1> : as_ref{};
   template<>
   struct arg_mod<operator_divide_equals,2> : as_const_ref{};
   template<>
   struct result_mod<operator_divide_equals> : as_ref{};
   template <>
   struct returns_result<operator_divide_equals> : std::true_type{};

}}//quan

#endif
