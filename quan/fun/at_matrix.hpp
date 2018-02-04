#ifndef QUAN_FUN_AT_MATRIX_HPP_INCLUDED
#define QUAN_FUN_AT_MATRIX_HPP_INCLUDED

#include <quan/fun/access_modifiers.hpp>
#include <quan/where.hpp>
#include <quan/fun/is_fun_matrix.hpp>
#include <quan/meta/bool.hpp>

namespace quan{ namespace fun{
   
    namespace impl{

       template<int R, int C, typename Matrix, typename Access, typename Where = void>
       struct at_matrix_impl;

       template<int R, int C, typename Matrix>
       struct at_matrix_impl<R,C,Matrix, as_ref,
         typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix>
               ,quan::meta::bool_< (R < matrix_row_size<Matrix>::value) >
               ,quan::meta::bool_< (C < matrix_col_size<Matrix>::value) >
            >
         >::type
       >{
           typedef typename Matrix::template type_at<R,C,as_ref>::type type;

           constexpr type operator()( Matrix & m)
           {
               return m. template at<R,C>();
           }
       };

       template<int R, int C, typename Matrix>
       struct at_matrix_impl<R,C,Matrix, as_const_ref,
         typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix>
               ,quan::meta::bool_< (R < matrix_row_size<Matrix>::value) >
               ,quan::meta::bool_< (C < matrix_col_size<Matrix>::value) >
            >
         >::type
       >{

           typedef typename Matrix::template type_at<R,C,as_const_ref>::type type;

           constexpr type operator()( Matrix const & m)
           {
               return m. template at<R,C>();
           }
       };

       template<int R, int C, typename Matrix>
       struct at_matrix_impl<R,C,Matrix, as_value,
         typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_matrix<Matrix>
               ,quan::meta::bool_< (R < matrix_row_size<Matrix>::value) >
               ,quan::meta::bool_< (C < matrix_col_size<Matrix>::value) >
            >
         >::type
       >{

           typedef typename Matrix::template type_at<R,C,as_value>::type type;

           constexpr type operator()( Matrix const & m)
           {
               return m. template at<R,C>();
           }
       };


    }


    template<int R,int C, typename Matrix, typename Access = as_value>
    struct at_matrix : impl::at_matrix_impl<
      R, C,
      typename std::remove_const<
         typename std::remove_reference<Matrix>::type
      >::type,
      Access
    >{};
}};



#endif // QUAN_FUN_AT_MATRIX_HPP_INCLUDED
