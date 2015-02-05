#ifndef QUAN_UAV_OSD_BASIC_FONT_HPP_INCLUDED
#define QUAN_UAV_OSD_BASIC_FONT_HPP_INCLUDED

#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd{

   // font abstract base class
   struct basic_font {
      virtual int32_t           get_begin() const =0;
      virtual size_type const & get_size() const =0;
      virtual int32_t  get_char_height() const =0
      virtual int32_t  get_char_width() const  =0;
      virual int32_t   get_num_elements() const =0;
      bitmap_ptr       get_char_at(int32_t i)const = 0;
     protected:
      basic_font(){}
      virtual ~basic_font(){}
      //static constexpr int32_t get_bits_px(){ return 2;}
   };

}}}


#endif // QUAN_UAV_OSD_BASIC_FONT_HPP_INCLUDED
