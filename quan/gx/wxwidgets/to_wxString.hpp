#ifndef QUAN_GX_WXWIDGETS_TO_WXSTRING_HPP_INCLUDED
#define QUAN_GX_WXWIDGETS_TO_WXSTRING_HPP_INCLUDED

#include <wx/wx.h>
#include <quan/to_string.hpp>

namespace quan{ namespace gx{ namespace wxwidgets{

   template <typename T>
   inline
   wxString to_wxString(T const & v)
   {   
       std::basic_string<wchar_t> str = quan::to_string<wchar_t>(v);
       return wxString(str);
   }

}}}

#endif // QUAN_GX_WXWIDGETS_TO_WXSTRING_HPP_INCLUDED
