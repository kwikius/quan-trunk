
// Copyright David Walthall 2006
//


 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    avogadros constant definition required to link
*/
#include <quan/constants/avogadro_constant.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<>
quan::avogadro_constant_<double>::Na_type const
quan::avogadro_constant_<double>::Na
= quan::avogadro_constant_<double>::Na_type(6.0221415);

template<>
quan::avogadro_constant_<long double>::Na_type const
quan::avogadro_constant_<long double>::Na
= quan::avogadro_constant_<long double>::Na_type(6.0221415L);

template<>
quan::avogadro_constant_<float>::Na_type const
quan::avogadro_constant_<float>::Na
= quan::avogadro_constant_<float>::Na_type(6.0221415f);
#endif


