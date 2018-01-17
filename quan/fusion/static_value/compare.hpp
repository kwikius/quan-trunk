#ifndef QUAN_FUSION_STATIC_VALUE_COMPARE_HPP_INCLUDED
#define  QUAN_FUSION_STATIC_VALUE_COMPARE_HPP_INCLUDED

#include <quan/fusion/static_value/static_value_def.hpp>
#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/fusion/static_value/static_bool.hpp>

namespace quan{ namespace meta{

   template <
      typename RuntimeType_L, typename StaticValue_L, 
      typename RuntimeType_R, typename StaticValue_R
   >
   struct binary_op<
      quan::fusion::static_value<RuntimeType_L,StaticValue_L>,
      equal_to, 
      quan::fusion::static_value<RuntimeType_R,StaticValue_R>,
      typename quan::where_<
         is_valid_binary_op<RuntimeType_L,minus,RuntimeType_R>
      >::type
   >: quan::fusion::static_bool<
         (eq_<StaticValue_L,StaticValue_R>::type::value)
   >{};

   template <
      typename RuntimeType_L, typename StaticValue_L, 
      typename RuntimeType_R, typename StaticValue_R
   >
   struct binary_op<
      quan::fusion::static_value<RuntimeType_L,StaticValue_L>,
      not_equal_to, 
      quan::fusion::static_value<RuntimeType_R,StaticValue_R>,
      typename quan::where_<
         is_valid_binary_op<RuntimeType_L,minus,RuntimeType_R>
      >::type
   >: quan::fusion::static_bool<
         (neq_<StaticValue_L,StaticValue_R>::type::value)
   >{};
     
}}

namespace quan{ namespace fusion{

   template <typename RL, typename SL, typename RR, typename SR>
   inline
   typename quan::where_<
      quan::meta::is_valid_binary_op<
         RL,
         quan::meta::minus,
         RR
      >,
      typename  quan::meta::binary_op<
         quan::fusion::static_value<RL,SL>,
         quan::meta::equal_to, 
         quan::fusion::static_value<RR,SR>
      >::type
   >::type
   operator == (
         quan::fusion::static_value<RL,SL> const &,
         quan::fusion::static_value<RR,SR> const &
   ){
      typedef typename quan::meta::binary_op<
         quan::fusion::static_value<RL,SL>,
         quan::meta::equal_to, 
         quan::fusion::static_value<RR,SR>
      >::type result_type;
      return result_type();
   }

   template <typename TL, typename RR, typename SR>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TL> >,
         quan::meta::is_valid_binary_op<
            TL,quan::meta::minus,RR
         >
      >,
      bool
   >::type
   operator == (TL const & lhs ,quan::fusion::static_value<RR,SR> const &)
   {
      return lhs == quan::fusion::static_value<RR,SR>::to_runtime();
   }
   
   template <typename RL, typename SL, typename TR >
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TR> >,
         quan::meta::is_valid_binary_op<
            RL,quan::meta::minus,TR
         >
      >,
      bool
   >::type
   operator == (quan::fusion::static_value<RL,SL> const &, TR const & rhs)
   {
      return quan::fusion::static_value<RL,SL>::to_runtime() == rhs;
   }

   template <typename RL, typename SL, typename RR, typename SR>
   inline
   typename quan::where_<
      quan::meta::is_valid_binary_op<
         RL,
         quan::meta::minus,
         RR
      >,
      typename  quan::meta::binary_op<
         quan::fusion::static_value<RL,SL>,
         quan::meta::not_equal_to, 
         quan::fusion::static_value<RR,SR>
      >::type
   >::type
   operator != (
         quan::fusion::static_value<RL,SL> const &,
         quan::fusion::static_value<RR,SR> const &
   ){
      typedef typename quan::meta::binary_op<
         quan::fusion::static_value<RL,SL>,
         quan::meta::not_equal_to, 
         quan::fusion::static_value<RR,SR>
      >::type result_type;
      return result_type();
   }

   template <typename TL, typename RR, typename SR>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TL> >,
         quan::meta::is_valid_binary_op<
            TL,quan::meta::minus,RR
         >
      >,
      bool
   >::type
   operator != (TL const & lhs ,quan::fusion::static_value<RR,SR> const &)
   {
      return lhs != quan::fusion::static_value<RR,SR>::to_runtime();
   }
   
   template <typename RL, typename SL, typename TR >
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TR> >,
         quan::meta::is_valid_binary_op<
            RL,quan::meta::minus,TR
         >
      >,
      bool
   >::type
   operator != (quan::fusion::static_value<RL,SL> const &, TR const & rhs)
   {
      return quan::fusion::static_value<RL,SL>::to_runtime() != rhs;
   }

   
}}//quan::fusion


#endif
