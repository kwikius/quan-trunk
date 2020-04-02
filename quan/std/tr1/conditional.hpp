#ifndef QUAN_TR1_STD_CONDITIONAL_HPP_INCLUDED
#define QUAN_TR1_STD_CONDITIONAL_HPP_INCLUDED

#include <quan/config.hpp>
#if defined QUAN_USE_QUAN_STD_TR1

#include <quan/meta/if.hpp>

namespace std{

   template< bool B, typename T, typename F >
   struct conditional;

   template< bool B, typename T, typename F >
   struct conditional : quan::meta::if_c<B,T,F>{};
}
#else
#include <type_traits>
#endif

#endif // QUAN_TR1_STD_CONDITIONAL_HPP_INCLUDED
