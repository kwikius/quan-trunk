// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.


/*
    boltzmanns constant definition
*/

#include <quan/constants/boltzmanns_constant.hpp>
#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<>
quan::boltzmanns_constant_<double>::K_type const
quan::boltzmanns_constant_<double>::K 
= quan::boltzmanns_constant_<double>::K_type(1.380658);

template<>
quan::boltzmanns_constant_<long double>::K_type const
quan::boltzmanns_constant_<long double>::K 
= quan::boltzmanns_constant_<long double>::K_type(1.380658L);

template<>
quan::boltzmanns_constant_<float>::K_type const
quan::boltzmanns_constant_<float>::K 
= quan::boltzmanns_constant_<float>::K_type(1.380658f);

#endif

