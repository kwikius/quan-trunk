
#include <quan/out/length.hpp>
#include <quan/math/powerof10.hpp>
#include <quan/utility/show_conversion_factor_working.hpp>
#include <cmath>
#include <iostream>

template <typename Q>
void convert_to_log10(Q const& q)
{
 //  show_working(std::cout,q, "");
   std::cout.precision(20);
   typedef typename std::remove_reference<decltype(q)>::type q_type;
   typedef typename q_type::unit unit;
   typedef typename unit::conversion_factor conversion_factor;
   typedef typename conversion_factor::multiplier multiplier;
   auto constexpr muxnume = multiplier::numerator;
   auto constexpr muxdenom = multiplier::denominator;
   typedef typename conversion_factor::exponent exponent;
   auto constexpr expnume = exponent::numerator;
   auto constexpr expdenom = exponent::denominator;
   auto constexpr ratio_digits10 = std::numeric_limits<intmax_t>::digits10 -3;
   auto constexpr pow10digits10 = static_cast<intmax_t>(pow(10,ratio_digits10));
   auto constexpr log10_value = std::log10(static_cast<double>(muxnume)/ muxdenom) ;// + 
   auto constexpr ratio_log10_nume_float = log10_value * pow10digits10;
   auto constexpr ratio_log10_nume = static_cast<intmax_t>(std::round(ratio_log10_nume_float));
   typedef typename std::ratio<ratio_log10_nume,pow10digits10>::type ratio_log10a;
   typedef typename std::ratio_add<ratio_log10a,std::ratio<expnume,expdenom> >::type ratio_log10;

    std::cout << "--------------- " << units_str(q) << " ------------\n";
    std::cout << "conversion factor (mux)   = " << static_cast<double>(muxnume)/ muxdenom * std::pow(10,static_cast<double>(expnume)/expdenom) <<'\n';
    std::cout << "exp10                     = " << ratio_log10::num;
    if ( ratio_log10::den != 1) std::cout << " / " <<  ratio_log10::den;
    std::cout <<'\n';
    std::cout << "conversion factor (log10) = " << std::pow(10,static_cast<double>(ratio_log10::num)/ ratio_log10::den) << '\n';

}

int main()
{
   convert_to_log10(quan::length::nm{});
   convert_to_log10(quan::length::um{});
   convert_to_log10(quan::length::mil{});
   convert_to_log10(quan::length::thou{});
   convert_to_log10(quan::length::mm{});
   convert_to_log10(quan::length::cm{});
   convert_to_log10(quan::length::in{});
   convert_to_log10(quan::length::dm{});
   convert_to_log10(quan::length::ft{});
   convert_to_log10(quan::length::ft_us{});
   convert_to_log10(quan::length::yd{});
   convert_to_log10(quan::length::m{});
   convert_to_log10(quan::length::fathom{});
   convert_to_log10(quan::length::fathom_us{});
   convert_to_log10(quan::length::ch{});
   convert_to_log10(quan::length::mi{});
   convert_to_log10(quan::length::l_y_{});

}
