
#ifndef QUAN_FUN_STD_FOR_EACH_HPP_INCLUDED
#define QUAN_FUN_STD_FOR_EACH_HPP_INCLUDED
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

#include <quan/fun/is_fun_sequence.hpp>

namespace quan{namespace fun{

   template <typename C, typename F>
   inline
   typename quan::where_not
      is_fun_sequence<C>,
      void
   >::type
   for_each(C & c, F const & f)
   {
      for(auto elem : c,[]() {f(elem);} );
   }
   
  
}}//quan::fun

#endif
