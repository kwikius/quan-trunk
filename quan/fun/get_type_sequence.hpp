#ifndef QUAN_FUN_GET_TYPE_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_GET_TYPE_SEQUENCE_HPP_INCLUDED

#include <quan/fun/get_matrix_type_sequence.hpp>

namespace quan{ namespace fun{

   template <typename T, typename Where = void>
   struct get_type_sequence;

   template<typename Matrix>
   struct get_type_sequence<
      Matrix
      ,typename quan::where_<quan::fun::is_fun_matrix<Matrix> >::type
   >
   {
      typedef typename detail::get_matrix_type_sequence_n<
         matrix_row_size<Matrix>::value -1, matrix_col_size<Matrix>::value-1
         ,Matrix
      >::type type;
   };

}}

#endif // QUAN_FUN_GET_TYPE_SEQUENCE_HPP_INCLUDED
