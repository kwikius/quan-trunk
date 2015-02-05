#include <quan/two_d/rotation.hpp>
#include <quan/uav/osd/api.hpp>

using namespace quan::uav::osd;

namespace quan{ namespace uav { namespace osd{

   void draw_bitmap(bitmap_ptr bitmap,pxp_type const & pos_in )
   {
      if ( !bitmap){
         return ;
      }
      size_type const size_px = get_size(bitmap);
      pxp_type raw_pos_out = transform_to_raw({pos_in.x,pos_in.y + size_px.y});
      int const raw_x_start = raw_pos_out.x;
      for ( int32_t y = 0; y < size_px.y; ++y, ++raw_pos_out.y){
         raw_pos_out.x = raw_x_start;
         for ( int32_t x = 0; x < size_px.x; ++x, ++raw_pos_out.x){
             colour_type const c = get_pixel_raw(bitmap,{x,y});
             if ( c != colour_type::transparent){
               set_pixel_raw(raw_pos_out,c); 
             }
         }
      }
   }

   void draw_bitmap(bitmap_ptr bitmap,pxp_type const & pos, pxp_type const & rotation_centre,  
            quan::angle::deg const & angle)
   {
      if ( !bitmap){
         return ;
      }
      auto const size_px = get_size(bitmap);
      quan::two_d::rotation rotate{angle};
      for ( int32_t y = 0; y < size_px.y; ++y){
         for ( int32_t x = 0; x < size_px.x; ++x ){
             pxp_type const raw_px = {x, (size_px.y - 1)- y};
             colour_type const c = get_pixel_raw(bitmap,raw_px);
             if ( c != colour_type::transparent){
                pxp_type const rvect = pxp_type{x,y} - rotation_centre;
   #if 0
                pxp_type const raw_out_pos = transform_to_raw(rotate(rvect) + pos);
                set_pixel_raw(raw_out_pos,c); 
   #else
                auto rotated = rotate(rvect);
                pxp_type const rotated_i = {
                     static_cast<int>(rotated.x + static_cast<QUAN_FLOAT_TYPE>(0.5)) + pos.x,
                     static_cast<int>(rotated.y + static_cast<QUAN_FLOAT_TYPE>(0.5)) + pos.y
                };
                set_pixel_raw(transform_to_raw(rotated_i),c);
   #endif
             }
         }
      }
   }

}}} // quan::uav::osd
