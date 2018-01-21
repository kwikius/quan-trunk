#ifndef QUAN_FUSION_STATIC_VALUE_OP_STATIC_VALUE_HPP_INCLUDED
#define QUAN_FUSION_STATIC_VALUE_OP_STATIC_VALUE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_valid_binary_op.hpp>
#include <quan/meta/is_lossless_calculation.hpp>
#include <quan/fusion/static_value/static_value_def.hpp>
//#include <quan/meta/static_numeric_concept.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/identity.hpp>
#include <quan/meta/is_scalar.hpp>
#include <quan/fusion/static_value/static_bool.hpp>
#include <quan/where.hpp>

namespace quan{ namespace meta{

   namespace impl {
      // if calc is lossless, return a static value
      template <
         typename RuntimeType_L,typename StaticValue_L,
         typename Op, 
         typename RuntimeType_R, typename StaticValue_R
      >
      struct binary_op_impl<
         quan::fusion::static_value<RuntimeType_L,StaticValue_L>,
         Op, 
         quan::fusion::static_value<RuntimeType_R,StaticValue_R>,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_lossless_calculation<RuntimeType_L,Op,RuntimeType_R>
               ,quan::meta::is_lossless_calculation<StaticValue_L,Op,StaticValue_R>
               ,quan::meta::or_<
                  quan::meta::is_additive_operator<Op>
                  ,quan::meta::is_multiplicative_operator<Op>
               >
               ,quan::meta::is_valid_binary_op<RuntimeType_L,Op,RuntimeType_R>
            >
         >::type
      > : quan::fusion::static_value<
         typename quan::meta::binary_op<RuntimeType_L,Op,RuntimeType_R>::type, 
         typename quan::meta::binary_op<StaticValue_L,Op,StaticValue_R>::type 
      >{};

      // if not lossless static calc return runtime type
      template <
         typename RuntimeType_L, typename StaticValue_L, 
         typename Op, 
         typename RuntimeType_R, typename StaticValue_R
      >
      struct binary_op_impl<
         quan::fusion::static_value<RuntimeType_L,StaticValue_L>,
         Op, 
         quan::fusion::static_value<RuntimeType_R,StaticValue_R>,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_valid_binary_op<RuntimeType_L,Op,RuntimeType_R>
               ,quan::meta::or_<
                  quan::meta::not_< is_lossless_calculation<RuntimeType_L,Op,RuntimeType_R> >
                  ,quan::meta::not_< is_lossless_calculation<StaticValue_L,Op,StaticValue_R> >
               >
               ,quan::meta::or_<
                  quan::meta::is_additive_operator<Op>
                  ,quan::meta::is_multiplicative_operator<Op>
               >
            >
         >::type
      > : quan::meta::binary_op<RuntimeType_L,Op,RuntimeType_R>{};
   }//impl
}}//quan::meta

#endif
