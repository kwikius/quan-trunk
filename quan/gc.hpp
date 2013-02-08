#ifndef QUAN_GC_HPP_INCLUDED
#define QUAN_GC_HPP_INCLUDED

/*
  gc with boehm collector
*/

#ifdef QUAN_BOEHM_GC
#error "QUAN_BOEHM_GC already defined elsewhere"
#else
#define QUAN_BOEHM_GC
#endif

#include <gc.h>

namespace quan{

   inline void gc_init()
   {
      GC_INIT();
   }

   inline void gc_collect()
   {
      ::GC_gcollect();
   }

   template <typename T, typename ... Args>
   inline T* gc_malloc(Args... args)
   {
     T * p = reinterpret_cast<T*>(GC_MALLOC(sizeof(T)));
     return new(p) T{args...};
   }

   template <typename T>
   inline T* gc_malloc()
   {
     T * p = reinterpret_cast<T*>(GC_MALLOC(sizeof(T)));
     return new (p) T ;
   }

   // no init, no alignment check should be auto
   template <typename T>
   T* gc_array_malloc(size_t n )
   {
     return reinterpret_cast<T*>( GC_MALLOC( ( sizeof(T) * n ) ) );
   }


}

#endif // QUAN_GC_HPP_INCLUDED
