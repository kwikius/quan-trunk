#ifndef QUAN_UTILITY_RT_STACK_HPP_INCLUDED
#define QUAN_UTILITY_RT_STACK_HPP_INCLUDED

#include <cstdint>
#include <cstddef>
#include <cstdlib>

#if (defined QUAN_FREERTOS)
#include "FreeRTOS.h"
extern "C" void vPortFree( void *pv );
extern "C" void * pvPortMalloc(size_t n);
#endif

namespace quan{
   template <typename T>
   struct rt_stack{
      rt_stack(size_t size): m_elements{nullptr},m_num_elements{0}, m_idx{0}
      {
         if ( size > 0){
         #if (defined QUAN_FREERTOS)
            m_elements = (T*) pvPortMalloc(size * sizeof(T));
         #else
            m_elements = (T*) malloc(size * sizeof(T));
         #endif    
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
          #if (defined QUAN_FREERTOS)
           vPortFree(m_elements);
         #else
           free(m_elements);
         #endif  
            }
      }
      bool good()const {return m_elements != nullptr;}
      bool push( T const & val)
      {
         if ( m_idx < m_num_elements){
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
