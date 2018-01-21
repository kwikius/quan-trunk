#ifndef QUAN_FUSION_STATIC_VALUE_COMPARE_HPP_INCLUDED
#define  QUAN_FUSION_STATIC_VALUE_COMPARE_HPP_INCLUDED

#include <quan/fusion/static_value/static_value_def.hpp>
#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/fusion/static_value/static_bool.hpp>

namespace quan{ namespace meta{

   namespace impl {
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
               quan::meta::is_valid_binary_op<RuntimeType_L,quan::meta::minus,RuntimeType_R>
               ,quan::meta::or_<
                  quan::meta::is_logical_operator<Op>
                  ,quan::meta::is_relational_operator<Op>
                  ,quan::meta::is_equality_operator<Op>
               >
               ,quan::meta::is_lossless_calculation<RuntimeType_L,quan::meta::minus,RuntimeType_R>
               ,quan::meta::is_lossless_calculation<StaticValue_L,quan::meta::minus,StaticValue_R>
            >  
         >::type
      >: quan::fusion::static_bool<
            (quan::meta::binary_op<StaticValue_L,Op,StaticValue_R>::type::value)
      >{};
   }//impl
}}

#define QUAN_FUSION_META_OP quan::meta::less
#define QUAN_FUSION_RT_OP <

#include "compare_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#define QUAN_FUSION_META_OP quan::meta::less_equal
#define QUAN_FUSION_RT_OP <=

#include "compare_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#define QUAN_FUSION_META_OP quan::meta::equal_to
#define QUAN_FUSION_RT_OP ==

#include "compare_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#define QUAN_FUSION_META_OP quan::meta::not_equal_to
#define QUAN_FUSION_RT_OP !=

#include "compare_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#define QUAN_FUSION_META_OP quan::meta::greater_equal
#define QUAN_FUSION_RT_OP >=

#include "compare_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#define QUAN_FUSION_META_OP quan::meta::greater
#define QUAN_FUSION_RT_OP >

#include "compare_i.hpp"

#undef QUAN_FUSION_META_OP
#undef QUAN_FUSION_RT_OP

#endif
