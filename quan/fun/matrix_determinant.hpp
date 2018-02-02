#ifndef QUAN_FUN_MATRIX_DETERMINANT_HPP_INCLUDED
#define QUAN_FUN_MATRIX_DETERMINANT_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>
#include <quan/fun/is_fun_matrix.hpp>
#include <quan/fun/access_modifiers.hpp>
#include <quan/fun/sub_matrix_view.hpp>
#include <quan/fusion/static_value.hpp>

namespace quan{ namespace fun{

 /* for reference
      template <int N, int Sign>
      struct fold_determinant{

         template <typename T, int RC>
         T operator () ( T sum, quan::test::matrix<T,RC,RC> const & m) const
         {
            static constexpr int iter = (RC-1)-N;
          #if 0
            // for clarity
            sub_matrix_view<T,RC-1,RC-1,0,iter> submatrix(m);
            T temp = sum + Sign * m.at(0,iter) * determinant(submatrix);
            return fold_determinant<N-1,-Sign>{}(temp,m);
          #else
           // for constexpr
           typedef quan::test::sub_matrix_view<T,RC-1,RC-1,0,iter> submatrix;
           return quan::test::detail::fold_determinant<N-1,-Sign>{}(
              sum + Sign * m.at(0,iter) * quan::test::determinant(submatrix{m})
              ,m
           );
          #endif
         }
      };

      template <int Sign>
      struct fold_determinant<0, Sign>
      {
         t
         template <typename T, int RC>
         T operator () ( T sum, quan::test::matrix<T,RC,RC> const & m) const
         {
            static constexpr int iter = (RC-1);
            typedef quan::test::sub_matrix_view<T,RC-1,RC-1,0,iter> submatrix;
            return sum + Sign * m.at(0,iter) * quan::test::determinant(submatrix{m});
         }
      };
  */

   namespace detail{
      
      template <int N, int Sign, typename Sum , typename Matrix, typename Where = void> 
      struct fold_determinant;
//{
//         static_assert(false, "bad");
//         typedef quan::undefined type;
//      };

      template <int N, int Sign, typename Sum, typename Matrix>
      struct fold_determinant<N,Sign,Sum,Matrix
        , typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix>   // its a matrix
               ,quan::meta::bool_<(N == 0)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value == 1)>
               ,quan::meta::bool_<(quan::fun::matrix_col_size<Matrix>::value == 1)>
            >
        >::type
      >{
         typedef typename quan::meta::strip_cr<Sum>::type sum_type;
         typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
         typedef typename matrix_type::template type_at<0,0>::type matrix_value_type;
         typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;
         typedef typename quan::meta::binary_op<
            sign_type, 
            quan::meta::times,
            matrix_value_type
         >::type temp1_type;
         typedef typename quan::meta::binary_op<
           Sum , quan::meta::plus,temp1_type
         >::type type;

         static type apply( Sum const & sum,Matrix const & m)
         {
             return sum + sign_type{} * m. template at<0,0>();
         }
      };

