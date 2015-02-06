#ifndef QUAN_UAV_OSD_DYNAMIC_FONT_HPP_INCLUDED
#define QUAN_UAV_OSD_DYNAMIC_FONT_HPP_INCLUDED

#include <vector>
#include <string>
#include <quan/uav/osd/basic_font.hpp>

namespace quan { namespace uav{ namespace osd{ namespace dynamic{

struct font : quan::uav::osd::basic_font{
    virtual std::string const & get_name()const =0;
   // virtual int get_index() const = 0;
protected:
   font(){}
   virtual ~font(){}
private:
   font & operator = ( font const &) = delete;
   font ( font const &) = delete;
};

}}}} // quan::uav::osd::dynamic

#endif //QUAN_UAV_OSD_DYNAMIC_FONT_HPP_INCLUDED
