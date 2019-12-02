#ifndef QUAN_FUSION_COMPARE_MATRIX_HPP1_INCLUDED
#define QUAN_FUSION_COMPARE_MATRIX_HPP1_INCLUDED

#include <quan/meta/binary_op.hpp>
#include <quan/meta/strip_cr.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/compare_seq_ops.hpp>
#include <quan/are_models_of.hpp>
#include <quan/meta/bool.hpp>
#include  <quan/fun/matrix_as_sequence.hpp>

namespace quan{ namespace fun{

   namespace detail{

      template <typename Lhs, typename Rhs>
      struct matrix_compare_equal_to_result{
         typedef quan::fun::matrix_as_sequence<Lhs> lhs_seq;
         typedef quan::fun::matrix_as_sequence<Rhs> rhs_seq;
         typedef typename quan::fun::inner_product_seq::template result<
            lhs_seq, rhs_seq,quan::operator_logical_and, quan::operator_equal_to
         >::type type;
      };

      template <typename Lhs, typename Rhs>
      struct matrix_compare_not_equal_to_result{
         typedef quan::fun::matrix_as_sequence<Lhs> lhs_seq;
         typedef quan::fun::matrix_as_sequence<Rhs> rhs_seq;
         typedef typename quan::fun::inner_product_seq::template result<
            lhs_seq, rhs_seq,quan::operator_logical_or, quan::operator_not_equal_to
         >::type type;
      };
   }

}}// quan::fun 

namespace quan{ namespace meta { namespace impl{

   template <typename Lhs, typename Rhs>
   struct binary_op_impl<
      Lhs, quan::meta::equal_to,Rhs,
      typename quan::where_<
         quan::meta::and_<
            quan::are_models_of<quan::fusion::Matrix_,Lhs,Rhs>
            ,quan::meta::bool_< (quan::fusion::num_rows<Lhs>  == quan::fusion::num_rows<Rhs>) >
            ,quan::meta::bool_< (quan::fusion::num_columns<Lhs>  == quan::fusion::num_columns<Rhs>) >
         >
      >::type
   > : quan::fun::detail::matrix_compare_equal_to_result<Lhs,Rhs>{};

   template <typename Lhs, typename Rhs>
   struct binary_op_impl<
      Lhs, quan::meta::not_equal_to,Rhs,
      typename quan::where_<
         quan::meta::and_<
            quan::are_models_of<quan::fusion::Matrix_,Lhs,Rhs>
            ,quan::meta::bool_< (quan::fusion::num_rows<Lhs>  == quan::fusion::num_rows<Rhs>) >
            ,quan::meta::bool_< (quan::fusion::num_columns<Lhs>  == quan::fusion::num_columns<Rhs>) >
         >
      >::type
   > : quan::fun::detail::matrix_compare_not_equal_to_result<Lhs,Rhs>{};

}}} // quan::meta::impl

namespace quan { namespace fun{

#if defined __cpp_concepts

#if 1

   template <fusion::Matrix Lhs, fusion::Matrix Rhs>
   requires (quan::fusion::num_rows<Lhs> == quan::fusion::num_rows<Rhs>) &&
            (quan::fusion::num_columns<Lhs>  == quan::fusion::num_columns<Rhs>)
   inline constexpr 
   auto operator == (Lhs const & lhs, Rhs const & rhs)
   {
      return quan::fusion::as_sequence(lhs) == quan::fusion::as_sequence(rhs);
   }

#else
   // This breaks in gcc-7 with c++14,c++17
   // ok in gcc-9 with c++14
   // remember that concepts were non-standard in gcc-7
   // but are likely to be closer to standard in gcc-9
   inline constexpr 
   auto operator == (fusion::Matrix const & lhs, fusion::Matrix const & rhs)
      requires (
         (quan::fusion::num_rows<decltype(lhs)> == quan::fusion::num_rows<decltype(rhs)>) &&
            (quan::fusion::num_columns<decltype(lhs)>  == quan::fusion::num_columns<decltype(rhs)>)
      )
   {
      return quan::fusion::as_sequence(lhs) == quan::fusion::as_sequence(rhs);
   }

#endif

#else
// not concepts
   template <typename Lhs, typename Rhs>
   inline
   constexpr
   typename quan::eval_where<
      quan::meta::and_<
         quan::are_models_of<quan::fusion::Matrix_,Lhs,Rhs>
         ,quan::meta::bool_< (quan::fusion::num_rows<Lhs>  == quan::fusion::num_rows<Rhs>) >
         ,quan::meta::bool_< (quan::fusion::num_columns<Lhs>  == quan::fusion::num_columns<Rhs>) >
      >,
      quan::meta::binary_op<Lhs,quan::meta::equal_to,Rhs>
   >::type
   operator == (Lhs const & lhs, Rhs const & rhs)
   {
      return quan::fusion::as_sequence(lhs) == quan::fusion::as_sequence(rhs);
   }

#endif

#if defined __cpp_concepts
   template <fusion::Matrix Lhs, fusion::Matrix Rhs>
   requires (quan::fusion::num_rows<Lhs> == quan::fusion::num_rows<Rhs>) &&
            (quan::fusion::num_columns<Lhs>  == quan::fusion::num_columns<Rhs>)
   inline constexpr 
   auto operator != (Lhs const & lhs, Rhs const & rhs) 
   {
      return quan::fusion::as_sequence(lhs) != quan::fusion::as_sequence(rhs);
   }

#else

   template <typename Lhs, typename Rhs>
   inline
   constexpr
   typename quan::eval_where<
      quan::meta::and_<
         quan::are_models_of<quan::fusion::Matrix_,Lhs,Rhs>
         ,quan::meta::bool_< (quan::fusion::num_rows<Lhs>  == quan::fusion::num_rows<Rhs>) >
         ,quan::meta::bool_< (quan::fusion::num_columns<Lhs>  == quan::fusion::num_columns<Rhs>) >
      >,
      quan::meta::binary_op<Lhs,quan::meta::equal_to,Rhs>
   >::type
   operator != (Lhs const & lhs, Rhs const & rhs)
   {
      return quan::fun::matrix_as_sequence<Lhs>(lhs) != quan::fun::matrix_as_sequence<Rhs>(rhs);
   }

#endif
   
}} // quan::fun

#endif // QUAN_FUSION_COMPARE_MATRIX_HPP_INCLUDED
