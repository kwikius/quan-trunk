
#include <quan/uav/osd/api.hpp>

using namespace quan::uav::osd;
/*
void           draw_text(text_ptr str, pxp_type const & pos,font_ptr font);
*/
// pos in transformed coords
// text origin is at lower left of first charact
namespace quan{ namespace uav { namespace osd{

   void draw_text(text_ptr str,  pxp_type const & pos_in, font_ptr font)
   {
      if (( font != nullptr) && ( str != nullptr )){
         pxp_type pos = pos_in;
         for (const char* ptr = str; *ptr != '\0'; ++ptr) {
            bitmap_ptr char_bmp = get_char(font, *ptr);
            size_type const bmp_size = get_size(char_bmp);
            if (char_bmp) {
               draw_bitmap(char_bmp,pos);
               pos.x += bmp_size.x;
            }
         }
      }
   }

}}} //quan::uav::osd
