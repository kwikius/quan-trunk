
#include <cassert>

#include <quan/uav/osd/dynamic/display_device.hpp>
#include <quan/uav/osd/dynamic/object_database.hpp>

#include <quan/uav/osd/get_aircraft_position.hpp>
#include <quan/uav/osd/get_home_position.hpp>
#include <quan/uav/osd/get_aircraft_attitude.hpp>
#include <quan/uav/get_bearing.hpp>
#include <quan/uav/get_distance.hpp>
#include <quan/uav/osd/get_aircraft_heading.hpp>
#include <quan/uav/osd/basic_bitmap.hpp>
#include <quan/uav/osd/basic_font.hpp>

#include "aircraft.hpp"

namespace{
  quan::uav::osd::dynamic::object_database const * the_database; 
  aircraft  the_aircraft;
  quan::uav::osd::dynamic::display_device* the_device;

  aircraft const & get_aircraft() 
   { 
      return the_aircraft;
   }
    
   quan::uav::osd::dynamic::object_database const & get_database()
   {
     assert(the_database);
     return *the_database;
   }
   
   quan::uav::osd::dynamic::display_device & get_device()
   {
     assert( the_device);
     return * the_device;
   }

}

#define QUAN_DLL_EXPORT __attribute__((visibility ("default")))
#define QUAN_DLL_LOCAL __attribute__((visibility ("hidden")))
//namespace quan{ namespace uav{ namespace osd{

   QUAN_DLL_LOCAL quan::uav::osd::pxp_type  
   quan::uav::osd::transform_to_raw(pxp_type const & pos)
   {
       return get_device().transform_to_raw(pos);
   }

   QUAN_DLL_LOCAL quan::uav::osd::pxp_type 
   quan::uav::osd::transform_from_raw(pxp_type const & pos)
   {
      return get_device().transform_from_raw(pos);
   }
   QUAN_DLL_LOCAL void quan::uav::osd::set_pixel_raw(pxp_type const & px,colour_type c)
   {
      get_device().set_pixel_raw(px,c);
   }
   QUAN_DLL_LOCAL quan::uav::osd::colour_type    
   quan::uav::osd::get_pixel_raw(pxp_type const & px)
   {
      return  get_device().get_pixel_raw(px);
   }

   QUAN_DLL_LOCAL quan::uav::osd::colour_type 
   quan::uav::osd::get_pixel_raw(bitmap_ptr bmp,pxp_type const & pos)
   {
      return bmp->get_pixel_colour(pos);
   }

   QUAN_DLL_LOCAL void 
   quan::uav::osd::set_clip_rect(pxp_type const & minimums, pxp_type const & maximums)
   {
       get_device().set_clip_rect(minimums,maximums);
   }

   QUAN_DLL_LOCAL quan::uav::osd::size_type
   quan::uav::osd::get_display_size()
   {
      return get_device().get_display_size();
   }
        // fonts
   QUAN_DLL_LOCAL quan::uav::osd::font_ptr 
   quan::uav::osd::get_font( uint32_t i)
   {
      return get_database().get_font_at(i);
   }

   QUAN_DLL_LOCAL quan::uav::osd::pxp_type 
   quan::uav::osd::get_size( font_ptr p)
   {
      return p->get_size();
   }

   QUAN_DLL_LOCAL quan::uav::osd::bitmap_ptr 
   quan::uav::osd::get_char(font_ptr f, int32_t i)
   {
      return f->get_char_at(i);
   }

   // bitmaps
   QUAN_DLL_LOCAL quan::uav::osd::bitmap_ptr 
   quan::uav::osd::get_bitmap(uint32_t i)
   {
      return get_database().get_bitmap_at(i);
   }

   QUAN_DLL_LOCAL quan::uav::osd::pxp_type 
   quan::uav::osd::get_size( bitmap_ptr p)
   {
      return p->get_size();
   }

   quan::uav::osd::position_type const & 
   quan::uav::osd::get_aircraft_position()
    {
        return get_aircraft().get_position();
    }

    quan::uav::osd::position_type const & 
    quan::uav::osd::get_home_position()
    {
       return get_aircraft().get_home_position();
    }

    quan::uav::osd::attitude_type const & 
    quan::uav::osd::get_aircraft_attitude()
    {
       return get_aircraft().get_attitude();
    }

    quan::uav::osd::angle_type 
    quan::uav::osd::get_aircraft_heading()
    {
       return get_aircraft().get_heading();
    }
/*
 required. The Bitmap maker will call this function
 to set up these two pointers
 At this point this lib should load
 or reload its own readonly version of the database
 So it can use array syntax
 Maybe call this initialise
 Or a fake syntax
  bitmap* operator [] ( int i) const
{
   std::string str = bitmap_names[i];
   return the_database. find_bitmap_by_name(str)
}
*/
extern "C" QUAN_DLL_EXPORT void set_osd_on_draw_params(
      quan::uav::osd::dynamic::object_database const * db)
{
   the_database = db;   
}

/*
   The Bitmap maker will call this function to draw the bitmap.
   Internally want this to look exactly like the API on the board
*/
extern "C" QUAN_DLL_EXPORT void osd_on_draw( quan::uav::osd::dynamic::display_device & d)
{
    if ( the_database != nullptr){
      the_device = &d;
      quan::uav::osd::on_draw();
    }
}