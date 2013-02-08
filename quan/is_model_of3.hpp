#ifndef QUAN_IS_MODEL_OF3_HPP_INCLUDED
#define QUAN_IS_MODEL_OF3_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/where_fwd.hpp>
#include <quan/meta/bool/false.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan{

   namespace impl{

      template < typename Concept,typename T1, typename T2,typename T3,typename Where>
      struct is_model_of_impl3 : quan::meta::false_{};
   }

   template <typename Concept,typename T1,typename T2,typename T3>
   struct is_model_of3 : quan::impl::is_model_of_impl3 <
      Concept,
      typename quan::meta::strip_cr<T1>::type,
      typename quan::meta::strip_cr<T2>::type,
      typename quan::meta::strip_cr<T3>::type
   >{};

}

#endif

