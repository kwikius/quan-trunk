#include <quan/uav/osd/api.hpp>
#include <quan/min.hpp>
#include <quan/max.hpp>

using namespace quan::uav::osd;
namespace {
   // have a buffer_bit_pos fledgling fun in video_buffer.hpp line 166
   // which should be used
   //raw screen units

   size_type current_display_size ;
   inline uint32_t get_bitoffset(pxp_type const & pos)
   {
#if defined  QUANTRACKER_AIR_OSD_PC_SIM_MODE
//#error test
      return static_cast<uint32_t> (pos.y) * (current_display_size.x)
         + static_cast<uint32_t> (pos.x);
#else 
      return static_cast<uint32_t> (pos.y) * (current_display_size.x + 8)
         + static_cast<uint32_t> (pos.x) + 1U;
#endif
   }
#if 0
   inline uint32_t get_offset32(pxp_type const & pos)
   { 
      return get_bitoffset(pos) / 32;
   }

   inline uint32_t get_bitoffset_in_word32(pxp_type const & pos)
   {
      return get_bitoffset(pos) % 32;
   }
#endif
  
   // return false if line not on display
   // raw pos units
   bool truncate_horz_line_to_screen(pxp_type const& from_in, int len_in, pxp_type& from_out, int & len_out)
   {
      if ((from_in.y < 0) || 
         (from_in.y >= current_display_size.y) || 
         ( from_in.x >= current_display_size.x) ) {
         return false;
      }
      
      auto const end_x = quan::min(from_in.x + len_in, current_display_size.x);
      if ( end_x <= 0){
         return false;
      }
      from_out.x = quan::max(from_in.x,0);
      from_out.y = from_in.y;
      len_out = end_x - from_out.x;
      return true;
   }

}

 // left from is at leftend of line
 // len is length to right
void quan::uav::osd::draw_horizontal_line(pxp_type from , uint32_t len, colour_type colour)
{
   // if len < some_value) {
    //  just do normal line
   //}
   pxp_type from1; // returned in raw
   int len1;
   current_display_size = get_display_size();
   if (! truncate_horz_line_to_screen(transform_to_raw(from),len,from1,len1) ){
      return;
   }
   uint32_t const start_bit_offset = get_bitoffset(from1);
   uint32_t const start_w32_offset = start_bit_offset / 0x20;
   uint32_t const start_bit_in_w32  = start_bit_offset % 0x20;
   uint32_t const end_bit_offset = start_bit_offset + (len1 -1);
   uint32_t const end_w32_offset   = end_bit_offset / 0x20;
   uint32_t const end_bit_in_w32  =  end_bit_offset % 0x20;
   // assumes that display is zero and 
   // writing 1's sets
   if ( start_w32_offset != end_w32_offset)
   {
      set_display_buffer(start_w32_offset,0xFFFFFFFF << start_bit_in_w32,colour);
      for  ( uint32_t i = start_w32_offset + 1; i < end_w32_offset; ++i){
         set_display_buffer(i,0xffffffff,colour);
      }
      set_display_buffer(end_w32_offset,~(0xFFFFFFFE << end_bit_in_w32),colour);
   }else{
      uint32_t const mask = (0xFFFFFFFF << start_bit_in_w32) & ~(0xFFFFFFFE << end_bit_in_w32);
      set_display_buffer(start_w32_offset,mask,colour);
   }
}

