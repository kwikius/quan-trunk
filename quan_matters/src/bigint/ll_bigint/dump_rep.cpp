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

#include <iostream>

using quan::detail::ll_bigint;

void ll_bigint::dump_rep()const
{
   for ( difference_type i = this->get_num_elements()-1; i >=0; --i){
     if ( i < static_cast<difference_type>(this->get_num_elements() -1)){
        std::cout << ",";
     }
     std::cout << std::hex << static_cast<size_type>(this->m_rep.at(i));
   }
   std::cout << '\n';
}
