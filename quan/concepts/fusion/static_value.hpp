#ifndef QUAN_CONCEPTS_FUSION_STATIC_VALUE_HPP_INCLUDED
#define QUAN_CONCEPTS_FUSION_STATIC_VALUE_HPP_INCLUDED

#if defined __cpp_concepts

#include <quan/fusion/static_value/is_static_value.hpp>

namespace quan{ namespace fusion{
    
   template <typename T>
   concept bool StaticValue = quan::fusion::is_static_value<T>::value;
   
}}

#endif

#endif // QUAN_CONCEPTS_FUSION_STATIC_VALUE_HPP_INCLUDED
