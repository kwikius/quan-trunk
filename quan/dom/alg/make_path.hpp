#ifndef QUAN_DOM_MAKE_PATH_HPP_INCLUDED
#define QUAN_DOM_MAKE_PATH_HPP_INCLUDED

#include <list>
#include <string>
#include <quan/dom/except.hpp>
#include <sstream>

namespace quan{ namespace dom{

    //throws empty_id_string
// template <typename ID>
   template <typename CharType>
   inline
   std::list<atomicstring<CharType> > make_path( std::basic_string<CharType> const & str_path)
   {
      if (!str_path.size()){
         throw empty_id_string();
      }
      std::basic_string<CharType> str = str_path;
      if ( str_path.at(0) == '.'){
         str = str_path.substr(1,std::basic_string<CharType>::npos);
      }
      if (!str.size()){
         throw empty_id_string();
      }
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

