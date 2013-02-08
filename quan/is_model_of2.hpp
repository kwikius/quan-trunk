#ifndef QUAN_IS_MODEL_OF2_HPP_INCLUDED
#define QUAN_IS_MODEL_OF2_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/where_fwd.hpp>
#include <quan/meta/bool/false.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan{

   namespace impl{

      template < typename Concept,typename T1, typename T2,typename Where>
      struct is_model_of_impl2 : quan::meta::false_{};
   }

   template <typename Concept,typename T1,typename T2>
   struct is_model_of2 : quan::impl::is_model_of_impl2 <
      Concept,
      typename quan::meta::strip_cr<T1>::type,
      typename quan::meta::strip_cr<T2>::type
   >{};

}

#endif

