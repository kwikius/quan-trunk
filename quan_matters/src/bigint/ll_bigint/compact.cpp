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
#include <quan/asm/get_msb.hpp>

using quan::detail::ll_bigint;

/*
  request_compact ..
   will go as far as can before losing twos_c info 
*/

ll_bigint::size_type ll_bigint::request_compact(ll_bigint::size_type to_size)
{
  size_type const size = (to_size==0)?0:to_size -1;
  bool const sign = this->is_negative();
  uint32 const mask = (sign)?static_cast<uint32>(~0):0;
  int remove_count = 0;
  for(size_type i = this->get_num_elements()-1; i > size; --i) {
      if ( ( m_rep.at(i) != mask ) ||
      ( quan::asm_::get_msb(this->m_rep.at(i-1)) != sign ) 
      ){
         break;
      }
      else{
          ++ remove_count;
      }
  }

  for (int i = remove_count; i > 0; --i){
    m_rep.pop_back();
  }

  return this->get_num_elements();
}

ll_bigint::size_type ll_bigint::force_compact(ll_bigint::size_type to_size)
{
  
  difference_type const remove_count 
         = static_cast<difference_type>(this->get_num_elements())
             - static_cast<difference_type>(to_size);
  for(difference_type i = 0; i < remove_count; ++i) {
    m_rep.pop_back();
  }
  return this->get_num_elements();
}
