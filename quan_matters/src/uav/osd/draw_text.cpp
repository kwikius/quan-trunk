
#include <quan/uav/osd/api.hpp>

// pos in transformed coords
// text origin is at lower left of first charact
//namespace quan{ namespace uav { namespace osd{

void quan::uav::osd::draw_text(text_ptr str,  pxp_type const & pos_in, font_ptr font)
{
   if (( font != nullptr) && ( str != nullptr )){
      pxp_type pos = pos_in;
      for (const char* ptr = str; *ptr != '\0'; ++ptr) {
         bitmap_ptr char_bmp = get_char(font, (int32_t)((uint8_t)(*ptr))); // try to make characters above 127 work!
         size_type const bmp_size = get_size(char_bmp);
         if (char_bmp) {
            draw_bitmap(char_bmp,pos);
            pos.x += bmp_size.x;
         }
      }
   }
}

