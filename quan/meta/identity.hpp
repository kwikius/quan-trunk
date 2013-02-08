#ifndef QUAN_META_IDENTITY_HPP_INCLUDED
#define QUAN_META_IDENTITY_HPP_INCLUDED

// Copyright Andrew Little 2006-2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{namespace meta{
   
   template<typename T>
   struct identity{
      typedef T type;
   };
            
}}//quan::meta

#endif
