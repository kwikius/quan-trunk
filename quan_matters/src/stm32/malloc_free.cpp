
#if ! defined __MBED__
#include <quan/malloc_free.hpp>

#if (defined QUAN_FREERTOS)

#include "FreeRTOS.h"
extern "C" void vPortFree( void *pv );
extern "C" void * pvPortMalloc(size_t n);

namespace quan{

  void * malloc(size_t n)
  {
      return ::pvPortMalloc(n);
  }
  void free( void* p)
  {
    ::vPortFree(p);
  }
}
#else
// not freertos

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

#endif
#endif






