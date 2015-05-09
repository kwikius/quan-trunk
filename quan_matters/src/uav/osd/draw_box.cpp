
#include <cmath>
#include <cstdlib>
#include <utility>

#include <quan/uav/osd/api.hpp>

   // transformed coords
void quan::uav::osd::draw_box(
   pxp_type const & p0_in, 
   pxp_type const & p1_in, 
   colour_type c,
   bool filled
)
{
   int32_t i,j;

   pxp_type p0 = transform_to_raw(p0_in) ;
   pxp_type p1 = transform_to_raw(p1_in);

   if(p0.x > p1.x) std::swap(p0.x,p1.x);
   if(p0.y > p1.y) std::swap(p0.y,p1.y);


   if(filled)
   {
	   for(i=p0.x; i<=p1.x; i++)
	   {
		   for(j=p0.y; j<=p1.y; j++)
		   {
		         set_pixel_raw({i,j},c);
		   }
	   }
   }
   else
   {
	   j = p0.y;
	   for(i=p0.x; i<=p1.x; i++)
		   set_pixel_raw({i,j},c);

	   i = p1.x;
	   for(j=p0.y; j<=p1.y; j++)
		   set_pixel_raw({i,j},c);

	   j = p1.y;
	   for(i=p1.x; i>=p0.x; i--)
		   set_pixel_raw({i,j},c);

	   i = p0.x;
	   for(j=p1.y; j>=p0.y; j--)
		   set_pixel_raw({i,j},c);

   }
}


