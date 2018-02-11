#ifndef QUAN_LIMITS_HPP_INCLUDED
#define QUAN_LIMITS_HPP_INCLUDED

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
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan/config.hpp>
#include <quan/meta/arithmetic_promote.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#endif

#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/strip_cr.hpp>
#include <quan/meta/integer_min.hpp>
#include <quan/meta/integer_max.hpp>
#include <quan/meta/float_min.hpp>
#include <quan/meta/float_max.hpp>

namespace quan{

   namespace impl_detail{
        namespace detail{

				template <typename T>
				struct min_order_impl;

				template <>
				struct min_order_impl<signed char> : std::integral_constant<int,-1>{};
			  
				template <>
				struct min_order_impl<short> :std::integral_constant<int,-2>{};

				template <>
				struct min_order_impl<int> : std::integral_constant<
						int,-2 - (sizeof(int) > sizeof(short)?1:0)
				>{};

				template <>
				struct min_order_impl<long> : std::integral_constant<int,min_order_impl<int>::value - (sizeof(long) > sizeof(int)?1:0)>{};
		#if (defined QUAN_HAS_LONG_LONG)   
				template <>
				struct min_order_impl<long long> : std::integral_constant<int,min_order_impl<long>::value-1>{};

				template <>
				struct min_order_impl<float> : std::integral_constant<int,min_order_impl<long long>::value-1>{};
		#else
				template <>
				struct min_order_impl<float> : std::integral_constant<int,min_order_impl<long>::value-1>{};
		#endif
				template <>
				struct min_order_impl<double> : std::integral_constant<int,min_order_impl<float>::value-1>{};

				template <>
				struct min_order_impl<long double> : std::integral_constant<
					int,
					min_order_impl<double>::value- (sizeof(long double) > sizeof(double)?1:0)
				>{};

				template <>
				struct min_order_impl<unsigned char>: std::integral_constant<int,0>{};
				template <>
				struct min_order_impl<unsigned short>: std::integral_constant<int,0>{};
				template <>
				struct min_order_impl<unsigned int>: std::integral_constant<int,0>{};
				template <>
				struct min_order_impl<unsigned long>: std::integral_constant<int,0>{};
		#if (defined QUAN_HAS_LONG_LONG) 
				template <>
				struct min_order_impl<unsigned long long>: std::integral_constant<int,0>{};
		#endif

				template <typename T>
				struct max_order_impl;

				template <>
				struct max_order_impl<signed char> : std::integral_constant<int,1>{};

				template <>
				struct max_order_impl<unsigned char>: std::integral_constant<int,2>{};
			  
				template <>
				struct max_order_impl<short> :std::integral_constant<int,3>{};

				template <>
				struct max_order_impl<unsigned short>: std::integral_constant<int,4>{};
				template <>
				struct max_order_impl<int> : std::integral_constant<int,4 + (sizeof(int) > sizeof(short)?1:0)>{};

				template <>
				struct max_order_impl<unsigned int>: std::integral_constant<int,max_order_impl<int>::value +1>{};
				template <>
				struct max_order_impl<long> : std::integral_constant<int,max_order_impl<int>::value + (sizeof(long) > sizeof(int)?1:0)>{};
				
				template <>
				struct max_order_impl<unsigned long>: std::integral_constant<int,max_order_impl<long>::value +1>{};
		#if (defined QUAN_HAS_LONG_LONG) 
				template <>
				struct max_order_impl<long long> : std::integral_constant<int,max_order_impl<unsigned long>::value+1>{};

				template <>
				struct max_order_impl<unsigned long long>: std::integral_constant<int,max_order_impl<long long>::value +1>{};
				template <>
				struct max_order_impl<float> : std::integral_constant<int,max_order_impl<unsigned long long>::value+1>{};
		#else
				template <>
				struct max_order_impl<float> : std::integral_constant<int,max_order_impl<unsigned long>::value+1>{};
		#endif
				template <>
				struct max_order_impl<double> : std::integral_constant<int,max_order_impl<float>::value+1>{};

				template <>
				struct max_order_impl<long double> : std::integral_constant<
					int,
					max_order_impl<double>::value + (sizeof(long double) > sizeof(double)?1:0)
				>{};
      }//detail

       template<typename T> struct min_order
		 : quan::impl_detail::detail::min_order_impl<typename quan::meta::strip_crv<T>::type>{};

      template<typename T> struct max_order
		 : quan::impl_detail::detail::max_order_impl<typename quan::meta::strip_crv<T>::type>{};

      template <typename Target , typename Source>
      struct is_narrowing_conversion : quan::meta::bool_< 
            (((min_order<Target>::value) > (min_order<Source>::value)) ||
            ((max_order<Target>::value) < (max_order<Source>::value)))
      >{};
      
      template <typename T, typename Where = void> struct lowest;

      template <typename T>
      struct lowest<T, typename quan::where_<std::is_integral<T> >::type>
      {
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         T operator()() const
         {
             return quan::meta::integer_min<T>::value;
         }
      };
      template <typename T>
      struct lowest<T, typename quan::where_<std::is_floating_point<T> >::type>
      {
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         T operator()() const
         {
            return quan::meta::float_min<T>()();
         }
      };

       template <typename T, typename Where = void> struct highest;
       template <typename T>
      struct highest<T, typename quan::where_<std::is_integral<T> >::type>
      {
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         T operator()() const
         {
             return quan::meta::integer_max<T>::value;
         }
      };
      template <typename T>
      struct highest<T, typename quan::where_<std::is_floating_point<T> >::type>
      {
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         T operator()() const
         {
            return quan::meta::float_max<T>()();
         }
      };
}//impl_detail

}

#endif

