#ifndef QUAN_IS_MODEL_OF_HPP_INCLUDED
#define QUAN_IS_MODEL_OF_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/where.hpp>
#include <quan/meta/bool/false.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/strip_cr.hpp>
#include <quan/is_model_of_fwd.hpp>

namespace quan{

   namespace impl{

      template < typename Concept,typename T,typename Where>
      struct is_model_of_impl : quan::meta::false_{};
   }

   template <typename Concept,typename T>
   struct is_model_of : quan::impl::is_model_of_impl <
      Concept,
      typename quan::meta::strip_cr<T>::type
   >{};

}

#endif

