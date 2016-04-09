#ifndef QUAN_GC_HPP_INCLUDED
#define QUAN_GC_HPP_INCLUDED
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

/*
  gc with boehm collector
*/

//#ifdef QUAN_BOEHM_GC
//#error "QUAN_BOEHM_GC already defined elsewhere"
//#else
//#define QUAN_BOEHM_GC
//#endif
//
//#include <gc.h>
#include <malloc.h>

namespace quan{

   inline void gc_init()
   {
      //GC_INIT();
   }

   inline void gc_collect()
   {
     // ::GC_gcollect();
   }

   template <typename T, typename ... Args>
   inline T* gc_malloc(Args... args)
   {
     T * p = reinterpret_cast<T*>(malloc(sizeof(T)));
     return new(p) T{args...};
   }

   template <typename T>
   inline T* gc_malloc()
   {
     T * p = reinterpret_cast<T*>(malloc(sizeof(T)));
     return new (p) T ;
   }

   // no init, no alignment check should be auto
   template <typename T>
   T* gc_array_malloc(size_t n )
   {
     return reinterpret_cast<T*>( malloc( ( sizeof(T) * n ) ) );
   }


}

#endif // QUAN_GC_HPP_INCLUDED
