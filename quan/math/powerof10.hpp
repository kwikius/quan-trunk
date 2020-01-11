#ifndef QUAN_MATH_POWEROF10_HPP_INCLUDED
#define QUAN_MATH_POWEROF10_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/undefined.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/not.hpp>
#include <type_traits>
#include <limits>
#include <quan/math/to_power.hpp>
#include <quan/meta/identity.hpp>

namespace quan{ namespace impl{

   template <typename Exp, typename Where = void>
   struct pow10_impl : quan::undefined{};

   template <
      typename Exp // std:ratio
   > 
   struct pow10_impl<
      Exp,
      typename quan::where_< 
         quan::meta::and_<
            std::integral_constant<bool,(Exp::den == 1)>,
            std::integral_constant<bool,(Exp::num == 0)>
         >
      >::type
   >{
        typedef int8_t type;
        static constexpr type value = static_cast<type>(1);
   };

   template <
      typename Exp // std:ratio
   > 
   struct pow10_impl<
      Exp,
      typename quan::where_< 
         quan::meta::and_<
            std::integral_constant<bool,(Exp::den == 1)>,
            std::integral_constant<bool,(Exp::num > 0)>,
            std::integral_constant<bool,(Exp::num <= std::numeric_limits<int64_t>::digits10)>
         >
      >::type
   >{
      typedef typename quan::meta::eval_if<
         std::integral_constant<bool,(Exp::num <= std::numeric_limits<int8_t>::digits10 )>,
            quan::meta::identity<int8_t>,
         std::integral_constant<bool,(Exp::num <= std::numeric_limits<int16_t>::digits10 )>,
            quan::meta::identity<int16_t>,
         std::integral_constant<bool,(Exp::num <= std::numeric_limits<int32_t>::digits10 )>,
            quan::meta::identity<int32_t>,
         quan::meta::identity<int64_t>
      >::type type;
      static constexpr type value = static_cast<type>(10) * pow10_impl<std::ratio<Exp::num -1,1> >::value;
   };


   template <
      typename Exp // std:ratio
   > 
   struct pow10_impl<
      Exp,
      typename quan::where_< 
         quan::meta::or_<
            std::integral_constant<bool,(Exp::den !=1)>,
            std::integral_constant<bool,(Exp::num < 0)>,
            std::integral_constant<bool,(Exp::num > std::numeric_limits<int64_t>::digits10)>
        >
      >::type
    >{
         typedef QUAN_FLOAT_TYPE type;
         static constexpr type value = quan::to_power<Exp::num,Exp::den>(static_cast<type>(10));
    };

   } // impl

   template <typename Exp>
   struct powerof10 : impl::pow10_impl<Exp>{};

}//quan


#endif // QUAN_MATH_POWEROF10_HPP_INCLUDED
