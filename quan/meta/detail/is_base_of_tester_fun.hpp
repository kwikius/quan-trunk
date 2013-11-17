#ifndef QUAN_META_IMPL_DETAIL_IS_BASE_OF_TESTER_FUN_HPP_INCLUDED
#define QUAN_META_IMPL_DETAIL_IS_BASE_OF_TESTER_FUN_HPP_INCLUDED
#define QUAN_META_IMPL_DETAIL_IS_BASE_OF_IMPL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006

namespace quan{ namespace meta{namespace detail{

   template <typename T>
   struct is_base_of_tester_fun{
    //typedef typename quan::meta::strip_cr<T>::type result_type;
      //typedef T* result_type;
    operator  T* () const;
   };

}}}

#endif

