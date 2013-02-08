#ifndef QUAN_FUN_ASSIGN_SEQ_OPS_HPP_INCLUDED
#define QUAN_FUN_ASSIGN_SEQ_OPS_HPP_INCLUDED

#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/are_fun_sequences.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/is_scalar.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/sequence_assign_op.hpp>
#include <quan/where.hpp>
#include <quan/fun/for_each.hpp>
#include <quan/fun/partial_binary.hpp>
#include <quan/fun/same_size_seq.hpp>

namespace quan{ namespace fun{

   template <typename Lhs, typename Rhs>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_sequences<Lhs,Rhs>,
         quan::fun::same_size_seq<Lhs,Rhs>
      >,
      Lhs &
   >::type
   operator +=( Lhs & lhs, Rhs const & rhs)
   {
         quan::fun::sequence_assign_op<
            (quan::fun::size_seq<Lhs>::value -1),
            quan::operator_plus_equals
         > ass;
         ass(lhs,rhs);
         return lhs;
   }

   template <typename Lhs, typename Rhs>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_sequences<Lhs,Rhs>,
         quan::fun::same_size_seq<Lhs,Rhs>
      >,
      Lhs &
   >::type
   operator -=( Lhs & lhs, Rhs const & rhs)
   {
         quan::fun::sequence_assign_op<
            quan::fun::size_seq<Lhs>::value -1,
            quan::operator_minus_equals
         > ass;
         ass(lhs,rhs);
         return lhs;
   }

   template <typename Lhs , typename Rhs>
   typename quan::where_<
      quan::meta::and_<
         quan::fun::is_fun_sequence<Lhs>,
         quan::meta::is_numeric<Rhs>
      >,
      Lhs &
   >::type
   operator *=(Lhs & lhs, Rhs const & rhs)
   {
      quan::fun::binary_op<_,operator_times_equals,Rhs> f(rhs);
      quan::fun::for_each(lhs,f);
      return lhs;
   }

   template <typename Lhs , typename Rhs>
   typename quan::where_<
      quan::meta::and_<
         quan::fun::is_fun_sequence<Lhs>,
         quan::meta::is_numeric<Rhs>
      >,
      Lhs &
   >::type
   operator /=(Lhs & lhs, Rhs const & rhs)
   {
      quan::fun::binary_op<_,operator_divide_equals,Rhs> f(rhs);
      quan::fun::for_each(lhs,f);
      return lhs;
   }

}}//quan::fun

#endif
