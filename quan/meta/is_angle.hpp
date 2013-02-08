#ifndef QUAN_META_IS_ANGLE_HPP_INCLUDED
#define QUAN_META_IS_ANGLE_HPP_INCLUDED

// Copyright Andrew Little 2006-2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <type_traits>
#include <quan/meta/or.hpp>

namespace quan{ namespace meta{

    template <typename T>
    struct is_mathematic_angle : std::false_type{};
    
    template <typename T>
    struct is_fraction_of_revolution : std::false_type{};

    template <typename T>
    struct is_angle : or_<
       is_mathematic_angle<T>,
       is_fraction_of_revolution<T>
    >{}; 
    
}} //quan::meta

#endif

