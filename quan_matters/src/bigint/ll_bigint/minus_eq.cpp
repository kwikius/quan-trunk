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
#include <algorithm>

using quan::detail::ll_bigint;

void ll_bigint::minus_eq (ll_bigint const & rhs_in)
{
  this->request_compact(0);
  ll_bigint rhs = rhs_in;
  rhs.request_compact(0);
  size_type size = std::max(this->get_num_elements(),rhs.get_num_elements()) +1;
  this->extend(size);
  rhs.extend(size);
  for ( size_type i = 0; i != size; ++i){
      uint64 res 
         = static_cast<uint64>(this->m_rep.at(i))
         - static_cast<uint64>(rhs.m_rep.at(i));
      this->m_rep.at(i) = static_cast<uint32>(quan::asm_::lo_nibble(res));
      bool carry = quan::asm_::hi_nibble(res)  != 0 ;
      for ( size_type carry_pos = i + 1; carry && ( carry_pos < size ) ; ++carry_pos){
         res = static_cast<uint64>( this->m_rep.at(carry_pos)) - 1;
         this->m_rep.at(carry_pos) = static_cast<uint32>(quan::asm_::lo_nibble(res));
         carry = quan::asm_::hi_nibble(res)  !=0 ;
      }
   }
   this->request_compact(0);
   return;
}
