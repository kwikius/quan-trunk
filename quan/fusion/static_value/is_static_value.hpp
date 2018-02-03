#ifndef QUAN_FUSION_IS_STATIC_VALUE_HPP_INCLUDED
#define QUAN_FUSION_IS_STATIC_VALUE_HPP_INCLUDED

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/bool/false.hpp>

namespace quan{namespace fusion{

    namespace impl{
       template <typename T>
      struct is_static_value_impl : quan::meta::false_{};
      
    } // impl

    template <typename T>
    struct is_static_value : impl::is_static_value_impl<typename quan::meta::strip_cr<T>::type>{};

}}//quan::fusion

#endif
