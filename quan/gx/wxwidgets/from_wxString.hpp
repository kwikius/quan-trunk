#ifndef QUAN_GX_WXWIDGETS_FROM_WXSTRING_HPP_INCLUDED
#define QUAN_GX_WXWIDGETS_FROM_WXSTRING_HPP_INCLUDED

#include <wx/wx.h>
#include <string>

namespace quan{ namespace gx{ namespace wxwidgets{

   template <typename CharType> 
   std::basic_string<CharType> from_wxString(wxString const & str);

   template<>
   inline
   std::basic_string<char> from_wxString<char>(wxString const & str)
   {
       return(const char*) str.mb_str(wxConvUTF8);
   }
}}}

#endif // QUAN_GX_WXWIDGETS_FROM_WXSTRING_HPP_INCLUDED
