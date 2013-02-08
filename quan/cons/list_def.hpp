#ifndef QUAN_SEQ_CONS_CONS_DEF_HPP_INCLUDED
#define QUAN_SEQ_CONS_CONS_DEF_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/tuple/at.hpp>
#include <quan/tuple/num_elements.hpp>
#include <quan/concepts/meta/type_sequence.hpp>
#include <quan/meta/detail/type_sequence_at.hpp>
#include <quan/concepts/meta/type_sequence.hpp>

namespace quan{namespace cons{

   struct nil{
      typedef nil type;
   };

   template <typename T, typename Front = nil>
   struct list;
}}

namespace quan{ namespace tuple{ namespace impl{

    template <int N,typename T, typename Front,typename Access>
    struct at_impl<N,quan::cons::list<T,Front>,Access> 
      : quan::meta::detail::type_sequence_at<N,quan::cons::list<T,Front>,Access>{};

   template <typename T, typename Front>
   struct num_elements_impl<quan::cons::list<T,Front> > : quan::cons::list<T,Front>::length{};

}}}//quan::tuple::impl

namespace quan{ namespace impl{

   template <typename T, typename Front>
   struct is_model_of_impl<
      quan::meta::TypeSequence,
      quan::cons::list<T,Front>
   > : quan::meta::true_{};
}}


#endif
