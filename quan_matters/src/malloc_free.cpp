
#include <quan/malloc_free.hpp>


namespace quan{

  void * malloc(size_t n)
  {
     return ::malloc(n);
  }

  void free( void* p)
  {
    ::free(p);
  }
}







