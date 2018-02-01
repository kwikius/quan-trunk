#ifndef QUAN_FUN_TRANSPOSE_MATRIX_HPP_INCLUDED
#define QUAN_FUN_TRANSPOSE_MATRIX_HPP_INCLUDED

#include <quan/fun/matrix.hpp>
#include <quan/where.hpp>

/*
  alt transpose_view
  also obvious version, iow a matrix inited with sequence values in the transpose positions
  or maybe like the mux init, do an init or even a custom init sequence
*/

namespace quan{ namespace fun{

     template <typename M, typename = typename quan::where_<quan::fun::is_fun_matrix<M> >::type>
     struct transpose_matrix{
        typedef M original_type;

        typedef transpose_matrix type;
        static constexpr int rows = original_type::cols;
        static constexpr int cols = original_type::rows;
        typedef typename original_type::access_type access_type;
        typedef typename original_type::elements_type elements_type;

        original_type m_matrix;

        template <int R, int C, typename F = as_value
        , typename = typename quan::where_c<((R < rows) && ( C < cols))>::type >
        struct type_at : original_type:: template type_at<C,R,F>{}; 

        constexpr transpose_matrix (original_type const & in) : m_matrix{in}{}

        template <int R, int C>
        constexpr 
        typename quan::where_c< 
           ((R < rows) && ( C < cols))
          ,typename type_at<R,C,as_ref>::type
        >::type
        at()
        {
            return m_matrix. template at<C,R>();
        }

        template <int R, int C>
        constexpr 
        typename quan::where_c< 
           ((R < rows) && ( C < cols))
          ,typename type_at<R,C,as_const_ref>::type
        >::type
        at()const 
        {
           return m_matrix. template at<C,R>();
        }

     };

     namespace impl {

      template <typename M >
      struct is_fun_matrix_impl<
         transpose_matrix<M>
         ,typename quan::where_< quan::fun::is_fun_matrix<M> >::type 
      > : std::true_type{};

      template <typename M>
      struct matrix_row_size_impl<
         transpose_matrix<M>
         ,typename quan::where_< quan::fun::is_fun_matrix<M> >::type 
      > : std::integral_constant<int,(transpose_matrix<M>::rows)>{};

      template <typename M>
      struct matrix_col_size_impl<transpose_matrix<M>
        ,typename quan::where_< quan::fun::is_fun_matrix<M> >::type 
      > : std::integral_constant<int,(transpose_matrix<M>::cols)>{};

   }// impl
    
} }

#endif // QUAN_FUN_TRANSPOSE_MATRIX_HPP_INCLUDED
