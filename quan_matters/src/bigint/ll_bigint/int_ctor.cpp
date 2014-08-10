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

// init as default?
template <typename Int>
ll_bigint::ll_bigint(Int in , typename quan::where_<
      std::is_signed<Int>
   >::type* )
{
   size_type size = (sizeof(Int)/sizeof(uint32));
   if ( size == 0 ){
      int32 si = in;
      uint32 elem = static_cast<uint32>(si);
      m_rep.push_back(elem );
     return;
   }
   else{
      static const Int mask = -1;
      for (size_type i = 0; i < size; ++i){
        Int shift = quan::meta::numbits<uint32>::value * i;
        Int v1 = in & (mask << shift);
        Int v2 = v1 >> shift;
        uint32 elem = static_cast<uint32>(v2);
        m_rep.push_back(elem );
      }
      this->request_compact(0);
      return;
    }
}

template quan::detail::ll_bigint::ll_bigint(int,void*);
template quan::detail::ll_bigint::ll_bigint(long,void*);
template quan::detail::ll_bigint::ll_bigint(long long,void*);
