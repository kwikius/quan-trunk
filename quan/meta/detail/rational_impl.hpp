
#ifndef QUAN_META_DETAIL_RATIONAL_IMPL_HPP_INCLUDED
#define QUAN_META_DETAIL_RATIONAL_IMPL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

#include <quan/config.hpp>
#include <quan/meta/gcd.hpp>

namespace quan{namespace meta{namespace detail{

   template<
      QUAN_INT32 N,
      QUAN_INT32 D 
   >
   struct rational_impl {

      static const QUAN_INT32 pos_nume_in = (N >= 0) ? N : -N;
      static const QUAN_INT32 pos_denom_in = (D >= 0) ? D : -D;

      typedef quan::meta::gcd<QUAN_INT32,pos_nume_in,pos_denom_in> gcd_type;

      static const QUAN_INT32 gcd_ = (gcd_type::value);
      static const QUAN_INT32 n_sign = (N >= 0)? 1 :-1;
      static const QUAN_INT32 d_sign = (D >= 0)? 1 :-1;
      static const QUAN_INT32 nume_in 
         = ((n_sign * d_sign) > 0)? pos_nume_in : -pos_nume_in;

      static const QUAN_INT32 numerator = static_cast<QUAN_INT32>(nume_in) / gcd_;
      static const QUAN_INT32 denominator = static_cast<QUAN_INT32>(pos_denom_in) / gcd_;

      typedef rational_impl<numerator,denominator> type;
   };

}}}//quan::meta::detail

#endif
