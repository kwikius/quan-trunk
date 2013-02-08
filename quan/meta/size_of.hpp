#ifndef QUAN_META_SIZEOF_HPP_INCLUDED
#define QUAN_META_SIZEOF_HPP_INCLUDED

// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace meta{

   template <typename T> 
   struct size_of{
      enum {value = sizeof(T)};
      typedef size_of type;
   };

}}//quan::meta

#endif

