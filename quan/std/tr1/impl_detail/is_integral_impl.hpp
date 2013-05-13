#ifndef QUAN_STD_TR1_IMPL_DETAIL_IS_INTEGRAL_IMPL_HPP_INCLUDED
#define QUAN_STD_TR1_IMPL_DETAIL_IS_INTEGRAL_IMPL_HPP_INCLUDED

// Copyright Andrew Little 2006

/*
 Copyright (c) 2005 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/config.hpp>
#include <quan/std/tr1/remove_cv.hpp>
#include <quan/std/tr1/integral_constant.hpp>

   namespace quan { namespace impl_detail{
   
      template <typename T>
      struct is_integral_impl_ucv : std::false_type{};

      //yuch...
      template<>
      struct is_integral_impl_ucv<bool> : std::true_type{};

      template<>
      struct is_integral_impl_ucv<char> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<signed char> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<short> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<int> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<long> : std::true_type{};
         template<>
      struct is_integral_impl_ucv<unsigned char> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<unsigned short> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<unsigned int> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<unsigned long> : std::true_type{};
      template<>
      struct is_integral_impl_ucv<wchar_t> : std::true_type{};
#ifdef QUAN_HAS_LONG_LONG
      template<>
      struct is_integral_impl_ucv<long long> : std::true_type{};

      template<>
      struct is_integral_impl_ucv<unsigned long long> : std::true_type{};
#endif
      template <typename T> 
      struct is_integral_impl : is_integral_impl_ucv<
          typename std::remove_cv<T>::type
      >{};
   
   }}// quan::impl_detail

#endif

