#ifndef QUAN_UAV_POSITION_HPP_INCLUDED
#define QUAN_UAV_POSITION_HPP_INCLUDED

#include <quan/length.hpp>
#include <quan/angle.hpp>
#include <quan/implicit_cast.hpp>

namespace quan { namespace uav {

   template <typename AngleType, typename LengthType>
	struct position {
       typedef LengthType length_type;
       typedef AngleType angle_type;
       position():lat{0},lon{0},alt{0}{}
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
       }
       template <typename LengthType1, typename AngleType1>
       position (position<LengthType1,AngleType1> const & in)
       : lat{quan::implicit_cast<angle_type>(in.lat)},
         lon{quan::implicit_cast<angle_type>(in.lon)},
         alt{quan::implicit_cast<length_type>(in.alt)}{}
	};

}}

#endif // QUAN_UAV_POSITION_HPP_INCLUDED
