#ifndef QUAN_STD_TR1_COMMON_TYPE_HPP_INCLUDED
#define QUAN_STD_TR1_COMMON_TYPE_HPP_INCLUDED

#include <quan/config.hpp>
#ifdef QUAN_USE_QUAN_STD_TR1

#include <quan/meta/binary_op.hpp>

namespace std{

   template <typename TL, typename TR>
   struct common_type : quan::meta::binary_op<TL,quan::meta::minus,TR>{};
}

#else
#include <type_traits>
#endif

#endif // QUAN_STD_TR1_COMMON_TYPE_HPP_INCLUDED
