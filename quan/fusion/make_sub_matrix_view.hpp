#ifndef QUAN_FUSION_MAKE_SUB_MATRIX_VIEW_HPP_INCLUDED
#define QUAN_FUSION_MAKE_SUB_MATRIX_VIEW_HPP_INCLUDED

#include <quan/fun/sub_matrix_view.hpp>

namespace quan{ namespace fusion{

   template <int R, int C, typename Matrix>
   inline constexpr
   quan::fun::sub_matrix_view<R,C,Matrix>
   make_sub_matrix_view(Matrix && in)
   {
      return quan::fun::sub_matrix_view<R,C,Matrix>{std::forward<Matrix>(in)};
   }
   
}}  // quan::fusion

#endif // QUAN_FUSION_MAKE_SUB_MATRIX_HPP_INCLUDED
