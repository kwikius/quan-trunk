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

/*
  request_compact as far as can before losing twos_c info 
*/

bool ll_bigint::extend(ll_bigint::size_type to_size)
{
   difference_type size_diff = to_size - this->get_num_elements() ;
   if (size_diff <= 0 ){
      return false;
   }else{
      bool const sign = this->is_negative();
      uint32 const mask = (sign)?static_cast<uint32>(~0):0;
      for(difference_type i = 0; i < size_diff; ++i) {
         m_rep.push_back(mask);
      }
      return true;
   }
}
