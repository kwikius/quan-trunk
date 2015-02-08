#ifndef QUAN_UAV_OSD_DETAIL_WRITABLE_BITMAP_HPP_INCLUDED
#define QUAN_UAV_OSD_DETAIL_WRITABLE_BITMAP_HPP_INCLUDED


#include <iosfwd>
#include <quan/uav/osd/basic_bitmap.hpp>

namespace quan{ namespace uav{ namespace osd{ namespace detail{

   struct writable_bitmap : quan::uav::osd::basic_bitmap{
      writable_bitmap();
      writable_bitmap(quan::uav::osd::size_type const & size_in); 
      ~writable_bitmap();
      void set_pixel( 
         quan::two_d::vect<int32_t> const & pos,
         quan::uav::osd::color_type c
      );
      quan::uav::osd::size_type get_size() const;
      uint8_t const * get_data() const;
      bool output_header (
         std::string const & bitmap_typename, 
         std::string const & bitmap_objectname, 
         std::ostream & out
      );
      void set_size(quan::uav::osd::size_type const & size_in);
      bool clear();
   protected:
      writable_bitmap(writable_bitmap const & in);
      
   private:
      bool copy_from(quan::uav::osd::basic_bitmap const & in);
      quan::uav::osd::size_type m_size;
      uint8_t * m_data;
      writable_bitmap & operator =(writable_bitmap const &) = delete;
   };

}}}} //quan::uav::osd::detail


#endif //QUAN_UAV_OSD_DETAIL_WRITABLE_BITMAP_HPP_INCLUDED
