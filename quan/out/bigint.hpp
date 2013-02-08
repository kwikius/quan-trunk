#ifndef QUAN_OUT_BIGINT_HPP_INCLUDED
#define QUAN_OUT_BIGINT_HPP_INCLUDED

#include <quan/big_rational.hpp>
#include <iostream>

namespace quan{

     inline std::ostream &  operator << (std::ostream & os, quan::bigint const & i)
     {
        return os << i.to_string();
     }
}

#endif // QUAN_OUT_BIGINT_HPP_INCLUDED
