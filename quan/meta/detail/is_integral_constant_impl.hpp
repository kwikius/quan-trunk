#ifndef QUAN_META_IMPL_DETAIL_IS_STD_INTEGRAL_CONSTANT_IMPL_HPP_INCLUDED
#define QUAN_META_IMPL_DETAIL_IS_STD_INTEGRAL_CONSTANT_IMPL_HPP_INCLUDED
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
 // No part of this document may be reproduced or transmitted 
 // in any form or by any means without the written permission 
 // of the author.

#include <type_traits>
#include <quan/meta/impl_detail/yes_no_type.hpp>

namespace quan{ namespace meta{namespace impl_detail{

   struct integral_constant_tester{

      template <typename T1, T1 N>
      static yes_type f( std::integral_constant<T1,N>* p);
      static no_type f(...);

      template <typename T>
      static T * fun();
   };

   template <typename T>
   struct is_integral_constant_impl : std::integral_constant<
      bool,
      (sizeof(integral_constant_tester::f(integral_constant_tester::fun<
         typename std::remove_const<typename std::remove_reference<T>::type>::type
         >()))
         == sizeof(quan::meta::impl_detail::yes_type))
   >{};

}}}


#endif

