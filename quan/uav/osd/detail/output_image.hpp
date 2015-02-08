#ifndef QUAN_UAV_OSD_DETAIL_OUTPUT_IMAGE_HPP_INCLUDED
#define QUAN_UAV_OSD_DETAIL_OUTPUT_IMAGE_HPP_INCLUDED

#include <quan/uav/osd/api.hpp>
#include <iosfwd>

namespace quan{ namespace uav{ namespace osd{ namespace detail{

   void output_image (quan::uav::osd::bitmap_ptr pic, std::ostream & out);

}}}}

#endif // QUAN_UAV_OSD_DETAIL_OUTPUT_IMAGE_HPP_INCLUDED
