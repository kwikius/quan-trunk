#ifndef QUAN_DETAIL_C_STR_WRAPPER_HPP_INCLUDED
#define QUAN_DETAIL_C_STR_WRAPPER_HPP_INCLUDED

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
