#ifndef QUAN_UAV_OSD_API_HPP_INCLUDED
#define QUAN_UAV_OSD_API_HPP_INCLUDED

#include <quan/angle.hpp>
#include <quan/two_d/vect.hpp>
#include <quan/uav/osd/colour.hpp>

namespace quan{ namespace uav{ namespace osd{

   struct basic_font;
   struct basic_bitmap;
   
   typedef basic_bitmap bitmap_type;
   typedef basic_font font_type;
   typedef quan::two_d::vect<int32_t> pxp_type;
   typedef quan::two_d::vect<int32_t> size_type;
   typedef quan::two_d::vect<int32_t> pos_type;
   typedef quan::angle_<float>::deg   angle_type;

   pos_type       fn_transform_to_raw(pos_type const & pos);
   pos_type       fn_transform_from_raw(pos_type const & pos);
 
   void           fn_set_pixel(pxp_type const & px, colour_type c);
   void           fn_set_pixel_raw(pxp_type const & px,colour_type c);
   colour_type    fn_get_pixel_raw(pxp_type const & px);
   void           fn_bitmap(pxp_type const & pos, bitmap_type* image);
   void           fn_rotated_bitmap(
                     pxp_type const & pos, 
                     bitmap_type* image, 
                     pxp_type const & rotation_centre, 
                     angle_type const & angle
                  );
   void           fn_text(pxp_type const & pos,const char* str, font_type* font);
   void           fn_line(pxp_type const & from, pxp_type const & to,colour_type c);
   void           fn_circle(pxp_type const & pos_in, int radius,colour_type c);
   void           fn_arc(pxp_type const & pos, 
                     int32_t radius,
                     angle_type const & start_angle,
                     angle_type const & end_angle,
                     colour_type c
                  );
   void           fn_set_clip(pos_type const & minimums, pos_type const & maximums);
   void           fn_flood(pxp_type const & start_pos, colour_type new_colour);
   size_type      fn_get_display_size();
   
}}}


#endif // QUAN_UAV_OSD_API_HPP_INCLUDED
