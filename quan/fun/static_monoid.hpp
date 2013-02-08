#ifndef QUAN_FUN_STATIC_MONOID_HPP_INCLUDED
#define QUAN_FUN_STATIC_MONOID_HPP_INCLUDED

#include <quan/meta/rational.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fusion/static_value/static_value.hpp>

namespace quan{ namespace fun{

      template <typename F, typename T, typename Enable = void>
      struct static_monoid;

//plus
      template <typename T>
      struct static_monoid<
         quan::operator_plus,T,
         typename quan::where_<
            quan::meta::is_valid_binary_op<T,quan::meta::plus,T>
         >::type
      > : quan::fusion::static_value<
         typename quan::fusion::to_runtime::template result<T>::type,
         quan::meta::rational<0>
      > {};

      template <typename T>
      struct static_monoid<
         quan::operator_minus,T,
         typename quan::where_<
            quan::meta::is_valid_binary_op<T,quan::meta::minus,T>
         >::type
      > : quan::fusion::static_value<
         typename quan::fusion::to_runtime::template result<T>::type,
         quan::meta::rational<0>
      > {};

      template <>
      struct static_monoid<
         quan::operator_logical_or,bool
      > : quan::fusion::static_bool<false>{};

      template <bool B>
      struct static_monoid<
         quan::operator_logical_or,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<false> {};

      template <>
      struct static_monoid<
         quan::operator_bit_or,bool
      > : quan::fusion::static_bool<false>{};

      template <bool B>
      struct static_monoid<
         quan::operator_bit_or,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<false> {};

      template <typename T>
      struct static_monoid<
         quan::operator_times,T,
         typename quan::where_<
            quan::meta::is_valid_binary_op<T,quan::meta::times,int>
         >::type
      > : quan::fusion::static_value<int,quan::meta::rational<1> >{};

      template <>
      struct static_monoid<
         quan::operator_logical_and,bool
      > : quan::fusion::static_bool<true>{};

      template <bool B>
      struct static_monoid<
         quan::operator_logical_and,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<true> {};

      template <>
      struct static_monoid<
         quan::operator_bit_and,bool
      > : quan::fusion::static_bool<true>{};

      template <bool B>
      struct static_monoid<
         quan::operator_bit_and,quan::fusion::static_bool<B>
      > : quan::fusion::static_bool<true> {};
}}

#endif
