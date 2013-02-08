#ifndef ARM_MOTOR1_FIFO_HPP_INCLUDED
#define ARM_MOTOR1_FIFO_HPP_INCLUDED

#include <cstdint>

namespace quan{ namespace stm32f4{ namespace usart{ namespace detail{

   template<size_t Size>
   struct fifo {
       static constexpr size_t size = Size;
       fifo():m_putptr {m_buf},m_getptr {0} {}

       void init()
       {
         m_putptr = m_buf;
         m_getptr = 0;
       }
       bool is_empty() const 
       {
           return m_getptr ==0;
       }
       bool is_full() const  {
           return m_putptr ==0;
       }
       bool put(char v) 
       {
          if( is_full() ) return 0;
          // putptr is at end if 0
       
          *m_putptr = v;
          // update getptr if was empty
          if (m_getptr == 0) {
              m_getptr = m_putptr;
          }
          // update the put ptr
          ++ m_putptr;
          if(m_putptr == ( m_buf + size )) {
              m_putptr =  m_buf;
          }
          // check if buffer is full
          if(m_putptr == m_getptr) {
              m_putptr = 0;
          }
          return true;
      }

   int num_in_buffer() const 
   {
      if (m_getptr == 0){
         return 0;
      }else{
         if ( m_putptr == 0){
            return size;
         }else{
            if (m_putptr > m_getptr){
              return m_putptr - m_getptr;
            } else{
              return ( m_putptr + size) - m_getptr  ;
            }
         }
      }
   }

   int num_free()const 
   {
      return size - this->num_in_buffer();
   }

   bool can_get() const  { return m_getptr !=0;}
    
   char  get () 
   {
      
       char result = *m_getptr;
       if (m_putptr ==0) {
           m_putptr = m_getptr;
       }
       ++m_getptr;
       if(m_getptr == (m_buf + size)) {
           m_getptr = m_buf;
       }
       if (m_getptr == m_putptr) {
           m_getptr =0;
       }
       return result;
   }
   private:
    
    char *  m_putptr;
    char *  m_getptr;
    char   m_buf[size];
   };

}}}}//quan::stm32f4::usart::detail
 
#endif
 