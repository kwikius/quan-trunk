#ifndef QUAN_GX_WXWIDGETS_FROM_WXSTRING_HPP_INCLUDED
#define QUAN_GX_WXWIDGETS_FROM_WXSTRING_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
