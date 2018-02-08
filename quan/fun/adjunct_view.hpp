#ifndef QUAN_FUN_ADJUNCT_MATRIX_VIEW_HPP_INCLUDED
#define QUAN_FUN_ADJUNCT_MATRIX_VIEW_HPP_INCLUDED

#include <quan/concepts/fusion/matrix.hpp>
#include <quan/fun/sub_matrix_view.hpp>
#include <quan/fun/matrix_determinant.hpp>

namespace quan{ namespace fun{

   #if defined __cpp_concepts
   template <typename M>
   struct adjunct_view;
   #else
   template <typename M, typename Where = void>
   struct adjunct_view;
   #endif

   #if  defined __cpp_concepts
   template <quan::fusion::Matrix M>
   struct adjunct_view<M
   #else
   template <typename M>
   struct adjunct_view<M
      ,typename quan::where_<
         quan::is_model_of<quan::fusion::Matrix_,M>
      >::type
   #endif
   >{
      typedef adjunct_view type;
      typedef typename quan::meta::strip_cr<M>::type matrix_type;

      static constexpr int rows = matrix_col_size<matrix_type>::value;
      static constexpr int cols = matrix_row_size<matrix_type>::value;

      typedef typename matrix_type::access_type access_type;

      constexpr adjunct_view(matrix_type const & in): m_matrix{in}{}

      template <int R, int C, typename F = as_value>
      struct type_at{
         typedef quan::fun::sub_matrix_view<C,R,matrix_type> sub_matrix_type;
         typedef typename quan::fun::make_determinant<sub_matrix_type>::type det_result_type;
         static constexpr int sign = ((C+R)% 2 == 0)? 1: -1;
         typedef quan::fusion::static_value<int, quan::meta::rational<sign,1> > sign_type;
         typedef typename quan::meta::binary_op<sign_type , quan::meta::times,det_result_type>::type type;
      };  

      template <int R, int C>
      constexpr 
      typename quan::where_c< 
         ((R < rows) && ( C < cols))
         ,typename type_at<R,C,as_value>::type
      >::type
      at() const  
      {
         typedef typename type_at<R,C>::sub_matrix_type sub_matrix_type;
         typedef typename type_at<R,C>::sign_type sign_type;

         return sign_type{} * make_determinant<sub_matrix_type>{}(sub_matrix_type{m_matrix});
      }
      private:
      matrix_type const & m_matrix;
   };

    namespace impl {

      template <typename M>
      struct is_fun_matrix_impl<
         adjunct_view<M>
         ,typename quan::where_<quan::fun::is_fun_matrix<M> >::type
       > : quan::meta::bool_<
         (matrix_col_size<M>::value == matrix_row_size<M>::value)
       >{};

      template <typename M>
      struct matrix_row_size_impl<
         adjunct_view<M> 
         ,typename quan::where_<quan::fun::is_fun_matrix<M> >::type 
      > : std::integral_constant<
         int,(adjunct_view<M>::rows)
      >{};

      template <typename M>
      struct matrix_col_size_impl<
         adjunct_view<M> 
         ,typename quan::where_<quan::fun::is_fun_matrix<M> >::type
      > : std::integral_constant<
         int,(adjunct_view<M>::cols)
      >{};

   }// impl

}} // quan::fun

#endif // QUAN_FUN_ADJUNCT_MATRIX_VIEW_HPP_INCLUDED
