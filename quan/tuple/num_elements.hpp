#ifndef QUAN_TUPLE_NUM_ELEMENTS_HPP_INCLUDED
#define QUAN_TUPLE_NUM_ELEMENTS_HPP_INCLUDED

#include <quan/concepts/tuple.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan{ namespace tuple{

   namespace impl{

      template <typename T, typename Where = void>
      struct num_elements_impl{}; 
   }

   template <typename T>
   struct num_elements : impl::num_elements_impl<
      typename quan::meta::strip_cr<T>::type
   >{};

}}//quan::tuple

#endif

