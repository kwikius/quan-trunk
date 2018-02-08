#ifndef QUAN_FUSION_MAKE_INVERSE_VIEW_HPP_INCLUDED
#define QUAN_FUSION_MAKE_INVERSE_VIEW_HPP_INCLUDED

#include <quan/fusion/matrix.hpp>
#include <quan/fun/inverse_view.hpp>

namespace quan { namespace fusion{

   template <typename M>
   inline constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::fun::is_fun_matrix<M>
         ,quan::meta::bool_<is_square_matrix<M> >
      >
      ,quan::fun::inverse_view<M>   
   >::type
   make_inverse_view( M && m)
   {
      return quan::fun::inverse_view<M>{m};
   }

}} //quan::fusion

#endif // QUAN_FUSION_MAKE_INVERSE_VIEW_HPP_INCLUDED
