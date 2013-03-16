#ifndef QUAN_META_IF_HPP_INCLUDED
#define QUAN_META_IF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2006-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/


namespace quan{ namespace meta{
   
   template <bool B, typename T, typename F>
   struct if_c{
      typedef T type;
   };

   template <typename T,typename F>
   struct if_c<false,T,F> {
      typedef F type;
   };

   template<typename C, typename T, typename F>
   struct if_ : if_c<((C::value)!=0),T,F>{};
   
}}//quan::meta

#endif
