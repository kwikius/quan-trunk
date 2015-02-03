
// Copyright Andy Little 2003 - 2014
// Copyright David Walthall 2006
/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
*/
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


