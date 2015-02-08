
#include <cmath>
#include <cstdlib>
#include <utility>

#include <quan/uav/osd/api.hpp>

   // transformed coords
   // Bressingham
void quan::uav::osd::draw_line(
   pxp_type const & p0_in, 
   pxp_type const & p1_in, 
   colour_type c 
)
{

   pxp_type p0 = transform_to_raw(p0_in) ;
   pxp_type p1 = transform_to_raw(p1_in);

   bool const steep = std::abs(p1.y - p0.y) > std::abs(p1.x - p0.x);

   if (steep){
      std::swap(p0.x,p0.y);
      std::swap(p1.x,p1.y);
   }

   if ( p0.x > p1.x){
      std::swap(p1,p0);
   }

   int const deltax = p1.x - p0.x;
   int const deltay = std::abs(p1.y - p0.y);
   float error = deltax / 2.f;
   int32_t const ystep = (p0.y < p1.y)?1:-1;
   int32_t y = p0.y ;

   for (int32_t x = p0.x ;x < p1.x ; ++x) {
      if (!steep) {
         set_pixel_raw({x,y},c);
      }else{
         set_pixel_raw({y,x},c);
      }
      error -= deltay;
      if (error < 0.0) {
         y     += ystep;
         error += deltax;
      }
   }
}
