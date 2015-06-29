#ifndef QUAN_UTILITY_RT_STACK_HPP_INCLUDED
#define QUAN_UTILITY_RT_STACK_HPP_INCLUDED

#include <cstdint>
//#include <cstddef>
//#include <cstdlib>
#include <quan/malloc_free.hpp>

namespace quan{
   template <typename T>
   struct rt_stack{
      rt_stack(size_t size): m_elements{nullptr},m_num_elements{0}, m_idx{0}
      {
         if ( size > 0){
            m_elements = (T*) quan::malloc(size * sizeof(T));  
            if ( m_elements != nullptr){
              m_num_elements = size;
            }
         }
      }
      bool empty() const 
      {
         return m_idx == 0;
      }
      ~rt_stack()
      {
           if ( m_elements != nullptr){
               quan::free(m_elements);
            }
      }
      bool good()const {return m_elements != nullptr;}
      bool push( T const & val)
      {
         if ( m_idx < static_cast<int>(m_num_elements)){
            m_elements[m_idx] = val;
            ++m_idx;
            return true;
         }else{
            return false;
         }
      }
      bool pop(T & result)
      {
         if ( m_idx > 0){
           -- m_idx;
            result = m_elements[m_idx];
            return true;
         }else{
            return false;
         }
      }
      bool peek(T & result)const
      {
         if ( m_idx > 0){
            result = m_elements[m_idx-1];
            return true;
         }else{
            return false;
         }
      }
      private:
      T * m_elements;
      size_t m_num_elements;
      int32_t m_idx;
   };
} // quan



#endif // QUAN_UTILITY_RT_STACK_HPP_INCLUDED
