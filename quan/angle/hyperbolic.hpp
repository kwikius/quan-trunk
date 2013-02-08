#ifndef QUAN_ANGLE_HYPERBOLIC_HPP_INCLUDED
#define QUAN_ANGLE_HYPERBOLIC_HPP_INCLUDED


/// Copyright Andrew Little 2005

/*
 hyberbolic functions
*/

#include <quan/angle/mathematic_angle.hpp>
#include <quan/where.hpp>
#include <quan/meta/min_type.hpp>

namespace quan{

    template <typename ValueType>
    inline
    typename quan::where_<
        quan::meta::is_angle_value_type<ValueType>,
        typename quan::meta::convert_integral_to_double<ValueType>::type
    >::type
    sinh(mathematic_angle<meta::rational<1>, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type result_type;
        using std::sinh;
        result_type result = sinh(static_cast<result_type>(x.numeric_value()));
        return  result;
    }

    template <typename ValueType>
    inline
    typename quan::where_<
        quan::meta::is_angle_value_type<ValueType>,
        typename quan::meta::convert_integral_to_double<ValueType>::type
    >::type
    cosh(mathematic_angle<meta::rational<1>, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type result_type;
        using std::cosh;
        result_type result = cosh(static_cast<result_type>(x.numeric_value()));
        return  result;
    }

    template <typename ValueType>
    inline
    typename quan::where_<
        quan::meta::is_angle_value_type<ValueType>,
        typename quan::meta::convert_integral_to_double<ValueType>::type
    >::type
    tanh(mathematic_angle<meta::rational<1>, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type result_type;
        using std::tanh;
        result_type result = tanh(static_cast<result_type>(x.numeric_value()));
        return  result;
    }

}// quan

#endif
