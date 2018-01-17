#ifndef QUAN_FUSION_OUT_STATIC_VALUE_HPP_INCLUDED
#define QUAN_FUSION_OUT_STATIC_VALUE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
/// Copyright Andrew Little 2005
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/fusion/static_value/static_value.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/fixed_quantity/io/output.hpp>
#include <quan/meta/out/rational.hpp>
#include <iostream>
#include <typeinfo>

namespace quan{namespace fusion{

    template <typename R, typename S>
    std::ostream & operator << (std::ostream& os, static_value<R,S>)
    {
        to_runtime runtime;
        S s;
        os << "static<"<< typeid(R).name() << ": " << runtime(s)  << " >";
        return os;
    }

    template <typename StaticUnit, typename Numeric, typename S>
     std::ostream & operator << (std::ostream& os, 
        static_value<quan::fixed_quantity<StaticUnit,Numeric> ,S>)
    {
        to_runtime runtime;
        typedef quan::fixed_quantity<StaticUnit,Numeric> rt_type;
        S s;
        os << "static{" << runtime(s) << ' ' << quan::units_str(rt_type()) << '}';
        return os;
    }

}}//quan::fusion


#endif
