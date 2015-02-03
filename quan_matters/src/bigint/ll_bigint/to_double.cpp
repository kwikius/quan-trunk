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
#include <cmath>

using quan::detail::ll_bigint;

double ll_bigint::to_double() const
{
   ll_bigint absv = *this;
   bool is_neg = (this->is_negative())? absv.negate(), true: false;
  
   double accum = absv.m_rep[0];
   double const mulk = std::pow(2., static_cast<double>(
         quan::meta::numbits<uint32>::value
      )
   );

   double mulp = 1.;

   for ( std::size_t i = 1; i < m_rep.size(); ++i){
      mulp *= mulk;
      accum += absv.m_rep[i] * mulp;
   }
   
   return (is_neg) ? - accum : accum;
}
