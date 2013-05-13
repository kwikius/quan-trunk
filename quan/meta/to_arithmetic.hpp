#ifndef QUAN_META_TO_ARITHMETIC_HPP_INCLUDED
#define QUAN_META_TO_ARITHMETIC_HPP_INCLUDED

// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    to get at the arithmetic type of a type.
    Used by fixed_quantity value_type
*/

#include <quan/config.hpp>

#include <quan/where.hpp>
#ifndef __AVR__
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#endif


namespace quan{namespace meta{

    template <typename T, typename Where = void>
    struct to_arithmetic {};

    template <typename T>
    struct to_arithmetic<
        T, 
        typename quan::where_<
            std::is_arithmetic<T>
        >::type
    >{ 
        typedef T type;
    
        QUAN_CONSTEXPR type operator()(T const & in)const
        {
            return in;
        }
    };

}}//quan::meta

#endif
