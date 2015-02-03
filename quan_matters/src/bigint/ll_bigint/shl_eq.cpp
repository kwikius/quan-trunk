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
#include <quan/meta/numbits.hpp>

using quan::detail::ll_bigint;

/*
 logical shift left... change in size to accomodate.
 keep sign so if currently negative then keep negative etc.
*/

void ll_bigint::arith_shl_eq(size_type shift)
{
   size_type const wordshift = shift / quan::meta::numbits<uint32>::value;
   difference_type const dH = shift % quan::meta::numbits<uint32>::value;
   difference_type const dL = quan::meta::numbits<uint32>::value - dH;

   bool const neg = this->is_negative();
   
   if ( neg){
    this->extend(this->get_num_elements() + 1);
   }
   
   size_type const size = this->get_num_elements() + wordshift + 1;
   std::vector<uint32> dest(size,0);
   
   for ( size_type i = 0; i < this->get_num_elements(); ++i){
      difference_type const dest_idx = i + wordshift;
      uint32 const hi_src = this->m_rep.at(i) >> dL;
      dest.at(dest_idx +1) |= hi_src;
      uint32 const lo_src = this->m_rep.at(i) << dH;
      dest.at(dest_idx ) |= lo_src;
   }
   if ( neg){ // chop the crap off the msb
    dest.pop_back();
   }
   this->m_rep = dest;
   this->request_compact(0);
}
/*
 probably should be fixed size?
*/
void ll_bigint::logical_shl_eq(size_type shift)
{
   size_type const wordshift = shift / quan::meta::numbits<uint32>::value;
   difference_type const dH = shift % quan::meta::numbits<uint32>::value;
   difference_type const dL = quan::meta::numbits<uint32>::value - dH;

   /*bool const neg = this->is_negative();
   
   if ( neg){
    this->extend(this->get_num_elements() + 1);
   }
   */
   size_type const size = this->get_num_elements() + wordshift + 1;
   std::vector<uint32> dest(size,0);
   
   for ( size_type i = 0; i < this->get_num_elements(); ++i){
      difference_type const dest_idx = i + wordshift;
      uint32 const hi_src = this->m_rep.at(i) >> dL;
      dest.at(dest_idx +1) |= hi_src;
      uint32 const lo_src = this->m_rep.at(i) << dH;
      dest.at(dest_idx ) |= lo_src;
   }
   /*
   if ( neg){ // chop the crap off the msb
    dest.pop_back();
   }
   */
   this->m_rep = dest;
   //this->request_compact(0);
   //this->force_compact(0);
}



