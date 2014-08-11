#ifndef QUAN_FUN_FILL_HPP_INCLUDED
#define QUAN_FUN_FILL_HPP_INCLUDED
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
 along with this program. If not, see http://www.gnu.org/licenses./
 */
namespace quan{namespace fun{
namespace impl_detail{
   template <typename T>
   struct fill{
      T const & val;
      fill(T const & in): val(in){}
      template <typename T1>
      void operator()(T1& t)const
      {
         t =val;
      }
   };
}

template <typename T>
impl_detail::fill<T> fill (T const & val)
{
   return impl_detail::fill<T>(val);
}
}}//quan::fun

#endif
