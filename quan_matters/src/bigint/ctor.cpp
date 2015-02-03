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
#include <quan/bigint.hpp>

#if (QUAN_BIGINT_VERSION == 2)
// quan::bigint::bigint() : m_alloc_size(0) ,m_value(0){}
 
/*
template <typename Int>
quan::ll_bigint::ll_bigint(Int in , typename quan::where_<
      std::is_signed<Int>
   >::type* = 0):m_alloc_size(0)
{
   this->signed_int_init(in ) ;
}
*/
#endif
#if (QUAN_BIGINT_VERSION == 1)
quan::bigint::bigint(): m_sign(1){}
#endif

#if (QUAN_BIGINT_VERSION == 2)


#endif

#if (QUAN_BIGINT_VERSION == 1)
quan::bigint::bigint(std::string const & str)
{
  this->assign_from_string(str);
}

quan::bigint::bigint(int n)
:
m_rep( static_cast<unsigned int>((n>=0)?n:-n)),
m_sign ( (n>=0)?1:-1 )
{}

quan::bigint::bigint(unsigned int n)
:m_rep(n),m_sign (1 ){}

quan::bigint::bigint(long n)
:m_rep( static_cast<unsigned long>((n>=0L)?n:-n)),
m_sign ( (n>=0)?1:-1 )
{}
quan::bigint::bigint(unsigned long n)
:m_rep(n),m_sign (1 ){}

quan::bigint::bigint(long long n)
:m_rep( static_cast<unsigned long long>((n>=0)?n:-n)),
m_sign ( (n>=0)?1:-1 ){}

quan::bigint::bigint(unsigned long long n)
:m_rep(n),m_sign (1 ){}


#endif
