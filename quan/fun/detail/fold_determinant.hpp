#ifndef QUAN_FUN_DETAIL_FOLD_DETERMINANT_HPP_INCLUDED
#define QUAN_FUN_DETAIL_FOLD_DETERMINANT_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>
#include <quan/fun/is_fun_matrix.hpp>
#include <quan/fun/access_modifiers.hpp>
#include <quan/fun/sub_matrix_view.hpp>
#include <quan/fusion/static_value.hpp>

/*
  see https://www.geeksforgeeks.org/determinant-of-a-matrix/
*/

#if defined (__cpp_decltype_auto) &&  ( (__cpp_decltype_auto) >= 201304)
// for std::declval
#include <utility>
#endif

namespace quan{ namespace fun{

   namespace detail{
      
      template <int N, int Sign, typename Matrix, typename Where = void> 
      struct fold_determinant;

      template <int Sign, typename Matrix>
      struct fold_determinant<0,Sign,Matrix
        , typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix> 
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value == 1)>
               ,quan::meta::bool_<(quan::fun::matrix_col_size<Matrix>::value == 1)>
            >
        >::type
      >{

       #if defined (__cpp_decltype_auto) &&  ( (__cpp_decltype_auto) >= 201304)

         static constexpr auto apply( Matrix const & m)
         {   
             typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;
             return sign_type{} * m. template at<0,0>();
         }

         typedef decltype( fold_determinant::apply(std::declval<Matrix>()) ) type;

       #else // no auto return type

         typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
         typedef typename matrix_type::template type_at<0,0>::type matrix_value_type;
         typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;
         typedef typename quan::meta::binary_op<
            sign_type, 
            quan::meta::times,
            matrix_value_type
         >::type type;

         static_assert( ! std::is_same<
               typename quan::meta::strip_cr<type>::type,quan::undefined
         >::value,"invalid calculation");

         static constexpr type apply( Matrix const & m)
         {
             return sign_type{} * m.template at<0,0>();
         }

       #endif
      };

      template <int Sign,typename Matrix>
      struct fold_determinant<0,Sign,Matrix
        , typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix> 
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value > 1)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value == quan::fun::matrix_col_size<Matrix>::value)>
            >
        >::type
      >{
         typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
         static constexpr int RC = quan::fun::matrix_row_size<matrix_type>::value;
         static constexpr int Iter = (RC-1) ; // note N == 0
         typedef quan::fun::sub_matrix_view<0,Iter,matrix_type> sub_matrix;
         typedef fold_determinant<Iter-1,1,sub_matrix> sub_fold_determinant;

       #if defined (__cpp_decltype_auto) &&  ( (__cpp_decltype_auto) >= 201304)

         template <typename Sum>
         static constexpr 
         auto
         apply(Sum && sum,Matrix const & m)
         {
            typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;

            return sum + sign_type{} * m.template at<0,Iter>() * sub_fold_determinant::apply(sub_matrix{m});
         }

         template <typename Sum>
         struct result{
            typedef decltype ( fold_determinant::apply( std::declval<Sum>(),std::declval<Matrix>()) ) type;
         };

      #else

         typedef typename quan::meta::binary_op<
            typename matrix_type::template type_at<0,Iter>::type, 
            quan::meta::times,
            typename sub_fold_determinant::type
         >::type temp1_type;

         typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;

         typedef typename quan::meta::binary_op<
            sign_type, 
            quan::meta::times,
            temp1_type
         >::type this_sum_type;

         static_assert( ! std::is_same<
            typename quan::meta::strip_cr<this_sum_type>::type,quan::undefined
         >::value,"invalid calculation");

         template <typename Sum>
         struct result{
            typedef typename quan::meta::binary_op<Sum,quan::meta::plus,this_sum_type>::type type;
         };

         template <typename Sum>
         static constexpr 
         typename result<Sum>::type
         apply(Sum && sum,Matrix const & m)
         {
            return sum + sign_type{} * m.template at<0,Iter>() * sub_fold_determinant::apply(sub_matrix{m});
         }
      #endif
      };

      template <int N, int Sign, typename Matrix>
      struct fold_determinant<N,Sign,Matrix
        , typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix>   // its a matrix
               ,quan::meta::bool_<(N > 0)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value > 1)>
               ,quan::meta::bool_<(quan::fun::matrix_row_size<Matrix>::value == quan::fun::matrix_col_size<Matrix>::value)>
            >
        >::type
      >{

         typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
         typedef quan::fun::detail::fold_determinant<
            N-1,-Sign,matrix_type
         > next_fold_determinant_type;
         static constexpr int RC = quan::fun::matrix_row_size<matrix_type>::value;
         static constexpr int Iter = (RC-1) - N;
         typedef quan::fun::sub_matrix_view<0,Iter,matrix_type> sub_matrix;

         typedef fold_determinant<RC-2,1,sub_matrix> sub_fold_determinant;

      #if defined (__cpp_decltype_auto) &&  ( (__cpp_decltype_auto) >= 201304)

         static constexpr 
         auto
         apply(Matrix const& m)
         {   
             typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;
             return next_fold_determinant_type::apply(
              sign_type{} * m. template at<0,Iter>() * sub_fold_determinant::apply(sub_matrix{m})
              ,m
           );
         }

         typedef decltype(fold_determinant::apply(std::declval<Matrix>()) ) type;

         template <typename Sum>
         static constexpr 
         auto 
         apply(Sum && sum,Matrix const& m)
         {   
            return sum + fold_determinant::apply(m);
         }

         template <typename Sum>
         struct result{
            typedef decltype( std::declval<Sum>() + fold_determinant::apply(std::declval<Matrix>()) ) type;
         };

      #else

         typedef typename matrix_type::template type_at<0,Iter>::type matrix_value_type;

         typedef typename quan::meta::binary_op<
            matrix_value_type, quan::meta::times,typename sub_fold_determinant::type
         >::type temp1_type;

         typedef quan::fusion::static_value<int,quan::meta::rational<Sign,1> > sign_type;

         typedef typename quan::meta::binary_op<
            sign_type, 
            quan::meta::times,
            temp1_type
         >::type this_sum_type;

         static_assert( ! std::is_same<
            typename quan::meta::strip_cr<this_sum_type>::type,quan::undefined
         >::value,"invalid calculation");

         typedef typename next_fold_determinant_type:: template result<this_sum_type>::type type;

         template <typename Sum>
         struct result{
            typedef typename quan::meta::binary_op<Sum,quan::meta::plus,typename fold_determinant::type>::type type;
         };

         static constexpr 
         type 
         apply(Matrix const& m)
         {   
           return next_fold_determinant_type::apply(
              sign_type{} * m. template at<0,Iter>() * sub_fold_determinant::apply(sub_matrix{m})
              ,m
           );
         }

         template <typename Sum>
         static constexpr 
         typename result<Sum>::type 
         apply(Sum && sum,Matrix const& m)
         {   
            return sum + fold_determinant::apply(m);
         }

      #endif
      };

   } //detail

}} // quan::fun

#endif // QUAN_FUN_DETAIL_FOLD_DETERMINANT_HPP_INCLUDED
