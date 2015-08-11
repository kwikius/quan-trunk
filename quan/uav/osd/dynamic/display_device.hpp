#ifndef QUAN_OSD_DYNAMIC_DISPLAY_DEVICE_HPP_INCLUDED
#define QUAN_OSD_DYNAMIC_DISPLAY_DEVICE_HPP_INCLUDED

#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd {namespace dynamic{

   struct display_device{
   typedef quan::uav::osd::pxp_type pxp_type;
   typedef quan::uav::osd::colour_type colour_type;
   typedef quan::uav::osd::size_type size_type;
   virtual pxp_type       transform_to_raw(pxp_type const & pos)const = 0;
   virtual pxp_type       transform_from_raw(pxp_type const & pos) const = 0;
   virtual void           set_pixel_raw(pxp_type const & px,colour_type c) = 0;
   virtual colour_type    get_pixel_raw(pxp_type const & px) const=0;
   virtual bool           set_clip_rect(pxp_type const & minimums, 
                                       pxp_type const & maximums)=0;
   virtual void           set_display_buffer(uint32_t offset32,uint32_t mask,colour_type c)=0;
   virtual size_type      get_display_size()const = 0;
 //  protected:
                          display_device(){}
      virtual             ~display_device(){}
   private:
      display_device (display_device const &) = delete;
      display_device & operator = (display_device const &) = delete;
   };

}}}}

#endif // QUAN_OSD_DYNAMIC_DISPLAY_DEVICE_HPP_INCLUDED
