#ifndef QUAN_UTILITY_SHOW_CONVERSION_FACTOR_WORKING_HPP_INCLUDED
#define QUAN_UTILITY_SHOW_CONVERSION_FACTOR_WORKING_HPP_INCLUDED


#include <iostream>
#include <cmath>
#include <string>
#include <type_traits>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/fusion/meta_rational_to_runtime.hpp>

namespace quan{

   template <typename Q>
   inline void show_working( std::ostream & out,Q const & q, std::string const & q_name)
   {
      out << q_name << " outputs as : " << q <<'\n';

      typedef typename std::remove_reference<decltype(q)>::type q_type;
      typedef typename q_type::unit unit;
      typedef typename unit::conversion_factor conversion_factor;
      typedef typename conversion_factor::multiplier multiplier;
      typedef typename conversion_factor::exponent exponent;

      auto rt_mux = quan::fusion::to_runtime{}(multiplier{});
      auto rt_exp = quan::fusion::to_runtime{}(exponent{});
      auto rt_cf = rt_mux * std::pow(10,rt_exp);

      auto rt_norm_value = q.numeric_value() * rt_cf;

      out << q_name << ".numeric_value = " << q.numeric_value() <<'\n';
      out << q_name << ".conversion_factor.mux = " << rt_mux << " rational(" << multiplier::numerator << " / " << multiplier::denominator << ")\n";
      out << q_name << ".conversion_factor.exp = " << rt_exp << " rational(" << exponent::numerator << " / " << exponent::denominator << ")\n";
      out << "conversion factor calc = " << q_name << ".conversion_factor.mux * pow(10," << q_name << ".conversion_factor.exp)\n";
      out << q_name << ".conversion_factor = " << rt_cf << '\n';
      out << q_name << ".normalised value =  " << rt_norm_value << "\n\n";
   }

}

#endif // QUAN_UTILITY_SHOW_CONVERSION_FACTOR_WORKING_HPP_INCLUDED
