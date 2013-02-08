#ifndef QUAN_UAV_POSITION_HPP_INCLUDED
#define QUAN_UAV_POSITION_HPP_INCLUDED


#include <quan/length.hpp>
#include <quan/angle.hpp>
#include <quan/atan2.hpp>

namespace quan { namespace uav {

	struct position {
		 position(quan::angle::rad const & lat_in, quan::angle::rad const & lon_in, quan::length::m const & h_in )
			  :lat(lat_in),lon(lon_in),alt(h_in) {}
/*
		 quan::angle::rad get_lat() const{return m_lat;}
		 quan::angle::rad get_lon() const {return m_lon;}
		 quan::length::m  get_alt() const {return m_alt;}

       
	private:
*/
		 quan::angle::rad lat;
		 quan::angle::rad lon;
		 quan::length::m   alt;
	};

}}

#endif // QUAN_UAV_POSITION_HPP_INCLUDED
