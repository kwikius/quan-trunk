#ifndef QUAN_FUN_IS_MATRIX_HPP_INCLUDED
#define QUAN_FUN_IS_MATRIX_HPP_INCLUDED

#include <type_traits>
#include <quan/meta/and.hpp>

namespace quan{ namespace fun{
   
   template <typename T>
   struct is_fun_matrix : std::false_type{};

   template <typename TL,typename TR>
   struct are_fun_matrices : quan::meta::and_<
     is_fun_matrix<TL>,is_fun_matrix<TR>
   >{} ;

   template <typename Matrix>
   struct matrix_row_size : std::integral_constant<int,-1>{};

   template <typename Matrix>
   struct matrix_col_size : std::integral_constant<int,-1>{};

   
   

}}


#endif
