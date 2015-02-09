#ifndef QUAN_UAV_POSITION_HPP_INCLUDED
#define QUAN_UAV_POSITION_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

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

#include <quan/length.hpp>
#include <quan/angle.hpp>
#include <quan/implicit_cast.hpp>

namespace quan { namespace uav {

   template <typename AngleType, typename LengthType>
	struct position {
       typedef LengthType length_type;
       typedef AngleType angle_type;
       position():lat{0.f},lon{0.f},alt{0.f}{}
		 position(
         angle_type const & lat_in, 
         angle_type const & lon_in,
         length_type const & h_in )
	    :lat{lat_in},lon{lon_in},alt{h_in} {}
		 angle_type    lat;
		 angle_type    lon;
		 length_type   alt;
       template <typename LengthType1, typename AngleType1>
       position & operator = (position<LengthType1,AngleType1> const & in)
       {
         this->lat = in.lat;
         this->lon = in.lon;
         this->alt = in.alt;
         return *this;
       }
       template <typename LengthType1, typename AngleType1>
       position (position<LengthType1,AngleType1> const & in)
       : lat{quan::implicit_cast<angle_type>(in.lat)},
         lon{quan::implicit_cast<angle_type>(in.lon)},
         alt{quan::implicit_cast<length_type>(in.alt)}{}
	};

}}

#endif // QUAN_UAV_POSITION_HPP_INCLUDED
