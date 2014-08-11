#ifndef QUAN_HTML2_RAW_HPP_INCLUDED
#define QUAN_HTML2_RAW_HPP_INCLUDED
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

#include <quan/html2/body_content.hpp>

/*
   output raw html stuff with no processing
*/

#include <string>

namespace quan{ namespace html2{
   
   struct raw : body_content{

      raw(std::string * in) : m_pstr(in){}
      ~raw(){delete m_pstr;}

      std::ostream & output(std::ostream & os)const
      {
         os << *m_pstr ;
         return os;
      }
      bool is_inline_element()const {return true;}
      
   private:
      std::string*  m_pstr;
   };


}}//quan::html2


#endif

