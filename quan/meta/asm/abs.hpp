
#ifndef QUAN_META_ASM_ABS_HPP_INCLUDED
#define QUAN_META_ASM_ABS_HPP_INCLUDED

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
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <type_traits>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{namespace asm_{

   namespace impl{

      template <typename T, T v>
      struct signed_abs_impl{
         static const T value = (v >=0) ? v : -v;
         typedef signed_abs_impl type;
      };
      template <typename T, T v>
      struct unsigned_abs_impl{
         static const T value = v;
         typedef unsigned_abs_impl type;
      };
      
   }

   template <typename T, T v>
   struct abs{
      typedef typename quan::meta::eval_if<
         std::is_signed<T>,
         impl::signed_abs_impl<T,v>,
         impl::unsigned_abs_impl<T,v>
      >::type type;
      static const T value = type::value;
   };

}}}//quan::meta::asm_

#endif

