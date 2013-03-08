#ifndef QUAN_UAV_POSITION_HPP_INCLUDED
#define QUAN_UAV_POSITION_HPP_INCLUDED

#include <quan/length.hpp>
#include <quan/angle.hpp>

namespace quan { namespace uav {

	struct position {
       position():lat{0},lon{0},alt{0}{}
		 position(
         quan::angle_<int32_t>::deg10e7 const & lat_in, 
         quan::angle_<int32_t>::deg10e7 const & lon_in,
         quan::length::m const & h_in )
	    :lat{lat_in},lon{lon_in},alt{h_in} {}
		 quan::angle_<int32_t>::deg10e7 lat;
		 quan::angle_<int32_t>::deg10e7 lon;
		 quan::length_<int32_t>::mm     alt;
	};

}}

#endif // QUAN_UAV_POSITION_HPP_INCLUDED
