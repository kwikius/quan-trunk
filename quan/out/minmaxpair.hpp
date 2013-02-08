#ifndef QUAN_OUT_MINMAXPAIR_HPP_INCLUDED
#define QUAN_OUT_MINMAXPAIR_HPP_INCLUDED

#include <quan/minmaxpair.hpp>
#include <iostream>
namespace quan{

   template <typename Min, typename Max>
   inline 
   std::ostream & os (std::ostream& os, minmaxpair<Min,Max> const & v)
   {
      os  << '[' << v. min << ',' << v.max << ']';
      return os;
   }

}

#endif

