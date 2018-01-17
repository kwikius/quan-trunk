#ifndef QUAN_FUSION_STATIC_VALUE_ADD_SUBTRACT_HPP_INCLUDED
#define QUAN_FUSION_STATIC_VALUE_ADD_SUBTRACT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan/config.hpp>
#include <quan/fusion/static_value/static_val_op_static_val.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/eq.hpp>
#include <quan/where.hpp>

namespace quan{namespace meta{

   //static + runtime type
   template <typename RL, typename SL, typename TR>
   struct binary_op<
      quan::fusion::static_value<RL,SL>, 
      plus, 
      TR,
      typename quan::where_<
         and_<
            not_<quan::fusion::is_static_value<TR> >,
            is_valid_binary_op<RL,plus,TR>
         >
      >::type
   > : binary_op<RL,plus,TR> {};

   //static - runtime type
   template <typename RL, typename SL,typename TR>
   struct binary_op<
      quan::fusion::static_value<RL,SL>, 
      minus, 
      TR,
      typename quan::where_<
         and_<
            not_<quan::fusion::is_static_value<TR> >,
            is_valid_binary_op<RL,minus,TR>
         >
      >::type
   > : binary_op<RL,minus,TR> {};

   //runtime type + static
   template <typename TL, typename RR, typename SR>
   struct binary_op<
      TL,
      plus,
      quan::fusion::static_value<RR,SR>,
      typename quan::where_<
         and_<
            not_<quan::fusion::is_static_value<TL> >,
            is_valid_binary_op<TL,plus,RR>
         >
      >::type
   > : binary_op<TL,plus,RR> {};

   //runtime-type - static
   template <typename TL,typename RR, typename SR>
   struct binary_op<
      TL,
      minus,
      quan::fusion::static_value<RR,SR>,
      typename quan::where_<
         and_<
            not_<quan::fusion::is_static_value<TL> >,
            is_valid_binary_op<TL,minus,RR>
         >
      >::type
   > : binary_op<TL,minus,RR> {};

}}//quan::meta



//#include <boost/preprocessor/cat.hpp>

#define QUAN_FUSION_META_OP quan::meta::plus
#define QUAN_FUSION_RT_OP +

#include "add_subtract_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#define QUAN_FUSION_META_OP quan::meta::minus
#define QUAN_FUSION_RT_OP -

#include "add_subtract_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#endif
