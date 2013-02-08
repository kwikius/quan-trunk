#ifndef QUAN_META_DETAIL_FOLD_I_HPP_INCLUDED
#define QUAN_META_DETAIL_FOLD_I_HPP_INCLUDED

#include <quan/meta/type_sequence.hpp>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{ namespace detail{

      template <typename Seq, typename Init, typename F>
      struct fold_i{
         typedef typename quan::meta::front<Seq>::type element_type;
         typedef typename F::template apply<Init,element_type>::type output_type;
         typedef typename quan::meta::pop_front<Seq>::type list_in_next;
         typedef typename quan::meta::eval_if_c<
            (quan::meta::get_num_elements<list_in_next>::value > 0),
            fold_i<list_in_next,output_type,F>,
            output_type
         >::type type;
           
      };

}}}//quan::meta::detail


#endif // QUAN_META_DETAIL_FOLD_I_HPP_INCLUDED
