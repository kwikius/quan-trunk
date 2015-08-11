
#include <quan/uav/osd/api.hpp>
#include <quan/constrain.hpp>

using namespace quan::uav::osd;
/*
draw an arc normalised in the first 45 degrees 
octant (mirroring for 45 -90 etc)
then figuring what other octants to draw it in.

*/
namespace {
   // 0.25 deg resolution between 0 and 45 degrees
   // should be a separate lib
  constexpr float fast_tan_array[] = {
       0.f
      ,0.00436335f
      ,0.00872687f
      ,0.0130907f
      ,0.0174551f
      ,0.0218201f
      ,0.0261859f
      ,0.0305528f
      ,0.0349208f
      ,0.0392901f
      ,0.0436609f
      ,0.0480334f
      ,0.0524078f
      ,0.0567841f
      ,0.0611626f
      ,0.0655435f
      ,0.0699268f
      ,0.0743128f
      ,0.0787017f
      ,0.0830936f
      ,0.0874887f
      ,0.0918871f
      ,0.096289f
      ,0.100695f
      ,0.105104f
      ,0.109518f
      ,0.113936f
      ,0.118358f
      ,0.122785f
      ,0.127216f
      ,0.131653f
      ,0.136094f
      ,0.140541f
      ,0.144993f
      ,0.149451f
      ,0.153915f
      ,0.158384f
      ,0.16286f
      ,0.167343f
      ,0.171831f
      ,0.176327f
      ,0.180829f
      ,0.185339f
      ,0.189856f
      ,0.19438f
      ,0.198912f
      ,0.203452f
      ,0.208f
      ,0.212557f
      ,0.217121f
      ,0.221695f
      ,0.226277f
      ,0.230868f
      ,0.235469f
      ,0.240079f
      ,0.244698f
      ,0.249328f
      ,0.253968f
      ,0.258618f
      ,0.263278f
      ,0.267949f
      ,0.272631f
      ,0.277325f
      ,0.282029f
      ,0.286745f
      ,0.291473f
      ,0.296214f
      ,0.300966f
      ,0.305731f
      ,0.310508f
      ,0.315299f
      ,0.320103f
      ,0.32492f
      ,0.329751f
      ,0.334595f
      ,0.339454f
      ,0.344328f
      ,0.349216f
      ,0.354119f
      ,0.359037f
      ,0.36397f
      ,0.368919f
      ,0.373885f
      ,0.378866f
      ,0.383864f
      ,0.388879f
      ,0.39391f
      ,0.39896f
      ,0.404026f
      ,0.409111f
      ,0.414214f
      ,0.419335f
      ,0.424475f
      ,0.429634f
      ,0.434812f
      ,0.440011f
      ,0.445229f
      ,0.450467f
      ,0.455726f
      ,0.461006f
      ,0.466308f
      ,0.471631f
      ,0.476976f
      ,0.482343f
      ,0.487733f
      ,0.493145f
      ,0.498582f
      ,0.504041f
      ,0.509525f
      ,0.515034f
      ,0.520567f
      ,0.526125f
      ,0.531709f
      ,0.537319f
      ,0.542956f
      ,0.548619f
      ,0.554309f
      ,0.560027f
      ,0.565773f
      ,0.571547f
      ,0.57735f
      ,0.583183f
      ,0.589045f
      ,0.594938f
      ,0.600861f
      ,0.606815f
      ,0.612801f
      ,0.618819f
      ,0.624869f
      ,0.630953f
      ,0.63707f
      ,0.643222f
      ,0.649408f
      ,0.655629f
      ,0.661886f
      ,0.668179f
      ,0.674509f
      ,0.680876f
      ,0.687281f
      ,0.693725f
      ,0.700208f
      ,0.70673f
      ,0.713293f
      ,0.719897f
      ,0.726543f
      ,0.73323f
      ,0.739961f
      ,0.746735f
      ,0.753554f
      ,0.760418f
      ,0.767327f
      ,0.774283f
      ,0.781286f
      ,0.788337f
      ,0.795436f
      ,0.802585f
      ,0.809784f
      ,0.817034f
      ,0.824336f
      ,0.831691f
      ,0.8391f
      ,0.846563f
      ,0.854081f
      ,0.861655f
      ,0.869287f
      ,0.876977f
      ,0.884725f
      ,0.892534f
      ,0.900404f
      ,0.908336f
      ,0.916331f
      ,0.92439f
      ,0.932515f
      ,0.940706f
      ,0.948965f
      ,0.957292f
      ,0.965689f
      ,0.974157f
      ,0.982697f
      ,0.991311f
   };

constexpr float fast_tan(angle_type const & in)
{
  return fast_tan_array[
      quan::constrain(
         static_cast<int>(in.numeric_value() * 4 + 0.5f), 0, 179
      )
  ];
  
}

  angle_type normalise_angle (angle_type const & angle_in)
   {
      auto angle = angle_in;
      while ( angle >=angle_type{360.f}){
            angle -=angle_type{360.f};
      }
      while (angle <angle_type{0.f}){
          angle +=angle_type{360.f};
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
  angle_type map_angle_to_zero_octant (angle_type const & angle, int octant)
   {
      if (octant & 1) {
            return (octant + 1) *angle_type {45.f} - angle;
         }
      else {
            return angle -angle_type {45.f} * octant;
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
     angle_type start_angle,
     angle_type end_angle,
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
           ? fast_tan (map_angle_to_zero_octant (end_angle, start_octant))
           : fast_tan (map_angle_to_zero_octant (start_angle, start_octant));
         float const end_slope
            = (start_octant & 1)
           ? fast_tan (map_angle_to_zero_octant (start_angle, end_octant))
           : fast_tan (map_angle_to_zero_octant (end_angle, end_octant));

         int mask = 1 << start_octant;
         plot_arc_1st_octant1 (mask,centre,radius,start_slope,end_slope,c);
     }else {
         float const start_slope0
         = (start_octant & 1)
           ? 0
           : fast_tan (map_angle_to_zero_octant (start_angle, start_octant));
         float const end_slope0
            = (start_octant & 1)
           ? fast_tan (map_angle_to_zero_octant (start_angle, start_octant))
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
           : fast_tan (map_angle_to_zero_octant (end_angle, end_octant));
          float const end_slope1
            = ((end_octant & 1) == 0)
            ? fast_tan (map_angle_to_zero_octant (end_angle, end_octant))
            : 1;
          int end_mask = 1 << end_octant;
          plot_arc_1st_octant1 (end_mask,centre,radius,start_slope1, end_slope1,c);
      }
   }
} // namespace

void  quan::uav::osd::draw_arc(
   int32_t radius,
   pxp_type const & pos, 
   angle_type const & start_angle_in,
   angle_type const & end_angle_in,
   colour_type c
)
{
   auto const start_angle = normalise_angle(start_angle_in);
   auto const end_angle = normalise_angle(end_angle_in);
   if ( end_angle != start_angle){
      if ( end_angle > start_angle){
         normalised_arc(pos,radius,start_angle, end_angle, c);
      }else{
         normalised_arc(pos,radius, start_angle,angle_type{360.f},c);
         normalised_arc(pos,radius,angle_type{0.f},end_angle,c);
      }
   }
}
