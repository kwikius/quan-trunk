#ifndef QUAN_UAV_OSD_BASIC_BITMAP_HPP_INCLUDED
#define QUAN_UAV_OSD_BASIC_BITMAP_HPP_INCLUDED

#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd{

   struct basic_bitmap{
      virtual size_type get_size() const = 0;
      virtual colour_type get_pixel_colour(pxp_type const & p)const=0;
      protected:
         basic_bitmap(){}
         virtual ~basic_bitmap(){}
   }; 
   
}}} // quan::uav::osd

#endif // QUAN_UAV_OSD_BASIC_BITMAP_HPP_INCLUDED
