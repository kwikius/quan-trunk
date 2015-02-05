
#include <quan/uav/osd/api.hpp>

/*
draw an arc normalised in the first 45 degrees octant (mirroring for 45 -90 etc)
then figuring what other octants to draw it in.
*/

using namespace quan::uav::osd;

namespace {

   quan::angle::deg normalise_angle ( quan::angle::deg const & angle_in)
   {
      auto angle = angle_in;
      while ( angle >= quan::angle::deg{360}){
            angle -= quan::angle::deg{360};
      }
      while (angle < quan::angle::deg{0}){
          angle += quan::angle::deg{360};
      }
      return angle;
   }
   // which octant is point in
   // [0,0] = none ?
   // (0) for octant from 0 to 44.9 deg
   // ( 1) for 45 to 89.9
   // ( 2) for 90 to 134.9
   // etc...
   int find_octant (pxp_type const & pos)
   {
      if ( (pos.x == 0) && (pos.y == 0)) {
            return 0;
      }
      if (pos.y >= 0) {
            if (pos.x >= 0) {
                  if (pos.y < pos.x) {
                        return 0;
                     }
                  else {
                        return 1;
                     }
               }
            else { // x < 0
                  if (pos.y < -pos.x) {
                        return 3;
                     }
                  else {
                        return 2;
                     }
               }
         }
      else {  // y < 0
            if (pos.x >= 0) {
                  if (-pos.y < pos.x) {
                        return 7;
                     }
                  else {
                        return 6;
                     }
               }
            else { // x < 0
                  if (-pos.y < -pos.x) {
                        return 4;
                     }
                  else {
                        return 5;
                     }
               }
         }
   }
   
   // mapping angle to octant.. tricky !, odd numbered octants are mirrored around 45degree line
   quan::angle::deg map_angle_to_zero_octant (quan::angle::deg const & angle, int octant)
   {
      if (octant & 1) {
            return (octant + 1) * quan::angle::deg {45} - angle;
         }
      else {
            return angle - quan::angle::deg {45} * octant;
         }
   }

/*
   each bit  set in mask says to draw relevant octant
   Prob could do this better by first octant to draw, second ocatcnt to draw?
   then go through array of set_pixel_octant functions?
*/
   void plotoctants_mask (uint32_t mask, 
         pxp_type const & centre, int x, 
         int y, colour_type c)
   {
      if (mask & (1 << 0)) {
         set_pixel (centre + pxp_type {x, y}, c);
      }
      if (mask & (1 << 1)) {
         set_pixel (centre + pxp_type {y,x}, c);
      }
      if (mask & (1 << 2)) {
         set_pixel (centre + pxp_type {-y,x}, c);
      }
      if (mask & (1 << 3)) {
         set_pixel (centre + pxp_type {-x,y}, c);
      }
      if( mask & (1 << 4)) {
         set_pixel (centre + pxp_type {-x,-y}, c);
      }
      if (mask & (1 << 5)) {
         set_pixel (centre + pxp_type {-y,-x}, c);
         }
      if (mask & (1 << 6)) {
         set_pixel (centre + pxp_type {y,-x}, c);
         }
      if (mask & (1 << 7)) {
         set_pixel (centre + pxp_type {x,-y}, c);
      }
   }

/*
this really only required for first and last octants
*/
      
   void plot_arc_1st_octant1 (
      int mask,          // see plot_octants_mask above
      pxp_type const & centre,
      int radius,
      float start_slope,   // start slope in octant 0, always between 0 to 1
      float end_slope,      //end slope in octant 0, always between 0 to 1 and < than start slope
      colour_type c
   ){

      int x = radius;
      int y = 0;
      int re = 1 - x;
         
      while (x >= y) {
         if ( (static_cast<float> (y) / x) >= start_slope) {
            plotoctants_mask ( mask, centre, x, y, c);
         }
         if ( (static_cast<float> (y) / x) > end_slope) {
               break;
         }
         ++y;
         if (re < 0) {
            re += 2 * (y + 1);
         }else {
            --x;
            re += 2 * (y - x + 1);
         }
      }
   }

   // normalised_arc
   void normalised_arc (
      pxp_type const & centre,
      int radius,
      quan::angle::deg start_angle,
      quan::angle::deg end_angle,
      colour_type c
   )
   {
      pxp_type const start_point = {radius * cos (start_angle), radius * sin (start_angle) };
      pxp_type const end_point = {radius * cos (end_angle), radius * sin (end_angle) };
      
      int start_octant = find_octant (start_point);
      int end_octant = find_octant (end_point);
      //Hack.. when end_angle is 360 and start angle < 360 
      // then end_octant will prob go to 0
      // so bump it back to 7 otherwise violates always anticlockwise
      // from start angle to end _angle
      if (( end_octant == 0) && ( start_octant != 0)){
         end_octant = 7;
      }
       
      if ( start_octant == end_octant){
         float const start_slope
         = (start_octant & 1)
           ? tan (map_angle_to_zero_octant (end_angle, start_octant))
           : tan (map_angle_to_zero_octant (start_angle, start_octant));
         float const end_slope
            = (start_octant & 1)
           ? tan (map_angle_to_zero_octant (start_angle, end_octant))
           : tan (map_angle_to_zero_octant (end_angle, end_octant));

         int mask = 1 << start_octant;
         plot_arc_1st_octant1 (mask,centre,radius,start_slope,end_slope,c);
     }else {
         float const start_slope0
         = (start_octant & 1)
           ? 0
           : tan (map_angle_to_zero_octant (start_angle, start_octant));
         float const end_slope0
            = (start_octant & 1)
           ? tan (map_angle_to_zero_octant (start_angle, start_octant))
           : 1;
         int start_mask = 1 << start_octant;
         plot_arc_1st_octant1 (start_mask,centre,radius,start_slope0,end_slope0,c);
           // if centre sections
         if ( (end_octant - start_octant) > 1){
            int mid_mask = 0;
            for ( int i = start_octant + 1 ; i < (end_octant); ++i){
               mid_mask |= (1 << i);
            }
            plot_arc_1st_octant1 (mid_mask,centre,radius,0,1,c);
         }
          float const start_slope1
            = ((end_octant & 1) == 0)
           ? 0
           : tan (map_angle_to_zero_octant (end_angle, end_octant));
          float const end_slope1
            = ((end_octant & 1) == 0)
            ? tan (map_angle_to_zero_octant (end_angle, end_octant))
            : 1;
          int end_mask = 1 << end_octant;
          plot_arc_1st_octant1 (end_mask,centre,radius,start_slope1, end_slope1,c);
      }
   }
} // namespace

namespace quan{ namespace uav { namespace osd{

   void draw_arc (
      pxp_type const & pos,
      int32_t radius,
      quan::angle::deg const & start_angle_in,
      quan::angle::deg const & end_angle_in,
      colour_type c
   )
   {
      auto const start_angle = normalise_angle(start_angle_in);
      auto const end_angle = normalise_angle(end_angle_in);
      if ( end_angle != start_angle){
         if ( end_angle > start_angle){
            normalised_arc(pos,radius,start_angle, end_angle, c);
         }else{
            normalised_arc(pos,radius, start_angle, quan::angle::deg{360},c);
            normalised_arc(pos,radius, quan::angle::deg{0},end_angle,c);
         }
      }
   }

}}} // quan::uav::osd


 