#ifndef QUAN_META_LOG10_RATIO_HPP_INCLUDED
#define QUAN_META_LOG10_RATIO_HPP_INCLUDED

#include <cmath>
#include <limits>
#include <ratio>

#include <quan/meta/numerator.hpp>
#include <quan/meta/denominator.hpp>
#include <quan/meta/rational.hpp>

namespace quan{ namespace meta{

   /*
    get the rational log10 of a std::ratio
   */
   template <typename Ratio>
   struct log10_ratio{
      static constexpr auto ratio_digits10 = std::numeric_limits<intmax_t>::digits10 -3;
      static constexpr auto pow10digits10 = static_cast<intmax_t>(std::pow(10,ratio_digits10));
      static constexpr auto log10_value = std::log10(static_cast<double>(quan::meta::numerator<Ratio>::value)/ quan::meta::denominator<Ratio>::value) ;
      static constexpr auto ratio_log10_nume_float = log10_value * pow10digits10;
      static constexpr auto ratio_log10_nume = static_cast<intmax_t>(std::round(ratio_log10_nume_float));
      typedef typename std::ratio<ratio_log10_nume,pow10digits10>::type type;
      //###########TODO: change meta::rational in quan to std::ratio####
      typedef quan::meta::rational<type::num,type::den> quan_type;
      //#################################################################
   };

}} //quan::meta

#endif // QUAN_META_LOG10_RATIO_HPP_INCLUDED
