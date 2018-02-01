
#ifndef QUAN_FUN_SUB_MATRIX_VIEW_HPP_INCLUDED
#define QUAN_FUN_SUB_MATRIX_VIEW_HPP_INCLUDED

#include <quan/fun/is_fun_matrix.hpp>

namespace quan { namespace fun{

  template <int MatrixRow, int MatrixCol, typename Matrix>
  struct sub_matrix_view{
        typedef sub_matrix_view type;
        typedef typename quan::meta::strip_cr<Matrix>::type parent_matrix_type;
        static constexpr int rows = parent_matrix_type::rows -1;
        static constexpr int cols = parent_matrix_type::cols -1;
        typedef typename parent_matrix_type::access_type access_type;

        sub_matrix_view(parent_matrix_type const & in): m_parent_matrix{in}{}

        template <int R, int C, typename F = as_value>
        struct type_at{
            static int constexpr Rparent = (R < MatrixRow)? R: R + 1;
            static int constexpr Cparent = (C < MatrixCol)? C: C + 1;
            typedef typename parent_matrix_type:: template type_at<Rparent,Cparent,F>::type type;
        };  
/*
        template <int R, int C>
        constexpr 
        typename quan::where_c< 
            ((R < rows) && ( C < cols))
           ,typename type_at<R,C,as_ref>::type
        >::type
        at() &
        {
          typedef typename type_at<R,C,as_ref> type_at1;
          int constexpr r = type_at1::Rparent;
          int constexpr c =type_at1::Cparent;
          return m_parent_matrix. template at<r,c>();
        }
*/
        template <int R, int C>
        constexpr 
        typename quan::where_c< 
            ((R < rows) && ( C < cols))
           ,typename type_at<R,C,as_const_ref>::type
        >::type
        at() const &
        {
          typedef type_at<R,C,as_const_ref> type_atf;
          int constexpr r = type_atf::Rparent;
          int constexpr c = type_atf::Cparent;
          return m_parent_matrix. template at<r,c>();
        }
        private:
        parent_matrix_type const & m_parent_matrix;
  };

    namespace impl {

      template <int MatrixRow, int MatrixCol, typename Matrix>
      struct is_fun_matrix_impl<sub_matrix_view<MatrixRow,MatrixCol,Matrix> > : 
      quan::meta::and_<
         quan::fun::is_fun_matrix<Matrix>
         ,quan::meta::bool_< (MatrixRow < matrix_row_size<Matrix>::value) >
         ,quan::meta::bool_< (MatrixCol < matrix_col_size<Matrix>::value) >
      >{};

      template <int MatrixRow, int MatrixCol, typename Matrix>
      struct matrix_row_size_impl<sub_matrix_view<MatrixRow,MatrixCol,Matrix> > : std::integral_constant<
         int,(sub_matrix_view<MatrixRow,MatrixCol,Matrix>::rows)
      >{};

      template <int MatrixRow, int MatrixCol, typename Matrix>
      struct matrix_col_size_impl<sub_matrix_view<MatrixRow,MatrixCol,Matrix> > : std::integral_constant<
         int,(sub_matrix_view<MatrixRow,MatrixCol,Matrix>::cols)
      >{};

   }// impl

}}  // quan::fun

#endif
