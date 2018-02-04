#ifndef QUAN_FUSION_MAKE_MULTIPLIES_VIEW_HPP_INCLUDED
#define QUAN_FUSION_MAKE_MULTIPLIES_VIEW_HPP_INCLUDED

#include <quan/fun/matrix_multiplies_view.hpp>

namespace quan { namespace fusion{

   template <typename MatrixL, typename MatrixR>
   inline constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_matrices<MatrixL,MatrixR>
         ,quan::meta::bool_<
            (quan::fun::matrix_col_size<MatrixL>::value
            == quan::fun::matrix_row_size<MatrixR>::value)
         >
      >
      ,quan::fun::multiplies_view<MatrixL,MatrixR>   
   >::type
   make_multiplies_view( MatrixL && ml, MatrixR && mr)
   {
      return quan::fun::multiplies_view<MatrixL,MatrixR>{ml,mr};
   }

}} //quan::fusion

#endif // QUAN_FUSION_MAKE_MULTIPLIES_VIEW_HPP_INCLUDED
