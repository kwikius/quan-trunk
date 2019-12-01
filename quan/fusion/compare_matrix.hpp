#ifndef QUAN_FUSION_COMPARE_MATRIX_HPP1_INCLUDED
#define QUAN_FUSION_COMPARE_MATRIX_HPP1_INCLUDED

#include <quan/fusion/matrix.hpp>
#include <quan/fun/compare_seq_ops.hpp>
#include <quan/are_models_of.hpp>
#include <quan/meta/bool.hpp>
#include  <quan/fun/matrix_as_sequence.hpp>

namespace quan{ namespace fun{

   namespace detail{

      template <typename Lhs, typename Rhs>
      struct matrix_compare_result{
         static_assert(quan::are_models_of<quan::fusion::Matrix_,Lhs,Rhs>::value);
         static_assert(quan::fun::is_fun_matrix<Lhs>::value);
         static_assert(quan::fun::is_fun_matrix<Lhs>::value);
         static_assert(quan::fun::is_fun_matrix<Rhs>::value);

         typedef quan::fun::matrix_as_sequence<Lhs> lhs_seq;
         typedef quan::fun::matrix_as_sequence<Rhs> rhs_seq;

         static_assert(quan::fun::is_fun_sequence<lhs_seq>::value);
         static_assert(quan::fun::is_fun_sequence<rhs_seq>::value);

         typedef typename quan::fun::inner_product_seq::template result<
            lhs_seq, rhs_seq,quan::operator_logical_and, quan::operator_equal_to
         >::type type;

      };
   }

   template <typename LhsM, typename RhsM>
   inline
   constexpr
   typename quan::eval_where<
      quan::meta::and_<
         quan::are_models_of<quan::fusion::Matrix_,LhsM,RhsM>
         ,quan::meta::bool_< (quan::fusion::num_rows<LhsM>  == quan::fusion::num_rows<RhsM>) >
         ,quan::meta::bool_< (quan::fusion::num_columns<LhsM>  == quan::fusion::num_columns<RhsM>) >
      >,
     detail::matrix_compare_result<LhsM,RhsM>
   >::type
   operator == (LhsM const & lhs, RhsM const & rhs)
   {
      static_assert(quan::fun::is_fun_matrix<LhsM>::value);
      static_assert(quan::fun::is_fun_matrix<RhsM>::value);
      auto const lhs_seq = quan::fun::matrix_as_sequence<LhsM>(lhs);
      auto const rhs_seq = quan::fun::matrix_as_sequence<RhsM>(rhs);
      return lhs_seq == rhs_seq;
   }
   
}}

#endif // QUAN_FUSION_COMPARE_MATRIX_HPP_INCLUDED
