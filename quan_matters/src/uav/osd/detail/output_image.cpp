
#if ! defined __MBED__

#include <iostream>
#include <quan/uav/osd/detail/output_image.hpp>
#include <quan/uav/osd/basic_bitmap.hpp>

void quan::uav::osd::detail::output_image (bitmap_ptr pic, std::ostream & out)
{
   if (!pic) {
      return ;
   }
   auto const size_px = pic->get_size();
   auto const bits_px = pic->get_bits_px();
   uint8_t const * data = pic->get_data();
   for (int32_t y = 0; y < size_px.y; ++y) {
      int32_t const y_bit_pos = y * size_px.x * bits_px;
      for (int32_t x = 0; x < size_px.x; ++x) {
         int32_t const px_pos = y_bit_pos + x * bits_px;
         int32_t const byte_pos = px_pos / 8;
         int32_t const bit_pos = px_pos % 8;
         int32_t const val = (data[byte_pos]>> bit_pos) &  0x03  ;
         typedef quan::uav::osd::colour_type colour_type;
         colour_type const col = static_cast<colour_type>(val);
         switch (col) {
         case  colour_type::grey:
            out << ".";
            break;
         case  colour_type::white:
            out << "#";
            break;
         case  colour_type::black:
             out << " ";
            break;
         case colour_type::transparent:
            out << "~";
            break;
         default:
            out << "?";
            break;
         }
      }
      out << "\n";
   }
}
#endif

