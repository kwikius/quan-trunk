#ifndef QUAN_CONCEPTS_FUSION_MATRIX_HPP_INCLUDED
#define QUAN_CONCEPTS_FUSION_MATRIX_HPP_INCLUDED

#include <quan/fun/is_fun_matrix.hpp>
#include <quan/fun/access_modifiers.hpp>
#include <quan/is_model_of.hpp>

namespace quan { namespace fusion{

#if defined __cpp_concepts

   template <typename M>
   concept bool Matrix = quan::fun::is_fun_matrix<M>::value;

#endif

   struct Matrix_;

}} // quan::fusion

// do the old pre concepts version always
namespace quan{ namespace impl{

      template <typename M> 
      struct is_model_of_impl<
         quan::fusion::Matrix_,M, 
         typename quan::where_<quan::fun::is_fun_matrix<M> >::type 
      > : quan::meta::true_{};
}} // quan::impl

namespace quan { namespace fusion{

#if defined __cpp_concepts

   template <int R, int C , Matrix M>
   using matrix_at_t = typename M:: template type_at<R,C,quan::fun::as_value>::type;

   template <quan::fusion::Matrix M>
   constexpr std::size_t num_rows = quan::fun::matrix_row_size<M>::value;

   template <quan::fusion::Matrix M>
   constexpr std::size_t num_columns = quan::fun::matrix_col_size<M>::value;

   template <quan::fusion::Matrix M>
   constexpr bool is_square_matrix = num_rows<M> == num_columns<M>;

#else

   template <int R, int C , typename M>
   using matrix_at_t = typename M:: template type_at<R,C,quan::fun::as_value>::type;

   template <typename M>
   constexpr std::size_t num_rows = quan::fun::matrix_row_size<M>::value;

   template <typename M>
   constexpr std::size_t num_columns = quan::fun::matrix_col_size<M>::value;

   template <typename M>
   constexpr bool is_square_matrix = num_rows<M> == num_columns<M>;

#endif

}} // quan::fusion


#endif // QUAN_CONCEPTS_FUSION_MATRIX_HPP_INCLUDED
