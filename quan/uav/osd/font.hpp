#ifndef QUAN_UAV_OSD_FONT_HPP_INCLUDED
#define QUAN_UAV_OSD_FONT_HPP_INCLUDED

#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd{

   // font base class
   struct font {
      font();
      ~font();
      int32_t           get_begin() const {return m_begin;}
      size_type const & get_size() const { return m_size;}
      int32_t   get_char_height() const {return m_size.y;}
      int32_t   get_char_width() const  {return m_size.x;}
      static constexpr int32_t get_bits_px(){ return 2;}
     private:
      font & operator = ( font const &) = delete;
      font ( basic_font const &) = delete;
      int32_t m_begin;
      size_type m_size;
      int32_t * m_data;
   };

}}}


#endif // QUAN_UAV_OSD_FONT_HPP_INCLUDED
