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
#include <quan/asm/nibble.hpp>

using quan::detail::ll_bigint;

void ll_bigint::mul_eq(ll_bigint const & rhs_in)
{
  
   this->request_compact(0);
   ll_bigint rhs = rhs_in; // may be == to this
   bool const lhs_neg
      = ( this->is_negative() )
      ? (this->negate(),true)
      : false;

   size_type const lhs_size = this->get_num_elements();
   rhs.request_compact(0);
   bool const rhs_neg 
      = rhs.is_negative()
      ? (rhs.negate(),true)
      : false;
   size_type const rhs_size = rhs.get_num_elements();

   ll_bigint result = 0;
   result.extend( lhs_size + rhs_size );
   size_type const result_size = result.get_num_elements();
    
   for ( size_type i = 0 ;i != lhs_size; ++i){
      for ( size_type j = 0 ; j != rhs_size; ++j){
         uint64 temp0 
           = static_cast<uint64>(this->m_rep.at(i) )
           * static_cast<uint64>(rhs.m_rep.at(j) );
         for ( size_type k = i + j ;
             ( (temp0 != 0) && ( k  != result_size ) );
               ++k){
            uint64 temp1 
               = result.m_rep.at(k) + quan::asm_::lo_nibble(temp0) ;
            result.m_rep.at(k) 
               = static_cast<uint32>(quan::asm_::lo_nibble(temp1));
            temp0 
               = quan::asm_::hi_nibble(temp0) + quan::asm_::hi_nibble(temp1);
         }
      }
   }
   *this 
      = ( lhs_neg == rhs_neg )
      ? result 
      : (result.negate(),result);
    this->request_compact(0);

}
