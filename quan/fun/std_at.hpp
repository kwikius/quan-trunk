#ifndef QUAN_FUN_STD_AT_HPP_INCLUDED
#define QUAN_FUN_STD_AT_HPP_INCLUDED
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

// impl functors
// to do push_back and at
namespace quan{ namespace fun{namespace impl_detail{

      struct std_at_{
         std_at_(size_t n_in) : n(n_in){}
      size_t n;
         template <typename C>
         typename C::value_type 
         operator()(C & c) const
         {
            return c.at(n);
         }

      };
   }
// interface functions for push_back, at
   inline
   impl_detail::std_at_ std_at( size_t n)
   {
      return impl_detail::std_at_(n);
   };
}}

#endif
