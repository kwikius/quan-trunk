#ifndef QUAN_MODULUS_HPP_INCLUDED
#define QUAN_MODULUS_HPP_INCLUDED

#include <quan/where.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#include <quan/std/tr1/common_type.hpp>
#endif

namespace quan{

   template <typename Lhs, typename Rhs>
   inline
   typename quan::where_<
      std::is_floating_point<typename std::common_type<Lhs,Rhs>::type>
      ,typename std::common_type<Lhs,Rhs>::type
   >::type
   modulus ( Lhs const & lhs, Rhs const & rhs)
   {
#ifndef QUAN_AVR_NO_CPP_STDLIB
       using std::fmod;
#else
       using ::fmod;
#endif
      typedef  typename std::common_type<Lhs,Rhs>::type common_type;
      return fmod(static_cast<common_type>(lhs),static_cast<common_type>(rhs));
   } // quan


   template <typename Lhs, typename Rhs>
   inline
   typename quan::where_<
      std::is_integral<typename std::common_type<Lhs,Rhs>::type>
      ,typename std::common_type<Lhs,Rhs>::type
   >::type
   modulus ( Lhs const & lhs, Rhs const & rhs)
   {
      return lhs % rhs ;
   } 

}// quan

#endif // QUAN_MODULUS_HPP_INCLUDED
