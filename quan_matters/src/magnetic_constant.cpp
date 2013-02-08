// Copyright Andrew Little 2005
//
 
 
 
//
// See libs/pqs for documentation.

/*
    gas constant definition required to link
*/

#include <quan/constants/magnetic_constant.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<>
quan::magnetic_constant_<double>::mu0_type const
quan::magnetic_constant_<double>::mu0 
= quan::magnetic_constant_<double>::mu0_type(12.566370614);

template<>
quan::magnetic_constant_<long double>::mu0_type const
quan::magnetic_constant_<long double>::mu0 
= quan::magnetic_constant_<long double>::mu0_type(12.566370614L);

template<>
quan::magnetic_constant_<float>::mu0_type const
quan::magnetic_constant_<float>::mu0
= quan::magnetic_constant_<float>::mu0_type(12.566370614f);
#endif
