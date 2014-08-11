#ifndef QUAN_META_UNDEFINED_OPERATION_HPP_INCLUDED
#define QUAN_META_UNDEFINED_OPERATION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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

#include <quan/meta/bool/false.hpp>

namespace quan{ namespace meta{

   struct quan::undefined{
     
      typedef quan::undefined type;
    //  protected:
        // template<typename T,typename T1> friend class any_type;
         quan::undefined(quan::undefined const &);
         quan::undefined& operator= (quan::undefined const &);
         quan::undefined();
         
   };

   namespace impl{
      template <typename T,typename Where >
      struct is_any_type_impl;

      template <>
      struct is_any_type_impl<quan::undefined,void> 
      : quan::meta::false_{};
   }

}}

#endif

