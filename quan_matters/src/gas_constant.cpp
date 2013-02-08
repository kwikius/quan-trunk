// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    gas constant definition required to link
*/

#include <quan/constants/gas_constant.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<>
quan::gas_constant_<double>::R_type const
quan::gas_constant_<double>::R 
= quan::gas_constant_<double>::R_type(8.3145);

template<>
quan::gas_constant_<long double>::R_type const
quan::gas_constant_<long double>::R 
= quan::gas_constant_<long double>::R_type(8.3145L);

template<>
quan::gas_constant_<float>::R_type const
quan::gas_constant_<float>::R
= quan::gas_constant_<float>::R_type(8.3145f);
#endif
