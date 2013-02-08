#ifndef QUAN_NUMBITS_HPP_INCLUDED
#define QUAN_NUMBITS_HPP_INCLUDED

#include <quan/meta/numbits.hpp>

namespace quan {

   template <typename T>
   inline
   std::size_t numbits(){
     return quan::meta::numbits<T>::value;
   };

}


#endif // QUAN_NUMBITS_HPP_INCLUDED
