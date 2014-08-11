#ifndef QUAN_REFLECT_SOURCE_OUTPUT_DIMENSION_HPP_INCLUDED
#define QUAN_REFLECT_SOURCE_OUTPUT_DIMENSION_HPP_INCLUDED
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

#include <iostream>
#include <string>
#include <quan/reflect/source/output_rational.hpp>
#include <quan/reflect/dimension.hpp>
#include <quan/fun/get_fun_seq1.hpp>
#include <quan/fun/range.hpp>
#include <quan/fun/vector7.hpp>
#include <quan/fun/for_each.hpp>
#include <quan/fun/output.hpp>

namespace quan{ namespace reflect{ namespace source{


template <typename FixedQuantity>
inline
std::ostream & output_dimension(
   std::ostream & os,
   std::string const & sol, 
   FixedQuantity const &
)
{
   os << sol << "quan::meta::dimension<\n";
   quan::fun::for_each_and_last(
      quan::fun::get_fun_seq1(
         quan::reflect::dimension<FixedQuantity>(),
         //quan::fun::range<0,6>(
            quan::fun::vector7<
               quan::length,
               quan::mass,
               quan::time,
               quan::temperature,
               quan::current,
               quan::substance,
               quan::intensity
            >()
        // )
      ),
      output_rational(sol + "   ",os,",\n"),
      output_rational(sol + "   ",os,"\n")
   ); 
   os << sol << ">";
   return os;
}
}}}//quan::reflect::source

#endif
