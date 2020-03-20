

#include <quan/config.hpp>
#if ! defined QUAN_MBED_ONLINE_COMPILER

#include <quan/out/length.hpp>
#include <quan/math/powerof10.hpp>
#include <quan/utility/show_conversion_factor_working.hpp>
#include <cmath>
#include <iostream>
#include <fstream>

template <typename Q>
void convert_to_log10(Q const& q, std::ostream & out)
{
 //  show_working(std::cout,q, "");
   out.precision(20);
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
   auto constexpr log10_value = std::log10(static_cast<double>(muxnume)/ muxdenom) ;
   auto constexpr ratio_log10_nume_float = log10_value * pow10digits10;
   auto constexpr ratio_log10_nume = static_cast<intmax_t>(std::round(ratio_log10_nume_float));
   // get log10 of multiplier
   typedef typename std::ratio<ratio_log10_nume,pow10digits10>::type ratio_log10a;
   // add log10 exponent
   typedef typename std::ratio_add<ratio_log10a,std::ratio<expnume,expdenom> >::type ratio_log10;
   // test raising to power
   typedef typename std::ratio_multiply<ratio_log10,std::ratio<1000> >::type mul_test;
   out << "mul test " << mul_test::num << " / " << mul_test::den << '\n';
   typedef typename std::ratio_divide<ratio_log10,std::ratio<1000> >::type div_test;
   out << "div test " << div_test::num << " / " << div_test::den << '\n';
    
    out << "--------------- " << units_str(q) << " ------------\n";
    if ( (muxnume == 1) && (muxdenom ==1) ) {
      out << "(S.I.)";
    }else{
      out << "(non S.I.)";
    }
    out << "non log version ....\n";
    out << "conversion_factor { mux = " << muxnume << " / " << muxdenom << " , exp = " << expnume << " / " << expdenom << " }\n";
    auto constexpr non_log_eval = static_cast<double>(muxnume)/ muxdenom * std::pow(10,static_cast<double>(expnume)/expdenom);
    out << "conversion factor (eval) = " << non_log_eval <<'\n';
    out << "exp10                     = " << ratio_log10::num;
    if ( ratio_log10::den != 1) out << " / " <<  ratio_log10::den;
    out <<'\n';
    out << "log version .....\n";
    out << "conversion_factor = { exp = " << ratio_log10::num << " / " << ratio_log10::den << " }\n";
    auto constexpr log_eval = std::pow(10,static_cast<double>(ratio_log10::num)/ ratio_log10::den);
    out << "conversion factor (eval) = " << log_eval << '\n';
    auto constexpr error = std::abs(non_log_eval - log_eval);
    if ( error == 0){
      out << "EXACT same result for log non log\n";
    }else{
      out << "DIFFERENCE (log - non-log eval) = " <<  error << '\n';
      out << "difference error/value = " <<  ( error / log_eval) << '\n';
    }

}


int main()
{
#if 0
   std::ofstream out("output.txt");
#else
   auto & out = std::cout;
#endif
   convert_to_log10(quan::length::nm{},out);
   convert_to_log10(quan::length::um{},out);
   convert_to_log10(quan::length::mil{},out);
   convert_to_log10(quan::length::thou{},out);
   convert_to_log10(quan::length::mm{},out);
   convert_to_log10(quan::length::cm{},out);
   convert_to_log10(quan::length::in{},out);
   convert_to_log10(quan::length::dm{},out);
   convert_to_log10(quan::length::ft{},out);
   convert_to_log10(quan::length::ft_us{},out);
   convert_to_log10(quan::length::yd{},out);
   convert_to_log10(quan::length::m{},out);
   convert_to_log10(quan::length::fathom{},out);
   convert_to_log10(quan::length::fathom_us{},out);
   convert_to_log10(quan::length::ch{},out);
   convert_to_log10(quan::length::mi{},out);
   convert_to_log10(quan::length::l_y_{},out);
   convert_to_log10(quan::length::pc{},out);
   convert_to_log10(quan::length::AU{},out);
   convert_to_log10(quan::length::naut_mile{},out);
   convert_to_log10(quan::length::pica_comp{},out);
   convert_to_log10(quan::length::pica_prn{},out);
   convert_to_log10(quan::length::point_comp{},out);
   convert_to_log10(quan::length::point_prn{},out);
   convert_to_log10(quan::length::angstrom{},out);
}

#else
#include <iostream>
int main()
{
   std::cout << "not supported on mbed compiler\n";
}

#endif

