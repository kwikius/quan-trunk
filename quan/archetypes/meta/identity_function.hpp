#ifndef QUAN_CONCEPTS_META_IDENTITY_FUNCTION_HPP_INCLUDED
#define QUAN_CONCEPTS_META_IDENTITY_FUNCTION_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/meta/detail/is_type_function.hpp>
#include <quan/std/tr1/is_same.hpp>

namespace quan{ namespace meta{

   struct IdentityFunction_;

}}

namespace quan{ namespace impl{

   template <typename T>
   struct is_model_of_impl<
      quan::meta::IdentityFunction_,T,
      typename quan::where_<
         quan::meta::impl_detail::is_type_function<T>
      >::type
   > : std::tr1::is_same<T,typename T::type>{};

}}

#endif

