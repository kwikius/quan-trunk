
#include <quan/uav/osd/api.hpp>

/*
draw an arc normalised in the first 45 degrees octant (mirroring for 45 -90 etc)
then figuring what other octants to draw it in.

Inspired from web.engr.oregonstate.edu/~sllu/bcircle.pdf
*/

using namespace quan::uav::osd;

namespace {

   void plot8pts( pxp_type const & centre, int x, int y,colour_type c)
   {
      set_pixel(centre + pxp_type{x,y},c);
      set_pixel(centre + pxp_type{-x,y},c);
      set_pixel(centre + pxp_type{-x,-y},c);
      set_pixel(centre + pxp_type{x,-y},c);
      set_pixel(centre + pxp_type{y,x},c);
      set_pixel(centre + pxp_type{-y,x},c);
      set_pixel(centre + pxp_type{-y,-x},c);
      set_pixel(centre + pxp_type{y,-x},c);
   }
}

/*
   void           draw_circle(int32_t radius,pxp_type const & pos, colour_type c);
*/

namespace quan{ namespace uav { namespace osd{

   void  draw_circle(int32_t radius,pxp_type const & centre, colour_type c)
   {
     int x = radius;
     int y = 0;
     int re = 1-x;
     while ( x >= y){
        plot8pts(centre,x,y,c);
        ++y;
        if ( re < 0){
           re += 2 * (y + 1);
        }else{
           --x;
           re += 2 * (y - x + 1);
        }
     }
   }

}}} //quan::uav::osd
