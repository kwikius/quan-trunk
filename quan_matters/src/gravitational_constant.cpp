// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/constants/gravitational_constant.hpp>
/*
    gravitational_constant definition required to link
*/
#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<>
quan::gravitational_constant_<long double>::G_type const 
quan::gravitational_constant_<long double>::G
= quan::gravitational_constant_<long double>::G_type(6.6726L);

template<>
quan::gravitational_constant_<double>::G_type const  
quan::gravitational_constant_<double>::G
= quan::gravitational_constant_<double>::G_type(6.6726);

template<>
quan::gravitational_constant_<float>::G_type const  
quan::gravitational_constant_<float>::G
= quan::gravitational_constant_<float>::G_type(6.6726F);
#endif

