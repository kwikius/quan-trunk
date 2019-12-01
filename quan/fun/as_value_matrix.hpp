#ifndef QUAN_FUN_AS_VALUE_MATRIX_HPP_INCLUDED
#define QUAN_FUN_AS_VALUE_MATRIX_HPP_INCLUDED

#include <quan/fun/matrix.hpp>
#include <quan/fun/as_vector.hpp>

namespace quan{ namespace fun{

   template <typename Matrix>
   struct as_value_matrix{
      typedef quan::fun::matrix<
          matrix_row_size<Matrix>::value,
          matrix_col_size<Matrix>::value
         ,typename as_vector<
            typename get_type_sequence<Matrix>::type
         >::type
      > type;
   };

}}

#endif // QUAN_FUN_AS_VALUE_MATRIX_HPP_INCLUDED
