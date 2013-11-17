#ifndef QUAN_META_IMPL_DETAIL_IS_BASE_OF_IMPL_HPP_INCLUDED
#define QUAN_META_IMPL_DETAIL_IS_BASE_OF_IMPL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006-2007

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/bool.hpp>
#include <quan/meta/detail/yes_no_type.hpp>
#include <quan/meta/detail/is_base_of_tester_fun.hpp>

namespace quan{ namespace meta{namespace detail{
   
   template <typename B>
   struct is_base_of_tester{
      static yes_type test( B* p);
      static no_type test(...);
   };

   template <typename B,typename T>
   struct is_base_of_impl{
      typedef is_base_of_tester<B> base;
      typedef is_base_of_tester_fun<T> func;
      static func function();
      const static bool value = (sizeof(yes_type) == sizeof(base::test(function())));
      typedef  quan::meta::bool_<value> type;
   };

   template <typename T>
   struct is_base_of_impl<T,T> {
       typedef quan::meta::bool_<false> type;
   };
   template <typename B, typename T,typename T1>
   struct is_base_of_impl<B, is_base_of_impl<T, T1> > {
       typedef quan::meta::bool_<false> type;
   };
      
}}}


#endif

