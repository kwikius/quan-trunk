#ifndef QUAN_FUSION_DETERMINANT_HPP_INCLUDED
#define QUAN_FUSION_DETERMINANT_HPP_INCLUDED

#include <quan/fun/matrix_determinant.hpp>

namespace quan{ namespace fusion{

   template <
      typename M 
   >
   inline constexpr 
   typename quan::where_<
      quan::meta::and_<
         quan::fun::is_fun_matrix<M>
         ,quan::meta::bool_<
            (quan::fun::matrix_col_size<M>::value ==
             quan::fun::matrix_row_size<M>::value)
         >
      >
      ,typename quan::fun::make_determinant<M>::type
   >::type
   determinant ( M const & m)
   {
      return quan::fun::make_determinant<M>{}(m);
   }
 
}} // quan::fusion

#endif // QUAN_FUDION_MATRIX_DETERMINANT_HPP_INCLUDED
