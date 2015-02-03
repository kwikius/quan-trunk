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
 along with this program. If not, see http://www.gnu.org/licenses.
*/
#include <quan/dynarray.hpp>

template <typename T>
quan::dynarray<T>::dynarray (size_t N, void (*pferror) ())
  : m_num_elements {N}
{
   m_ptr = (T*) malloc (N * sizeof (T));
   if (m_ptr == nullptr) {
      pferror();
      m_num_elements = 0;
   }
/*
   for ( uint32_t i = 0; i < m_num_elements; ++i){
    m_ptr[i] = T{0};
   }
*/
}
 
template <typename T>
quan::dynarray<T>::~dynarray()
{
   ::free (m_ptr);
}
 
template <typename T>
void quan::dynarray<T>::free()
{
   ::free (m_ptr);
   m_ptr = nullptr;
   m_num_elements = 0;
}
template <typename T>
bool quan::dynarray<T>::realloc (size_t N)
{
   // check for 0 ?
   if (N == 0) {
      return false;
   }
   if (N == m_num_elements) {
      return true;
   } else {
      T* new_rep = (T*) ::realloc (m_ptr,N * sizeof (T));
      if (new_rep == nullptr) {
         // memory stays the same
         return false;
      } else {
         m_ptr = new_rep;
         m_num_elements = N;
/*
          for ( uint32_t i = 0; i < m_num_elements; ++i){
    m_ptr[i] = T{0};
   }
*/
         return true;
      }
   }
}
 
template <typename T>
bool quan::dynarray<T>::realloc (size_t N, void (*pferror) ())
{
   if (this->realloc (N)) {
      return true;
   } else {
      pferror();
      return false;
   }
}
 
 
 
