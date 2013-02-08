#ifndef QUAN_REFLECT_SOURCE_OUTPUT_DIMENSION_HPP_INCLUDED
#define QUAN_REFLECT_SOURCE_OUTPUT_DIMENSION_HPP_INCLUDED

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
