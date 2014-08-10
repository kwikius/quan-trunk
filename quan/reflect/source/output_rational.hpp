#ifndef QUAN_REFLECT_SOURCE_OUTPUT_RATIONAL_HPP_INCLUDED
#define QUAN_REFLECT_SOURCE_OUTPUT_RATIONAL_HPP_INCLUDED

#include <string>
#include <iostream>
#include <quan/meta/get_nume_denom_functions.hpp>

namespace quan{ namespace reflect{ namespace source{

   struct output_rational{
      std::ostream & os;
      std::string sol;
      std::string eol;
      output_rational(
         std::string const & sol_in,
         std::ostream & os_in, 
         std::string const & eol_in
      ):os(os_in),sol(sol_in), eol(eol_in){}

      template <typename Rational>
      struct result{
            typedef std::ostream & type;
      };

      template <typename Rational>
      typename result<Rational>::type
      operator()(Rational in) const
      {
         os << sol
            << "quan::meta::rational<" 
            << get_numerator(in) << ',' << get_denominator(in)
            << '>' 
            << eol;
         return os;
      }
   };

}}}//quan::reflect::source

#endif
