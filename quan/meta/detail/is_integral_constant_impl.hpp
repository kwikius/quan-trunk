#ifndef QUAN_META_IMPL_DETAIL_IS_STD_INTEGRAL_CONSTANT_IMPL_HPP_INCLUDED
#define QUAN_META_IMPL_DETAIL_IS_STD_INTEGRAL_CONSTANT_IMPL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

 // Copyright (c) 2007 Andrew Little.  ALL RIGHTS RESERVED.
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

