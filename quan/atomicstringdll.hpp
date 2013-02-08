

/*
   quan::atomicstring<char_type> is used for holding strings for fat lookup.
   When an atomic_string is constructed from a C-stylestring the string is 
   looked up in the sybmol table and a char* is returned
   The char* returned will not be the same as the input one
   but will be a pointer to a string of the same characters
   and thereafter will always be the same for same charcters.
   comparison of atomicstrings is fast, as only 2 char* need be compared
   but compare is of pointers , not lexographical comparison.
   
*/

#ifndef QUAN_ATOMICSTRINGDLL_HPP_INCLUDED
#define QUAN_ATOMICSTRINGDLL_HPP_INCLUDED

#include <windows.h>
#include <iostream>

#ifdef ATOMICSTRINGDLL_EXPORTS
#define ATOMICSTRINGDLL_API __declspec(dllexport)
#else
#define ATOMICSTRINGDLL_API __declspec(dllimport)
#endif

namespace quan{
  
   template <typename CharType>
   struct ATOMICSTRINGDLL_API atomicstring{

         atomicstring(CharType const * in);
       
         CharType const * get_rep() const
         {
            return rep;
         }
         
      private:
      CharType const * rep;
   };

   template <typename Chartype>
   inline 
   bool operator == (
      atomicstring<Chartype> const & lhs,
      atomicstring<Chartype> const & rhs
   ){
      return lhs.get_rep() == rhs.get_rep();
   }
   template <typename Chartype>
   inline 
   bool operator != (
      atomicstring<Chartype> const & lhs,
      atomicstring<Chartype> const & rhs
   ){
      return lhs.get_rep() != rhs.get_rep();
   }
   template <typename Chartype>
   inline 
   bool operator < (
      atomicstring<Chartype> const & lhs,
      atomicstring<Chartype> const & rhs
   ){
      return lhs.get_rep() < rhs.get_rep();
   }
               
   template <typename CharType>
   inline
   std::basic_ostream<CharType> & operator << (
         std::basic_ostream<CharType> & os, 
         atomicstring<CharType> const & atom
   ){
     return  os << atom.get_rep();
   }

}//quan


#endif

