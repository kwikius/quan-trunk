#ifndef QUAN_DETAIL_C_STR_WRAPPER_HPP_INCLUDED
#define QUAN_DETAIL_C_STR_WRAPPER_HPP_INCLUDED
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

#include <cwchar>
#include <cstring>

namespace quan{

   template <typename CharType>
   struct atomicstring;

   namespace detail{
      
      template <typename CharType>
      struct cstr_wrapper{
         friend class quan::atomicstring<CharType>;
       CharType const *  get_charptr() const{ return m_charptr;}
       private:
         cstr_wrapper(CharType const * in)
         : m_charptr(in)
         {
           // assert(in);
         };
         CharType  const * const m_charptr;
         
      };

      inline int comp(cstr_wrapper<char> const & lhs, cstr_wrapper<char> const & rhs)
      {
         return strcmp(lhs.get_charptr(),rhs.get_charptr());
      }

      inline int comp(cstr_wrapper<wchar_t> const & lhs, cstr_wrapper<wchar_t> const & rhs)
      {
         return wcscmp(lhs.get_charptr(),rhs.get_charptr());
      }

      template <typename CharType>
      inline bool operator < (cstr_wrapper<CharType> const & lhs, cstr_wrapper<CharType> const & rhs)
      {
         if (lhs.get_charptr() == rhs.get_charptr()) return false;
         return comp(lhs,rhs) < 0 ;
      }
      template <typename CharType>
      inline bool operator == (cstr_wrapper<CharType> const & lhs, cstr_wrapper<CharType> const & rhs)
      {
         if (lhs.get_charptr() == rhs.get_charptr()) return true;
         return comp(lhs,rhs) == 0 ;
      }
    
      inline  size_t get_strlen(char const * str)
      {
         return strlen(str);
      }

      inline size_t get_strlen(wchar_t const * str)
      {
         return wcslen(str);
      }

      inline char* do_strcpy(char * dest, char const * src)
      {
            return strcpy(dest,src);
      }

      inline wchar_t * do_strcpy(wchar_t * dest, wchar_t const * src)
      {
            return wcscpy(dest,src);
      }

   }
}

#endif // QUAN_DETAIL_C_STR_WRAPPER_HPP_INCLUDED
