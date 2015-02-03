#ifndef QUAN_REFLECT_SOURCE_OUTPUT_RATIONAL_HPP_INCLUDED
#define QUAN_REFLECT_SOURCE_OUTPUT_RATIONAL_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
