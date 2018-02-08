#ifndef QUAN_FUN_INVERSE_VIEW_HPP_INCLUDED
#define QUAN_FUN_INVERSE_VIEW_HPP_INCLUDED

#include <quan/concepts/fusion/matrix.hpp>
#include <quan/fun/matrix_determinant.hpp>
#include <quan/fun/adjunct_view.hpp>
#include <quan/fusion/static_value.hpp>
#include <quan/fun/access_modifiers.hpp>

namespace quan{namespace fun{

 #if ! defined __cpp_concepts
   template <typename Matrix, typename Where = void >
   struct inverse_view;
#else
   template <typename M >
   struct inverse_view;
#endif

#if defined  __cpp_concepts
   template <quan::fusion::Matrix M>
   struct inverse_view<M
#else
   // Matrix must be a square matrix
   template <typename M>
   struct inverse_view<M, 
      typename quan::where_<
         quan::is_model_of<quan::fusion::Matrix_,M>
      >::type
#endif
   >{
      
      typedef inverse_view type;
      typedef typename quan::meta::strip_cr<M>::type matrix_type;
      static_assert(quan::fun::is_fun_matrix<matrix_type>::value,"not a matrix");
      static constexpr int rows = matrix_row_size<matrix_type>::value;
      static constexpr int cols = matrix_col_size<matrix_type>::value;
      static_assert( rows == cols, "not a square matrix");
    
      typedef quan::fun::make_determinant<matrix_type> determinant_type;
      typedef quan::fusion::static_value<float,quan::meta::rational<1> > float_one;
      typedef typename quan::meta::binary_op<
         float_one,
         quan::meta::times, 
         typename determinant_type::type
      >::type determinant_result_type;
      typedef quan::fun::adjunct_view<matrix_type> adjunct_type;

      typedef quan::fun::as_value access_type;

      constexpr inverse_view(matrix_type const & in)
      : m_matrix{in}
      ,m_determinant{ float_one{} * determinant_type{}(in)}
      {}

      template <int R, int C, typename F = as_value>
      struct type_at{
         typedef typename adjunct_type :: template type_at<R,C>::type adj_type;
         typedef typename quan::meta::binary_op<
            adj_type, 
            quan::meta::divides,
            determinant_result_type
         >::type type;
        static_assert( !std::is_same<type,quan::undefined>::value, "bad calc");
      }; 

      template <int R, int C>
      constexpr 
      typename quan::where_c< 
         ((R < rows) && ( C < cols))
        ,typename inverse_view::template type_at<R,C,as_value>::type
      >::type
      at() const  
      {  
         return adjunct_type{m_matrix}. template at<R,C>() / m_determinant;
      }

      private:
      matrix_type const & m_matrix;
      determinant_result_type const m_determinant;
      
   };

 namespace impl {

      template <typename Matrix>
      struct is_fun_matrix_impl<inverse_view<Matrix> > : 
      quan::meta::and_<
         quan::fun::is_fun_matrix<Matrix>
         ,quan::meta::bool_<(matrix_col_size<Matrix>::value == matrix_row_size<Matrix>::value)>
      >{};

      template <typename Matrix>
      struct matrix_row_size_impl<inverse_view<Matrix> > : std::integral_constant<
         int,(inverse_view<Matrix>::rows)
      >{};

      template <typename Matrix>
      struct matrix_col_size_impl<inverse_view<Matrix> > : std::integral_constant<
         int,(inverse_view<Matrix>::cols)
      >{};

   }// impl

}}


#endif // QUAN_FUN_INVERSE_VIEW_HPP_INCLUDED
