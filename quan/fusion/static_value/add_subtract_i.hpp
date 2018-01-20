
//meant for multiple inclusion

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.


namespace quan{namespace fusion{ 

  /*
     sv op sv lossless
     sv op sv lossy
     non_zero sv op rv 
     zero sv op rv
     rv op non zero sv
     rv op zero sv
*/


   // runtime version returning static value
   // sv op sv lossles
   template <typename RL, typename SL, typename RR, typename SR>
   inline constexpr 
   typename quan::where_<
      quan::meta::and_<
         quan::meta::is_valid_binary_op<RL,QUAN_FUSION_META_OP,RR>
         ,quan::meta::is_lossless_calculation<RL,QUAN_FUSION_META_OP,RR>
         ,quan::meta::is_lossless_calculation<SL,QUAN_FUSION_META_OP,SR>
      >,
      typename quan::meta::binary_op<
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
      return result_type{};
   }

   // sv op sv lossy
   template <typename RL, typename SL, typename RR, typename SR>
   inline constexpr
   typename quan::where_not<
      quan::meta::or_<
         quan::meta::and_<
            quan::meta::is_lossless_calculation<RL,QUAN_FUSION_META_OP,RR>,
            quan::meta::is_lossless_calculation<SL,QUAN_FUSION_META_OP,SR>
         >,
         quan::meta::not_<
            quan::meta::is_valid_binary_op<RL,QUAN_FUSION_META_OP,RR>
         >
      >,
      typename quan::meta::binary_op<
         quan::fusion::static_value<RL,SL>,
         QUAN_FUSION_META_OP,
         quan::fusion::static_value<RR,SR>
      >::type
   >::type
   operator QUAN_FUSION_RT_OP (
      quan::fusion::static_value<RL,SL> const & lhs,
      quan::fusion::static_value<RR,SR> const & rhs
   ){
      //typedef quan::fusion::static_value<RL,SL> lhs_type;
     // typedef quan::fusion::static_value<RR,SR> rhs_type;
      return to_runtime{}(lhs) QUAN_FUSION_RT_OP to_runtime{}(rhs);
   }
   // could add extra constraint for zero static unit here
   template <typename RL, typename SL, typename TR>
   inline constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TR> >,
         quan::meta::is_valid_binary_op<RL, QUAN_FUSION_META_OP ,TR>,
         quan::meta::neq_zero<SL>
      >,
      typename quan::meta::binary_op<
            quan::fusion::static_value<RL,SL>, QUAN_FUSION_META_OP, TR
      >::type
   >::type
   operator QUAN_FUSION_RT_OP (
      quan::fusion::static_value<RL,SL> const & lhs,
      TR const & rhs
   ){
     // typedef quan::fusion::static_value<RL,SL> s_val;
      return to_runtime{}(lhs) QUAN_FUSION_RT_OP rhs;
   }

   template <typename RL, typename SL, typename TR>
   inline constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TR> >,
         quan::meta::is_valid_binary_op<RL, QUAN_FUSION_META_OP ,TR>,
         quan::meta::eq_zero<SL>
      >,
      typename quan::meta::binary_op<
            quan::fusion::static_value<RL,SL>, QUAN_FUSION_META_OP, TR
      >::type
   >::type
   operator QUAN_FUSION_RT_OP (
      quan::fusion::static_value<RL,SL> const &,
      TR const & rhs
   ){
      return rhs;
   }

   template <typename TL,typename RR, typename SR>
   inline constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TL> >,
         quan::meta::is_valid_binary_op<TL, QUAN_FUSION_META_OP ,RR>,
         quan::meta::neq_zero<SR>
      >,
      typename quan::meta::binary_op<
            TL, QUAN_FUSION_META_OP,  quan::fusion::static_value<RR,SR>
      >::type
   >::type
   operator QUAN_FUSION_RT_OP (
      TL const & lhs,
      quan::fusion::static_value<RR,SR> const &  rhs          
   ){
     // typedef quan::fusion::static_value<RR,SR> s_val;
      return lhs QUAN_FUSION_RT_OP to_runtime{}(rhs);
   }

   template <typename TL,typename RR, typename SR>
   inline constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::meta::not_<quan::fusion::is_static_value<TL> >,
         quan::meta::is_valid_binary_op<TL, QUAN_FUSION_META_OP ,RR>,
         quan::meta::eq_zero<SR>
      >,
      typename quan::meta::binary_op<
            TL, QUAN_FUSION_META_OP,  quan::fusion::static_value<RR,SR>
      >::type
   >::type
   operator QUAN_FUSION_RT_OP (
      TL const & lhs,
      quan::fusion::static_value<RR,SR>  const &          
   ){
      return lhs;
   }
        
}}//quan::fusion


// meant for multiple inclusion
