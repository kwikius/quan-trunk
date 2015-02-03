
#ifndef QUAN_DETAIL_LL_BIGINT_HPP_INCLUDED
#define QUAN_DETAIL_LL_BIGINT_HPP_INCLUDED
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

#include <quan/config.hpp>

#include <string>
#include <vector>

#include <type_traits>
#include <quan/where.hpp>

namespace quan{
 
   struct bigint;

   namespace detail{

      struct ll_bigint{
          friend class quan::bigint;
         // for testing use small size ints !

#if defined(QUAN_LL_BIGINT_USE_SMALLINT_IMPL)
//#if (0)
         typedef signed char int32;
         typedef signed short int64;
         typedef unsigned char uint32;
         typedef unsigned short uint64;
#else
         typedef int int32;
         typedef long long int64;
         typedef unsigned int uint32;
         typedef unsigned long long uint64;
#endif
         
         typedef std::vector<uint32>::size_type size_type;
         typedef std::vector<uint32>::difference_type difference_type;

         ll_bigint();
         ~ll_bigint();
         ll_bigint(ll_bigint const & rhs);

         template <typename Int>
         ll_bigint(Int in , typename quan::where_<
               std::is_signed<Int>
            >::type* = 0
         );
         ll_bigint & operator = (ll_bigint const & rhs);

         
         void plus_eq (ll_bigint const & rhs);
         void minus_eq(ll_bigint const & rhs);

         void logical_shl_eq(size_type rhs);
         void arith_shl_eq(size_type rhs);
         void logical_shr_eq(size_type bits);
         void arith_shr_eq(size_type bits);

         void mul_eq( ll_bigint const & rhs);
         void div_eq( ll_bigint const & rhs);
         void mod_eq( ll_bigint const & rhs);

         void bitor_eq(ll_bigint const & rhs);
         void bitand_eq(ll_bigint const & rhs);
         void bitxor_eq(ll_bigint const & rhs);

         void invert();
         void negate();

         static void div_mod(
           ll_bigint const & lhs,ll_bigint const & rhs, 
           ll_bigint & div_result, ll_bigint & mod_result
         );
         static ll_bigint gcd(ll_bigint const & n,ll_bigint const & d);

         bool eq_zero() const;
         bool eq_one() const;
         bool is_negative() const;
         int  compare( ll_bigint const & rhs)  const;
         bool equal_to( ll_bigint const & rhs)  const;
         bool not_equal( ll_bigint const & rhs)  const;
         bool less_than( ll_bigint const & rhs)  const;
         bool less_equal( ll_bigint const & rhs)  const;
         bool greater_equal( ll_bigint const & rhs)  const;
         bool greater( ll_bigint const & rhs)  const;

         template <int N>
         void from_string_base(std::string const & str);
         template <int N>
         std::string to_string_base()const;

         double to_double() const;

         void           move(ll_bigint & rhs);

         std::size_t get_num_elements() const;

         void dump_rep()const;
         size_type force_compact(size_type to_size);
         size_type request_compact(size_type to_size);
         bool extend(ll_bigint::size_type to_size);
         
      private:
         void plus_eq1();
         std::vector<uint32> m_rep;
     
      }; //ll_bigint

   }//detail

}//quan

#endif
