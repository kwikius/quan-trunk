#ifndef QUAN_DYNARRAY_HPP_INCLUDED
#define QUAN_DYNARRAY_HPP_INCLUDED
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
//size_t
#include <cstddef>
#include <quan/malloc_free.hpp>

namespace  quan {
/*
 simple class for allocating on the stack and cleaning itself up
when out of scope.
requires a ctor function to call on failure to alloc
/ todo optimise so only size of pointer when empty ( store size as 1st elem maybe)
 For RTOS will need to use thread safe alloc and free funs rather than malloc and free
*/
template <typename T>
struct dynarray {
   dynarray (size_t N, void (*pferror) ())
      : m_num_elements {N}
   {
      m_ptr = (T*) quan::malloc (N * sizeof (T));
      if (m_ptr == nullptr) {
         pferror();
         m_num_elements = 0;
      }
   }
   ~dynarray()
   {
      quan::free (m_ptr);
   }
   
   size_t get_num_elements() const
   {
      return m_num_elements;
   }

   void free()
   {
      quan::free (m_ptr);
      m_ptr = nullptr;
      m_num_elements = 0;
   }
  
   T* get() const
   {
      return m_ptr;
   }

   bool realloc (size_t N)
   {
      // check for 0 ?
      if (N == 0) {
         return false;
      }
      if (N == m_num_elements) {
         return true;
      } else {
         T* new_rep = (T*)quan::malloc(N * sizeof (T));
         if ( new_rep != nullptr ){
            quan::free(m_ptr);
            m_ptr = new_rep;
            m_num_elements = N;
            return true;
         }else{
            return false;
         }
      }
   }
  
   bool realloc (size_t N, void (*pferror) ())
   {
      if (this->realloc (N)) {
         return true;
      } else {
         pferror();
         return false;
      }
   }
   
   bool good() const {
      return m_ptr != nullptr;
   }
private:
   T* m_ptr;
   size_t m_num_elements;
   dynarray (dynarray const &) = delete;
   dynarray & operator = (dynarray const &) = delete;
};
} //quan
 
#endif // QUAN_DYNARRAY_HPP_INCLUDED
 
 
