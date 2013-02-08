#ifndef QUAN_OUT_BIG_RATIONAL_HPP_INCLUDED
#define QUAN_OUT_BIG_RATIONAL_HPP_INCLUDED

#include <quan/big_rational.hpp>
#include <quan/out/bigint.hpp>

namespace quan{

   inline std::ostream & operator << (std::ostream & os, quan::big_rational const & r)
   {
       return os << r.to_string() ;
   }
}


#endif // QUAN_OUT_BIG_RATIONAL_HPP_INCLUDED
