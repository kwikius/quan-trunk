#ifndef QUAN_FUSION_STATIC_VALUE_MULTIPLY_HPP_INCLUDED
#define QUAN_FUSION_STATIC_VALUE_MULTIPLY_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
/// Copyright Andrew Little 2005 - 2018

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/is_scalar.hpp>
#include <quan/fusion/static_value/static_val_op_static_val.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/not.hpp>
#include <quan/where.hpp>

namespace quan{ namespace meta{

      namespace impl {
      // non-zero * runtime type
         template <typename RL,typename SL, typename TR>
         struct binary_op_impl<
            quan::fusion::static_value<RL,SL>,
            quan::meta::times,
            TR,
            typename quan::where_<
               quan::meta::and_<
                  quan::meta::neq_zero<SL>,
                  quan::meta::not_<quan::fusion::is_static_value<TR> >,
                  quan::meta::is_valid_binary_op<RL,times,TR>,
                  quan::meta::is_scalar<TR>
               >
            >::type
         > : quan::meta::binary_op< RL, times, TR>{};

         // 0 * runtime_type
         template <typename RL,typename SL, typename TR>
         struct binary_op_impl<
            quan::fusion::static_value<RL,SL>,
            quan::meta::times,
            TR,
            typename quan::where_<
               quan::meta::and_<
                  quan::meta::eq_zero<SL>,
                  quan::meta::not_<quan::fusion::is_static_value<TR> >,
                  quan::meta::is_scalar<TR>,
                  quan::meta::is_valid_binary_op<RL,times,TR>
               >
            >::type
         > : quan::fusion::static_value<
               typename quan::meta::binary_op< RL, times, TR>::type,
            SL
         > {};

      // runtime * static 0
         template <typename TL,typename RR, typename SR>
         struct binary_op_impl<
            TL,
            quan::meta::times,
            quan::fusion::static_value<RR,SR>,
            typename quan::where_<
               quan::meta::and_<
                  quan::meta::eq_zero<SR>,
                  quan::meta::not_<quan::fusion::is_static_value<TL> >,
                  quan::meta::is_scalar<TL>,
                  quan::meta::is_valid_binary_op<TL,times,RR>
               >
            >::type
         > : quan::fusion::static_value<
              typename quan::meta::binary_op<TL,times,RR>::type,
            SR
         >{};
   } // impl

}}//quan::meta


namespace quan{namespace fusion{ 

    //lossless so stay in ct
    template <typename RL, typename SL, typename RR, typename SR>
    inline constexpr 
    typename quan::where_<
        quan::meta::and_<
            quan::meta::is_lossless_calculation<RL,quan::meta::times,RR>,
            quan::meta::is_lossless_calculation<SL,quan::meta::times,SR>
        >,
        typename quan::meta::binary_op<
            quan::fusion::static_value<RL,SL>,
            quan::meta::times,
            quan::fusion::static_value<RR,SR>
        >::type
    >::type
    operator *  (
            quan::fusion::static_value<RL,SL> const &,
            quan::fusion::static_value<RR,SR> const &
    ){
        typedef typename quan::meta::binary_op<
            quan::fusion::static_value<RL,SL>,
            quan::meta::times,
            quan::fusion::static_value<RR,SR>
        >::type result_type;
        return result_type{};
    }
    // move to rt
    template <typename RL, typename SL, typename RR, typename SR>
    inline constexpr 
    typename quan::where_not<
        quan::meta::and_<
            quan::meta::is_lossless_calculation<RL,quan::meta::times,RR>,
            quan::meta::is_lossless_calculation<SL,quan::meta::times,SR>
        >,
        typename quan::meta::binary_op<
            quan::fusion::static_value<RL,SL>,
            quan::meta::times,
            quan::fusion::static_value<RR,SR>
        >::type
    >::type
    operator *  (
            quan::fusion::static_value<RL,SL> const & lhs,
            quan::fusion::static_value<RR,SR> const & rhs
    ){
//        typedef quan::fusion::static_value<RL,SL> suL;
//        typedef quan::fusion::static_value<RR,SR> suR; 
        return to_runtime{}(lhs) * to_runtime{}(rhs);
    }
    // not zero so move to rt
    template<typename RL, typename SL, typename TR>
    inline constexpr
    typename quan::where_<
        quan::meta::and_<
            quan::meta::neq_zero<SL>,
            quan::meta::not_<quan::fusion::is_static_value<TR> >,
            quan::meta::is_scalar<TR>
        >,
        typename quan::meta::binary_op<
            quan::fusion::static_value<RL,SL>,
            quan::meta::times,
            TR
        >::type
    >::type
    operator * (
        quan::fusion::static_value<RL,SL> const & lhs,
        TR const & rhs
    )
    {
       // typedef quan::fusion::static_value<RL,SL> suL;
        return to_runtime{}(lhs) * rhs;
    }

    //zero so move all to ct
    template<typename RL, typename SL, typename TR>
    inline constexpr 
    typename quan::where_<
        quan::meta::and_<
           quan::meta::eq_zero<SL>,
           quan::meta::not_<quan::fusion::is_static_value<TR> >,
           quan::meta::is_scalar<TR>           
        >,
        typename quan::meta::binary_op<
            quan::fusion::static_value<RL,SL>,
            quan::meta::times,
            TR
        >::type
    >::type
    operator * (
        quan::fusion::static_value<RL,SL> const &,
        TR const & rhs
    )
    {
        typedef quan::fusion::static_value<RL,SL> suL;
        typedef typename quan::meta::binary_op<
            suL,
            quan::meta::times,
            TR
        >::type result_type;
        return result_type{};
    }

    //other non zero case
    template<typename TL, typename RR, typename SR>
    inline  constexpr
    typename quan::where_<
        quan::meta::and_<
           quan::meta::neq_zero<SR>,
           quan::meta::not_<quan::fusion::is_static_value<TL> >,
           quan::meta::is_scalar<TL>
        >,
        typename quan::meta::binary_op<
            TL,
            quan::meta::times,
            quan::fusion::static_value<RR,SR>
        >::type
    >::type
    operator * (
        TL const & lhs,
        quan::fusion::static_value<RR,SR> const & rhs
    )
    {
       // typedef quan::fusion::static_value<RR,SR> suR;
        return lhs * to_runtime{}(rhs);
    }

    //other zero case
    template<typename TL, typename RR, typename SR>
    inline constexpr
    typename quan::where_<
        quan::meta::and_<
           quan::meta::eq_zero<SR>,
           quan::meta::not_<quan::fusion::is_static_value<TL> >,
           quan::meta::is_scalar<TL>
        >,
        typename quan::meta::binary_op<
            TL,
            quan::meta::times,
            quan::fusion::static_value<RR,SR>
        >::type
    >::type
    operator * (
        TL const & lhs,
        quan::fusion::static_value<RR,SR> const &
    )
    {
        typedef quan::fusion::static_value<RR,SR> suR;
        typedef typename quan::meta::binary_op<
            TL,
            quan::meta::times,
            suR
        >::type result_type;
        return result_type{};
    }

}}//quan::fusion

#endif
