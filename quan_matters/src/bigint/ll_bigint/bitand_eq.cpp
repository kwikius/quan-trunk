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

using quan::detail::ll_bigint;

void ll_bigint::bitand_eq(ll_bigint const & rhs)
{
   size_type const rhs_size = rhs.get_num_elements();
   size_type const size = std::max(this->get_num_elements(),rhs_size);
   uint32 const mask = (rhs.is_negative())?static_cast<uint32>(~0): 0;
   this->extend(size);
   for (size_type i = 0; i < rhs_size; ++i){
      this->m_rep.at(i) &= rhs.m_rep.at(i);
   }
   for ( size_type i = rhs_size; i < size; ++i){
      this->m_rep.at(i) &= mask;
   }
}
