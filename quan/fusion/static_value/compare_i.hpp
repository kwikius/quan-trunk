//meant for multiple inclusion

#include <quan/fusion/static_value/static_value_def.hpp>
#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/fusion/static_value/static_bool.hpp>


namespace quan{ namespace fusion{

   // n.b compare only defined for same unit static value types
   template <typename RL, typename SL, typename RR, typename SR>
   inline
   constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::meta::is_valid_binary_op<
            RL,
            quan::meta::minus,
            RR
         >
         ,quan::meta::is_lossless_calculation<RL,quan::meta::minus,RR>
         ,quan::meta::is_lossless_calculation<SL,quan::meta::minus,SR>
      >
      ,typename  quan::meta::binary_op<
         quan::fusion::static_value<RL,SL>,
         QUAN_FUSION_META_OP, 
         quan::fusion::static_value<RR,SR>
      >::type
   >::type
   operator QUAN_FUSION_RT_OP (
         quan::fusion::static_value<RL,SL> const &,
         quan::fusion::static_value<RR,SR> const &
   ){
      typedef typename quan::meta::binary_op<
         quan::fusion::static_value<RL,SL>,
         QUAN_FUSION_META_OP, 
         quan::fusion::static_value<RR,SR>
      >::type result_type;
      return result_type();
   }

   template <typename TL, typename RR, typename SR>
   inline
   constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TL> >,
         quan::meta::is_valid_binary_op<
            TL,quan::meta::minus,RR
         >
      >,
      bool
   >::type
   operator QUAN_FUSION_RT_OP  (TL const & lhs ,quan::fusion::static_value<RR,SR> const & rhs)
   {
      return lhs QUAN_FUSION_RT_OP to_runtime{}(rhs);
   }

   template <typename RL, typename SL, typename TR >
   inline
   constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TR> >,
         quan::meta::is_valid_binary_op<
            RL,quan::meta::minus,TR
         >
      >,
      bool
   >::type
   operator QUAN_FUSION_RT_OP  (quan::fusion::static_value<RL,SL> const & lhs, TR const & rhs)
   {
      return to_runtime{}(lhs) QUAN_FUSION_RT_OP rhs;
   }

}}//quan::fusion

