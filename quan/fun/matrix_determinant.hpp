#ifndef QUAN_FUN_MATRIX_DETERMINANT_HPP_INCLUDED
#define QUAN_FUN_MATRIX_DETERMINANT_HPP_INCLUDED

#include <quan/fun/detail/fold_determinant.hpp>

namespace quan{ namespace fun{

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
    #if (defined (__cpp_decltype_auto)) &&  ( (__cpp_decltype_auto) >= 201304) && (! defined __MBED__ )

      constexpr auto operator()( M const & m)const
      {
         typedef typename quan::meta::strip_cr<M>::type matrix_type;
         typedef quan::fun::detail::fold_determinant<
            quan::fun::matrix_row_size<matrix_type>::value-1  // iter
            ,1     // sign
            ,matrix_type // matrix type
         > fold_determinant_type;
         return fold_determinant_type::apply(m);
      }

      typedef decltype( std::declval<make_determinant>()(std::declval<M>())) type;

    #else

      typedef typename quan::meta::strip_cr<M>::type matrix_type;
     // typedef quan::fusion::static_value<int,quan::meta::rational<0,1> > zero_type;
      typedef quan::fun::detail::fold_determinant<
         quan::fun::matrix_row_size<matrix_type>::value-1  // iter
         ,1     // sign
         ,matrix_type // matrix type
      > fold_determinant_type;

      typedef typename fold_determinant_type::type type;

      constexpr type operator()( M const & m)const
      {
         return fold_determinant_type::apply( m);
      }

    #endif
   };

}} // quan::fun

#endif // QUAN_FUN_MATRIX_DETERMINANT_HPP_INCLUDED
