#ifndef QUAN_UAV_OSD_DYNAMIC_OBJECT_DATABASE_HPP_INCLUDED
#define QUAN_UAV_OSD_DYNAMIC_OBJECT_DATABASE_HPP_INCLUDED

#include <quan/uav/osd/dynamic/bitmap.hpp>
#include <quan/uav/osd/dynamic/font.hpp>
namespace quan { namespace uav{ namespace osd{ namespace dynamic{

// abc
   struct object_database{
         
      virtual size_t get_num_fonts() const = 0;
      virtual size_t get_num_bitmaps() const = 0;
      virtual quan::uav::osd::dynamic::bitmap * get_bitmap_at(size_t i) const = 0;
      virtual quan::uav::osd::dynamic::font * get_font_at(size_t i) const = 0;
   protected:
      object_database(){}
      virtual ~ object_database(){}
   };

}}}}

#endif // QUAN_UAV_OSD_DYNAMIC_OBJECT_DATABASE_HPP_INCLUDED
