#ifndef QUAN_DOM_MAKE_PATH_HPP_INCLUDED
#define QUAN_DOM_MAKE_PATH_HPP_INCLUDED

#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif

#include <list>
#include <string>
#include <quan/atomicstring.hpp>
#include <quan/dom/except.hpp>
#include <sstream>

namespace quan{ namespace dom{

    //throws empty_id_string
   template <typename CharType>
   inline
   std::list<atomicstring<CharType> > make_path( std::basic_string<CharType> const & str_path)
   {
#if defined QUAN_NO_EXCEPTIONS
      assert(( str_path.size() > 0) && " empty path string");
#else
      if (!str_path.size()){
         throw empty_id_string();
      }
#endif
      std::basic_string<CharType> str = str_path;
      if ( str_path.at(0) == '.'){
         str = str_path.substr(1,std::basic_string<CharType>::npos);
      }
#if defined QUAN_NO_EXCEPTIONS
     assert (( str.size() > 0) && " empty path string");
#else
      if (!str.size()){
         throw empty_id_string();
      }
#endif
      std::stringstream s; 
      s << str; 

      std::list<atomicstring<CharType> > tokens; 
      while (! s.eof() ){ 
         std::basic_string<CharType> str; 
         getline(s,str,'.'); 
         tokens.push_back(atomicstring<CharType>(str)); 
      } 
      return tokens;
   }

    //throws empty_id_string

   template <typename CharType>
   inline
   std::list<atomicstring<CharType> > 
   make_path( const CharType* const str_path)
   {
      std::basic_string<CharType> s(str_path); 
      return make_path(s);       
   }

   template <typename CharType>
   inline
   std::list<atomicstring<CharType> > 
   const & make_path( std::list<atomicstring<CharType> > const & in)
   {
      return in;
   }

}}//quan:;dom

#endif

