#ifndef QUAN_MALLOC_HPP_INCLUDED
#define QUAN_MALLOC_HPP_INCLUDED

#include <cstdlib>

/*
wrap malloc and free 
 These can be used transparently with FreeRTOS
*/
namespace quan{

  void * malloc(size_t n);
  void  free( void* p);

}


#endif // QUAN_MALLOC_HPP_INCLUDED
