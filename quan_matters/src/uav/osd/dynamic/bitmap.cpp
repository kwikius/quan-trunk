#include <wx/bitmap.h>
#include <wx/rawbmp.h>

#include <quan/uav/osd/dynamic/bitmap.hpp>

/*
box represents how far to move each part
As  bitmap is text mode
bottom >= top
*/
bool quan::uav::osd::dynamic::bitmap::resize (quan::two_d::box<int> const & new_box)
{
   quan::two_d::vect<int> cur_size = this->get_size();
   // size of new box
   
   quan::two_d::vect<int> new_size{ 
         cur_size.x + new_box.right - new_box.left
         ,cur_size.y + new_box.bottom - new_box.top
   };
                    
   bitmap temp_bmp{this->get_name(),new_size};
   // temp_bmp is constructed with all cells transparent
   
   for (int y = 0 ; y < new_size.y; ++y) {
      int const old_bitmap_y = y + new_box.top;
      if ( (old_bitmap_y >= 0) && ( old_bitmap_y < cur_size.y) ) {
         for (int x = 0; x < new_size.x; ++x) {
           int const old_bitmap_x = x + new_box.left;
           if ( ( old_bitmap_x >= 0) && ( old_bitmap_x < cur_size.x)) {
                 colour_type c =this->get_pixel_colour({old_bitmap_x,old_bitmap_y});
                 temp_bmp.set_pixel({x,y},c);
            }
         }
      }
   }
  // this->m_data = temp_bmp.m_data;
  // this->m_size = temp_bmp.m_size;
   return true;
}
#if 0
quan::uav::osd::color_type 
quan::uav::osd::dynamic::bitmap::get_pixel_colour (pos_type const & p) const
{
   if ( (p.x >= m_size.x) || (p.y >= m_size.y)) {
         return colour::transparent;
   }
   auto idx = p.y * m_size.x + p.x;
   return m_data.at (idx);
}


bool quan::uav::osd::dynamic::bitmap::set_pixel_colour (pos_type const & p, quan::uav::osd::color_type c)
{
   if ( (p.x >= m_size.x) || (p.y >= m_size.y)) {
         return false;
   }
   auto idx = p.y * m_size.x + p.x;
   m_data.at (idx) = c;
   return true;
}
#endif
 