      template <int N, int Sign, typename Sum, typename Matrix>
      struct fold_determinant<N,Sign,Sum,Matrix
        , typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix>   // its a matrix
               ,quan::meta::bool_<(N == 0)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value > 1)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value == quan::fun::matrix_col_size<Matrix>::value)>
            >
        >::type
      >{
         typedef typename quan::meta::strip_cr<Sum>::type sum_type;
         typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
         static constexpr int RC = quan::fun::matrix_row_size<matrix_type>::value;
         static constexpr int Iter = (RC-1) - N; // note N == 0
         typedef quan::fun::sub_matrix_view<0,Iter,matrix_type> sub_matrix_type;
         static constexpr int matrix_sub_type_RC = quan::fun::matrix_row_size<sub_matrix_type>::value; // should be RC-1
         typedef quan::fusion::static_value<int,quan::meta::rational<0,1> > zero_type;
         typedef fold_determinant<matrix_sub_type_RC-1,1,zero_type,sub_matrix_type> sub_fold_determinant;
         typedef typename sub_fold_determinant::type sub_determinant_type;
         typedef typename matrix_type::template type_at<0,Iter>::type matrix_value_type;

         typedef typename quan::meta::binary_op<
            matrix_value_type, quan::meta::times,sub_determinant_type
         >::type temp1_type;

         typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;
        // typedef quan::fusion::static_value<int,quan::meta::rational<0,1> > zero_type;
         typedef typename quan::meta::binary_op<
            sign_type, 
            quan::meta::times,
            temp1_type
         >::type temp2_type;
         typedef typename quan::meta::binary_op<
           Sum , quan::meta::plus,temp2_type
         >::type type;

         static type apply(Sum const & sum,Matrix const & m)
         {
            return sum + sign_type{} * m. template at<0,Iter>() * sub_fold_determinant::apply(zero_type{},sub_matrix_type{m});
         }
      };

      template <int N, int Sign, typename Sum, typename Matrix>
      struct fold_determinant<N,Sign,Sum,Matrix
        , typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix>   // its a matrix
               ,quan::meta::bool_<(N > 0)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value > 1)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value == quan::fun::matrix_col_size<Matrix>::value)>
            >
        >::type
      >{
         typedef typename quan::meta::strip_cr<Sum>::type sum_type;
         typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
         static constexpr int RC = quan::fun::matrix_row_size<matrix_type>::value;
         static constexpr int Iter = (RC-1) - N;
         typedef quan::fun::sub_matrix_view<0,Iter,matrix_type> sub_matrix_type;
         static constexpr int matrix_sub_type_RC = quan::fun::matrix_row_size<sub_matrix_type>::value; // should be RC-1
         static_assert(quan::fun::is_fun_matrix<sub_matrix_type>::value,"odd1");
         static_assert(matrix_sub_type_RC > 0, "odd");
         typedef quan::fusion::static_value<int,quan::meta::rational<0,1> > zero_type;
         typedef fold_determinant<matrix_sub_type_RC-1,1,zero_type,sub_matrix_type> sub_fold_determinant;
         typedef typename matrix_type::template type_at<0,Iter>::type matrix_value_type;

         typedef typename quan::meta::binary_op<
            matrix_value_type, quan::meta::times,typename sub_fold_determinant::type
         >::type temp1_type;

         typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;

         typedef typename quan::meta::binary_op<
            sign_type, 
            quan::meta::times,
            temp1_type
         >::type temp2_type;
         typedef typename quan::meta::binary_op<
            sum_type , quan::meta::plus,temp2_type
         >::type temp3_type;
         typedef quan::fun::detail::fold_determinant<
            N-1,-Sign,temp3_type,matrix_type
         > next_fold_determinant_type;

         typedef typename next_fold_determinant_type::type type;

         static type apply(Sum const & sum,Matrix const & m)
         {   
           return next_fold_determinant_type::apply(
              sum + sign_type{} * m. template at<0,Iter>() * sub_fold_determinant::apply(zero_type{},sub_matrix_type{m})
              ,m
           );
         }
      };
   }

   template <typename M, typename Where = void>
   struct make_determinant;

   template <
      typename M 
   >
   struct make_determinant<
      M
     ,typename quan::where_<
         quan::meta::and_<
             quan::fun::is_fun_matrix<M>
            ,quan::meta::bool_<(quan::fun::matrix_col_size<M>::value == quan::fun::matrix_row_size<M>::value)>
         >
      >::type
   >{
      typedef typename quan::meta::strip_cr<M>::type matrix_type;
      typedef quan::fusion::static_value<int,quan::meta::rational<0,1> > zero_type;
      typedef quan::fun::detail::fold_determinant<
         quan::fun::matrix_row_size<M>::value-1  // iter
         ,1     // sign
         ,zero_type  // partial sum
         ,matrix_type // matrix type
      > fold_determinant_type;

      typedef typename fold_determinant_type::type type;

      type operator() ( M const & m)const
      {
         return fold_determinant_type::apply(zero_type{}, m);
      }
   };

   namespace detail{


  //    template <int Sign> 
   //   struct fold_determinant<0,Sign>;
 // }// detail



     /* for reference
      template <int N, int Sign>
      struct fold_determinant{

         template <typename T, int RC>
         T operator () ( T sum, quan::test::matrix<T,RC,RC> const & m) const
         {
            static constexpr int iter = (RC-1)-N;
          #if 0
            // for clarity
            sub_matrix_view<T,RC-1,RC-1,0,iter> submatrix(m);
            T temp = sum + Sign * m.at(0,iter) * determinant(submatrix);
            return fold_determinant<N-1,-Sign>{}(temp,m);
          #else
           // for constexpr
           typedef quan::test::sub_matrix_view<T,RC-1,RC-1,0,iter> submatrix;
           return quan::test::detail::fold_determinant<N-1,-Sign>{}(
              sum + Sign * m.at(0,iter) * quan::test::determinant(submatrix{m})
              ,m
           );
          #endif
         }
      };
      */
  // namespace detail{




     

   } // detail



   
   /*
      template <typename T,int RC>
      inline
      typename quan::where_c<(RC > 1),T >::type
      determinant(matrix<T,RC,RC> const & m)
      {
         return detail::fold_determinant<RC-1,1>{}(T{},m);
   }
   */

}}

#endif // QUAN_FUN_MATRIX_DETERMINANT_HPP_INCLUDED
