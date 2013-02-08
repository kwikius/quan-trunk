#ifndef QUAN_META_FOR_EACH_HPP_INCLUDED
#define QUAN_META_FOR_EACH_HPP_INCLUDED

#include <quan/meta/impl/for_each_impl.hpp>

namespace quan{ namespace meta{

   template <typename Sequence, typename Fun>
   struct for_each : quan::meta::impl::for_each_impl<Sequence, Fun>{};

}}//quan::meta

#endif // QUAN_META_FOR_EACH_HPP_INCLUDED
