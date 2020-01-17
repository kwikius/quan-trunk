#ifndef QUAN_META_MAKE_COHERENT_HPP_INCLUDED
#define QUAN_META_MAKE_COHERENT_HPP_INCLUDED

#include <quan/meta/strip_cr.hpp>
#include <quan/undefined.hpp>

namespace quan{ namespace meta{

   // turn a possibly incoherent something into a coherent something
   namespace impl {

      template <typename Q, typename Where = void>
      struct make_coherent_impl : quan::undefined{};

   } // impl

   template <typename Q>
   struct make_coherent : impl::make_coherent_impl< typename quan::meta::strip_cr<Q>::type> {};

}} // quan::meta


#endif // QUAN_META_MAKE_COHERENT_HPP_INCLUDED
