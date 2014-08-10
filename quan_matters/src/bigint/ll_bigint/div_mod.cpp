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
 along with this program. If not, see http://www.gnu.org/licenses.
*/
#include <quan/detail/ll_bigint.hpp>

#include <cassert>


using quan::detail::ll_bigint;


void ll_bigint::div_mod(
   ll_bigint const & lhs,ll_bigint const & rhs,
   ll_bigint & div_result, ll_bigint & mod_result)
{
   assert( ! rhs.eq_zero() );
   
   ll_bigint remainder = lhs;
   remainder.request_compact(0);
   bool const lhs_neg 
    = remainder.is_negative()
      ?(remainder.negate(),true)
      :false;
   
   ll_bigint divisor = rhs;
   divisor.request_compact(0);
   bool const rhs_neg 
    = (divisor.is_negative())
      ?(divisor.negate(),true)
      :false;

   ll_bigint dividend = 0;
   dividend.request_compact(0);

   int shift = 0;

   while ( divisor.less_equal(remainder)){
     divisor.arith_shl_eq(1);
     ++shift;
   }

   for(int i = shift; i > 0; --i) {
      divisor.arith_shr_eq(1);
      dividend.arith_shl_eq(1);
      ll_bigint t = remainder;
      t.minus_eq(divisor);
      if ( ! t.is_negative()){
         dividend.m_rep.at(0) |= 1;
         remainder = t;
      }
   }

   dividend.request_compact(0);
   div_result 
      = ( lhs_neg == rhs_neg)
      ? dividend
      : (dividend.negate(),dividend);
     
   remainder.request_compact(0);
   mod_result = remainder;
}
