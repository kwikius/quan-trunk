#ifndef QUAN_META_TRANSFORM_HPP_INCLUDED
#define QUAN_META_TRANSFORM_HPP_INCLUDED

#include <quan/meta/type_sequence.hpp>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{

   namespace detail{

        template <typename ListIn, typename ListOut, typename F>
        struct transform_i
        {
             typedef typename quan::meta::front<ListIn>::type element_type;
             typedef typename F::template apply<element_type>::type output_element;
             typedef typename quan::meta::pop_front<ListIn>::type list_in_next;
             typedef typename quan::meta::push_back<ListOut,output_element>::type list_out;
             typedef typename quan::meta::eval_if_c<
               (quan::meta::get_num_elements<list_in_next>::value > 0),
               transform_i<list_in_next,list_out,F>,
               list_out
             >::type type;
        };
   }
  
   template <typename List, typename F>
   struct transform {
      typedef typename quan::meta::eval_if_c<
         (quan::meta::get_num_elements<List>::value > 0),
         quan::meta::detail::transform_i<List,quan::meta::type_sequence<>,F>,
         quan::meta::type_sequence<>
      >::type type;
   };

}}


#endif // QUAN_META_TRANSFORM_HPP_INCLUDED
