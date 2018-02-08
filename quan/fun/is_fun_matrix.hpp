#ifndef QUAN_FUN_IS_MATRIX_HPP_INCLUDED
#define QUAN_FUN_IS_MATRIX_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <type_traits>
#include <quan/meta/and.hpp>
#include <quan/meta/strip_cr.hpp>
#include <quan/meta/bool/false.hpp>
#include <type_traits>

namespace quan{ namespace fun{

   namespace impl {
      // defualts not a matrix
      template <typename M, typename Where = void> struct is_fun_matrix_impl : std::false_type{};

      template <typename M, typename Where = void>
      struct matrix_row_size_impl : std::integral_constant<int,-1>{};

      template <typename M, typename Where = void>
      struct matrix_col_size_impl : std::integral_constant<int,-1>{};
   }
   
   template <typename M>
   struct is_fun_matrix : impl::is_fun_matrix_impl<typename quan::meta::strip_cr<M>::type>{};

   template <typename ...T>
   struct are_fun_matrices : quan::meta::and_<is_fun_matrix<T>... >{};

   template <typename M>
   struct matrix_row_size : impl::matrix_row_size_impl<typename quan::meta::strip_cr<M>::type>{};

   template <typename M>
   struct matrix_col_size : impl::matrix_col_size_impl<typename quan::meta::strip_cr<M>::type>{};

}}


#endif
