#ifndef QUAN_FUSION_OUT_STATIC_VALUE_HPP_INCLUDED
#define QUAN_FUSION_OUT_STATIC_VALUE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
/// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan/concepts/fusion/static_value.hpp>

#include <iostream>

namespace quan{namespace fusion{

#if defined __cpp_concepts
     
   // template <quan::fusion::StaticValue T> 
    inline constexpr 
    std::ostream & 
    operator << (std::ostream& os, quan::fusion::StaticValue v )
    {
        return os << "static{" << quan::fusion::to_runtime{}(v) << "}";
    }

#else

    template <typename T> 
    inline constexpr 
    typename quan::where_<quan::fusion::is_static_value<T> ,std::ostream & >::type
    operator << (std::ostream& os, T )
    {
        return os << "static{" << quan::fusion::to_runtime{}(T{}) << "}";
    }

#endif

}}//quan::fusion


#endif
