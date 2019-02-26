#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED
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

// we dont want any c++ streams 
// so only C constructs used
//#include <utility>
#include <quan/malloc_free.hpp>
#include <string.h>

namespace quan{

  /*
      if string is empty then underlying array points to to zero terminator empty string
      so string pointer is never invalid
  */

  struct string{

     string()
     :m_c_str{&empty_string}{ 
      //std::cout << "default ctor\n";
      } // empty
     ~string(){ clean();}
     string(const char* str)
     :m_c_str{&empty_string}{
       // std::cout << "const char* ctor\n";
        this->ll_copy_in_c_str(str);
     }

     string (string const& str)
     :m_c_str{&empty_string}
     {
        //std::cout << "string ctor\n";
        this->ll_copy_in_c_str(str.m_c_str);
     }

     string (string&& str)
     :m_c_str{str.m_c_str}
     {
       // std::cout << "rvalue ctor\n";
        str.m_c_str = &empty_string;
     }

     string & operator = (string const & str)
     {
			if (this != &str){
            this->ll_copy_in_c_str(str.m_c_str);
         }
         return *this;
     }

     string & operator = (string && str)
     {
       if ( this != &str){
           clean();
           this->m_c_str = str.m_c_str;
           str.m_c_str = &empty_string;
       }
       return *this;
     }

     string & operator = (const char* cstr)
     {
        ll_copy_in_c_str(cstr);
        return * this;
     }

     string & operator += (const char* cstr)
     {
      if ( cstr && (cstr != &empty_string) ){
         auto const len = strlen(cstr);
         if ( len > 0){
            auto const len1 = strlen(m_c_str);
            auto new_string = static_cast<char*>(quan::malloc(len + len1 +1U));
            memcpy(new_string,m_c_str,len1);
            strcpy(new_string + len1,cstr);
            // strcpy(this->m_c_str,str);
            clean();
            m_c_str = new_string;
         }
      }
      return *this;
     }
     string & operator += (string const & str)
     {
        return string::operator +=(str.get());
     }

     string & operator += (char c)
     {
         auto const len = strlen(m_c_str);
         auto new_string = static_cast<char*>(quan::malloc(len + 2U));
         if ( len > 0){
            memcpy(new_string,m_c_str,len);
         }
         new_string[len] = c;
         new_string[len+1] = '\0';
         clean();
         m_c_str = new_string;
         return *this;
     }

     const char* get() const
     {
        return m_c_str;
     }

     static string concat (const char* lhs, const char* rhs)
     {
         if ( lhs && rhs){
            auto lhs_len = strlen(lhs);
            auto rhs_len = strlen(rhs);

            if ( (lhs_len + rhs_len) > 0){
               char* str = static_cast<char*>(quan::malloc(lhs_len + rhs_len + 1));
               memcpy( str,lhs, lhs_len);
               strcpy(str + lhs_len, rhs);
               string result;
               result.move(str);
               return static_cast<string&&>(result);
            }else {
               return string{};
            }
            
         }else {
            if ( lhs){
               return lhs;
            }else {
               if ( rhs) {
                  return rhs;
               }else{
                  return "";
               }
            }
         }
     }

     static string concat (const char* lhs, char rhs)
     {
         if ( lhs && (lhs != &empty_string) ){
            auto lhs_len = strlen(lhs);
            auto str = static_cast<char*>(quan::malloc(lhs_len + 2));
            memcpy(str, lhs,lhs_len);
            str[lhs_len] = rhs;
            str[lhs_len +1] = '\0';
            string result;
            result.move(str);
            return static_cast<string&&>(result);
         } else{
            auto str = static_cast<char*>(quan::malloc(2));
            str[0] = rhs;
            str[1] = '\0';
            string result;
            result.move(str);
            return static_cast<string&&>(result);
         }
     }

//     static   template<typename _Tp>
//    constexpr typename std::remove_reference<_Tp>::type&&
//    move(_Tp&& __t) noexcept
//    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }

     static string concat (char lhs, const char* rhs)
     {
         if ( rhs && (rhs != &empty_string) ){
            auto rhs_len = strlen(rhs);
            auto str = static_cast<char*>(quan::malloc(rhs_len + 2));
           // memcpy(str, lhs,lhs_len);
            str[0] = lhs;
            strcpy(str+1,rhs);
            string result;
            result.move(str);
            return static_cast<string&&>(result);
         } else{
            auto str = static_cast<char*>(quan::malloc(2));
            str[0] = lhs;
            str[1] = '\0';
            string result;
            result.move(str);
            return static_cast<string&&>(result);
         }
     }

     private:

      static char empty_string;
      // copy in if its a valid string
      // else copy in null
      void ll_copy_in_c_str(const char* str)
      {
         clean();
         if ( str && (str != &empty_string)){
            
            auto const len = strlen(str);
            
            if ( len > 0){
               this->m_c_str = static_cast<char*>(quan::malloc(len +1U));
               strcpy(this->m_c_str,str);
            }
         }
      }

      void move( char* str)
      {
         clean();
         if ( str && (str != &empty_string) ){
            m_c_str = str;
         }
      }

      void clean()
      {
         if ( m_c_str != &empty_string){
            quan::free(m_c_str);
            m_c_str = &empty_string;
         }
      }
      char * m_c_str;
     
  };

  inline bool operator == (string const & lhs, string const & rhs)
  {
     return strcmp(lhs.get(), rhs.get()) == 0;
  }

  inline bool operator == (string const & lhs, const char * rhs)
  {
     return strcmp(lhs.get(), rhs) == 0;
  }

  inline bool operator == (const char* lhs, string const & rhs)
  {
     return strcmp(lhs, rhs.get()) == 0;
  }

  inline bool operator != (string const & lhs, string const & rhs)
  {
     return strcmp(lhs.get(), rhs.get()) != 0;
  }

  inline bool operator != (string const & lhs, const char * rhs)
  {
     return strcmp(lhs.get(), rhs) != 0;
  }

  inline bool operator != (const char* lhs, string const & rhs)
  {
     return strcmp(lhs, rhs.get()) != 0;
  }

  inline string operator + (string const & lhs, string const & rhs)
  {
      return static_cast<string&&>(string::concat(lhs.get(),rhs.get()));
  }

  inline string operator + (string const & lhs, const char* rhs)
  {
      return static_cast<string&&>(string::concat(lhs.get(),rhs));
  }

  inline string operator + (const char* lhs, string const & rhs)
  {
      return static_cast<string&&>(string::concat(lhs,rhs.get()));
  }

  inline string operator + (string const & lhs, char rhs)
  {
      return static_cast<string&&>(string::concat(lhs.get(),rhs));
  }

  inline string operator + (char lhs, string const & rhs)
  {
      return static_cast<string&&>(string::concat(lhs,rhs.get()));
  }

}

#endif // STRING_HPP_INCLUDED
