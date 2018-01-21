#ifndef QUAN_FUSION_STATIC_VALUE_ADD_SUBTRACT_HPP_INCLUDED
#define QUAN_FUSION_STATIC_VALUE_ADD_SUBTRACT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan/config.hpp>
#include <quan/fusion/static_value/static_val_op_static_val.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/eq.hpp>
#include <quan/where.hpp>

namespace quan{namespace meta{

   
   template <typename R, typename S>
   struct unary_operation<negate,quan::fusion::static_value<R,S> >{
      typedef quan::fusion::static_value<
         R, typename quan::meta::unary_operation<negate,S>::type
      > type;
   };

   namespace impl {
      //static + runtime type
      template <typename RL, typename SL, typename TR>
      struct binary_op_impl<
         quan::fusion::static_value<RL,SL>, 
         quan::meta::plus, 
         TR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::not_<quan::fusion::is_static_value<TR> >,
               quan::meta::is_valid_binary_op<RL,plus,TR>
            >
         >::type
      > : quan::meta::binary_op<RL,plus,TR> {};

      //static - runtime type
      template <typename RL, typename SL,typename TR>
      struct binary_op_impl<
         quan::fusion::static_value<RL,SL>, 
         quan::meta::minus, 
         TR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::not_<quan::fusion::is_static_value<TR> >,
               quan::meta::is_valid_binary_op<RL,minus,TR>
            >
         >::type
      > : quan::meta::binary_op<RL,minus,TR> {};

      //runtime type + static
      template <typename TL, typename RR, typename SR>
      struct binary_op_impl<
         TL,
         quan::meta::plus,
         quan::fusion::static_value<RR,SR>,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::not_<quan::fusion::is_static_value<TL> >,
               quan::meta::is_valid_binary_op<TL,plus,RR>
            >
         >::type
      > : quan::meta::binary_op<TL,plus,RR> {};

      //runtime-type - static
      template <typename TL,typename RR, typename SR>
      struct binary_op_impl<
         TL,
         quan::meta::minus,
         quan::fusion::static_value<RR,SR>,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::not_<quan::fusion::is_static_value<TL> >,
               quan::meta::is_valid_binary_op<TL,minus,RR>
            >
         >::type
      > : quan::meta::binary_op<TL,minus,RR> {};
   }//impl

}}//quan::meta

namespace quan{ namespace fusion{

   template <typename R, typename S>
   inline constexpr
   typename quan::fusion::static_value<R,S> 
   operator + ( quan::fusion::static_value<R,S> const & in)
   {
      return in;
   }

   template <typename R, typename S>
   inline constexpr
   typename quan::meta::unary_operation<
      quan::meta::negate,
      quan::fusion::static_value<R,S> 
   >::type
   operator - ( quan::fusion::static_value<R,S> const & in)
   {
      typedef typename quan::meta::unary_operation<
         quan::meta::negate,
         quan::fusion::static_value<R,S> 
      >::type result_type;

      return result_type{};
   }

}}

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
