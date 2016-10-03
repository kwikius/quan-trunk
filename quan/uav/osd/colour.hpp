#ifndef QUAN_UAV_OSD_COLOUR_HPP_INCLUDED
#define QUAN_UAV_OSD_COLOUR_HPP_INCLUDED

#if defined QUAN_AERFLITE_BOARD
#include <quan/uav/osd/detail/aerflite_colour_type.hpp>
#else
#include <quan/uav/osd/detail/quantracker_colour_type.hpp>
#endif

namespace quan{ namespace uav{ namespace osd{

#if defined QUAN_AERFLITE_BOARD
  typedef quan::uav::osd::detail::aerflite_colour_type colour_type;
#else
  typedef quan::uav::osd::detail::quantracker_colour_type colour_type;
#endif
  typedef colour_type color_type;

}}}

#endif // QUAN_UAV_OSD_COLOUR_HPP_INCLUDED
