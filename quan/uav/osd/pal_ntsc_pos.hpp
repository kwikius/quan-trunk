#ifndef QUAN_UAV_OSD_PAL_NTSC_POS_HPP_INCLUDED
#define QUAN_UAV_OSD_PAL_NTSC_POS_HPP_INCLUDED

#include <cstdint>
#include <quan/two_d/vect.hpp>
#include <quan/uav/osd/get_video_mode.hpp>

/* 
   returns a pxp_type adjusted dependent on cuurnet osd video mode
*/

namespace quan{ namespace uav{ namespace osd{

   struct pal_ntsc_pos {

      constexpr pal_ntsc_pos (int32_t xpos,int32_t ypos_pal, int32_t ypos_ntsc)
      : m_xpos{xpos}, m_ypos_pal{ypos_pal},m_ypos_ntsc{ypos_ntsc}{}

      void set_xpos(int32_t val) { m_xpos = val;}
      void set_ypos(int32_t pal_val,int32_t ntsc_val) 
      { m_ypos_pal = pal_val; m_ypos_ntsc = ntsc_val;}

      // conversion to a pxp_type
      // to use:
      // pxp_type p = value_of_type_pal_ntsc_pos;
      operator quan::two_d::vect<int32_t>()const
      {
         return { m_xpos,((get_video_mode() == video_mode::pal)?m_ypos_pal:m_ypos_ntsc)};
      }

   private:

      int32_t m_xpos;
      int32_t m_ypos_pal;
      int32_t m_ypos_ntsc;
   };

}}}


#endif // QUAN_UAV_OSD_PAL_NTSC_POS_HPP_INCLUDED
