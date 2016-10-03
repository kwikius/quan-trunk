#ifndef QUAN_UAV_OSD_DETAIL_AERFLITE_COLOUR_TYPE_HPP_INCLUDED
#define QUAN_UAV_OSD_DETAIL_AERFLITE_COLOUR_TYPE_HPP_INCLUDED

namespace quan{ namespace uav{ namespace osd{ namespace detail{

  // n.b grey is transparent in aerflite
  enum class aerflite_colour_type{ white = 0, grey = 1, black = 2, transparent = 3};

}}}} // quan::uav::osd::detail

#endif // QUAN_UAV_OSD_DETAIL_AERFLITE_COLOUR_TYPE_HPP_INCLUDED
