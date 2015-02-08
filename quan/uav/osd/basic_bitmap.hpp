#ifndef QUAN_UAV_OSD_BASIC_BITMAP_HPP_INCLUDED
#define QUAN_UAV_OSD_BASIC_BITMAP_HPP_INCLUDED

#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd{

   struct basic_bitmap{
      virtual size_type get_size() const = 0;
      static uint32_t constexpr get_bits_px() { return 2U;}
      // basically ram or rom
      virtual uint8_t const * get_data() const=0;
      quan::uav::osd::colour_type 
      get_pixel_colour(quan::two_d::vect<int32_t> const & pos)const
      {
         quan::uav::osd::size_type const size_px = this->get_size();
         if (     (pos.x >= 0 ) 
               && (pos.x < size_px.x) 
               && (pos.y >= 0) 
               && (pos.y < size_px.y)
         ){
            uint32_t constexpr bits_px = get_bits_px();
            uint32_t const y_bit_pos = pos.y * size_px.x * bits_px;
            uint32_t const px_pos = y_bit_pos + pos.x * bits_px;
            uint32_t const byte_pos = px_pos / 8U;
            uint32_t const bit_pos = px_pos % 8U;
            uint8_t const val = static_cast<uint8_t>(((this->get_data())[byte_pos] >> bit_pos) & 0x03)  ;  
            return static_cast<quan::uav::osd::colour_type>(val); 
         }else{
            return quan::uav::osd::colour_type::transparent;
         }
      }

      uint32_t get_data_size() const
      {
         auto const size = this->get_size();
         int32_t const size_bits = size.x * size.y * get_bits_px() ;
         return  size_bits / 8U + (((size_bits % 8U) != 0)?1U:0U);
      }
      protected:
         basic_bitmap(){}
         virtual ~basic_bitmap(){}

      private:
         //basic_bitmap ( basic_bitmap const &) = delete;
         basic_bitmap & operator = ( basic_bitmap const &) = delete;
   }; 
   
}}} // quan::uav::osd

#endif // QUAN_UAV_OSD_BASIC_BITMAP_HPP_INCLUDED
