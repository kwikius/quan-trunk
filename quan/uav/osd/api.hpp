#ifndef QUAN_UAV_OSD_API_HPP_INCLUDED1
#define QUAN_UAV_OSD_API_HPP_INCLUDED1

#include <cstdarg>
#include <cstdio>
#include <quan/angle.hpp>
#include <quan/length.hpp>
#include <quan/two_d/vect.hpp>
#include <quan/uav/position.hpp>
#include <quan/uav/attitude.hpp>
#include <quan/uav/osd/colour.hpp>
#include <quan/uav/osd/get_video_mode.hpp>

namespace quan{ namespace uav{ namespace osd{

   void  on_draw();

   typedef quan::angle_<int32_t>::deg10e7                   lat_lon_type;
   typedef quan::length_<float>::mm                         altitude_type;
   typedef quan::uav::position<lat_lon_type,altitude_type>  position_type;
   typedef quan::uav::attitude<float>                       attitude_type;
   // the position_type should use integer value_type throughout
   // till that is fixed, use this type
   typedef quan::uav::position<lat_lon_type,quan::length_<int32_t>::mm> norm_position_type;

   struct basic_font;
   struct basic_bitmap;

   typedef basic_bitmap const * bitmap_ptr;
   typedef basic_font const * font_ptr;
   typedef quan::two_d::vect<int32_t> pxp_type;
   typedef quan::two_d::vect<int32_t> size_type;
   typedef quan::angle_<float>::deg   angle_type;
   typedef const char* text_ptr;

// #############definition dependent on device #################
   pxp_type       transform_to_raw(pxp_type const & pos);
   pxp_type       transform_from_raw(pxp_type const & pos);
   void           set_pixel_raw(pxp_type const & px,colour_type c);
   colour_type    get_pixel_raw(pxp_type const & px);

   void           set_clip_rect(pxp_type const & minimums, pxp_type const & maximums);
   size_type      get_display_size();
//################# ~ definition dependent on device ####################

     // fonts
   font_ptr get_font( uint32_t id);
   pxp_type get_size( font_ptr p);
   bitmap_ptr get_char(font_ptr, int32_t i);

   // bitmaps
   bitmap_ptr get_bitmap(uint32_t id);
   pxp_type get_size( bitmap_ptr p);
   colour_type get_pixel_raw(bitmap_ptr,pxp_type const & pos);

   inline void  set_pixel(pxp_type const & px, colour_type c)
   {
      set_pixel_raw(transform_to_raw(px),c);
   }

   void set_display_buffer(uint32_t offset32,uint32_t mask,colour_type c);

   inline colour_type    get_pixel(pxp_type const & px)
   {
      return get_pixel_raw(transform_to_raw(px));
   }

   void           draw_bitmap(bitmap_ptr image, pxp_type const & pos);
   void           draw_bitmap(bitmap_ptr image, pxp_type const & pos, 
                     pxp_type const & rotation_centre, 
                     angle_type const & angle
                  );

   void           draw_text(text_ptr str, pxp_type const & pos,font_ptr font);
   inline void    draw_text(text_ptr str, pxp_type const & pos, uint32_t i = 0U)
   {
      font_ptr p = get_font(i);
      if (p){draw_text(str,pos,p);}
   }

   template <uint32_t Buflen, uint32_t i = 0>
   inline void draw_text(pxp_type const & pos,const char * const format,  ...)
   {
     char buffer[Buflen];
     va_list args;
     va_start (args, format);
     vsnprintf (buffer,Buflen,format, args);
     draw_text(buffer,pos,i);
     va_end(args);
   }

   void           draw_line(pxp_type const & from, pxp_type const & to,colour_type c);
   void           draw_horizontal_line(pxp_type from , uint32_t len, colour_type colour);
   void           draw_box(pxp_type const & corner1, pxp_type const & corner2,colour_type c, bool filled);
   void           draw_circle(int32_t radius,pxp_type const & pos, colour_type c);
   void           draw_arc(int32_t radius,
                     pxp_type const & pos, 
                     angle_type const & start_angle,
                     angle_type const & end_angle,
                     colour_type c
                  );
   void           flood_fill(pxp_type const & start_pos, colour_type new_colour, int max_count);

}}}

#endif // QUAN_UAV_OSD_API_HPP_INCLUDED1
