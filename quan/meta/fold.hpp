#ifndef QUAN_META_FOLD_HPP_INCLUDED
#define QUAN_META_FOLD_HPP_INCLUDED

#include <quan/meta/detail/fold_i.hpp>

namespace quan{ namespace meta{

   template < typename Seq, typename Init, typename F>
   struct fold{
      typedef typename quan::meta::eval_if_c<
         (quan::meta::get_num_elements<Seq>::value > 0),
         quan::meta::detail::fold_i<Seq,Init,F>,
         Init
      > ::type type;
   };

}}// quan::meta

#endif // QUAN_META_FOLD_HPP_INCLUDED
