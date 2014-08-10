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

int ll_bigint::compare(ll_bigint const & rhs)const
{
  ll_bigint lhs = *this;
  lhs.minus_eq(rhs);

  if ( lhs.eq_zero()){
    return 0;
  }
  return (lhs.is_negative())? -1 : 1 ;
}

bool ll_bigint::eq_zero() const
{
  for ( size_type i = 0; i < this->get_num_elements();++i){
    if (this->m_rep[i] != 0){
      return false;
    }
  }
  return true;
}

bool ll_bigint::eq_one() const
{
   for ( size_type i = 1; i < this->get_num_elements();++i){
    if (this->m_rep[i] != 0){
      return false;
    }
  }
  return  m_rep[0] == 1 ;
}

bool ll_bigint::equal_to( ll_bigint const & rhs)  const
{
  return this->compare(rhs) == 0 ;
}

bool ll_bigint::not_equal( ll_bigint const & rhs)  const
{
  return this->compare(rhs) != 0 ;
}

bool ll_bigint::less_than( ll_bigint const & rhs)  const
{
  return this->compare(rhs) < 0 ;
}

bool ll_bigint::less_equal( ll_bigint const & rhs)  const
{
  return this->compare(rhs) <= 0 ;
}

bool ll_bigint::greater_equal( ll_bigint const & rhs)  const
{
  return this->compare(rhs) >= 0 ;
}

bool ll_bigint::greater( ll_bigint const & rhs)  const
{
  return this->compare(rhs) > 0 ;
}



