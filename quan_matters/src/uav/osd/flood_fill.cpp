// N.B. need alternative to stack
// malloc a fixed size stack
#include <quan/utility/rt_stack.hpp>
#include <quan/uav/osd/api.hpp>

void quan::uav::osd::flood_fill(
   pxp_type const & start_pos, 
   colour_type new_colour, 
   int max_count
)
{
   pxp_type raw_pxp = transform_to_raw(start_pos);
   if ( get_pixel_raw(raw_pxp) == new_colour){
      return;
   } 
   
   auto const display_size = get_display_size();
   
// sanity check
   if (  (raw_pxp.x < 0 ) 
         || (raw_pxp.x >= display_size.x)
         || (raw_pxp.y < 0)
         || (raw_pxp.y >= display_size.y)
   ){
      return;
   }

   quan::rt_stack<pxp_type> stack(max_count);
   stack.push(raw_pxp);
   int count = 0;
   while (! stack.empty()){
      // prob spilled
      if (++ count == max_count){
         return;
      }
      pxp_type n;
      stack.pop(n);
      set_pixel_raw(n,new_colour);
      if ( n.x > 0){
         auto west = pxp_type {n.x-1,n.y};
         if ( get_pixel_raw(west) != new_colour){
            stack.push(west);
         }
      } 
      if ( n.x < static_cast<int>(display_size.x -1)){
         auto east = pxp_type {n.x+1,n.y};
         if ( get_pixel_raw(east) != new_colour){
            stack.push(east);
         }
      }
      if ( n.y > 0){
         auto north = pxp_type {n.x,n.y -1};
         if ( get_pixel_raw(north) != new_colour){
            stack.push(north);
         }
      }
      if( n.y < static_cast<int>(display_size.y -1)){
       auto south = pxp_type {n.x,n.y+1};
       if ( get_pixel_raw(south) != new_colour){
            stack.push(south);
       }
     }
   }
}
