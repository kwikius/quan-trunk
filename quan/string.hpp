#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED

// we dont want any c++ streams 
// so only C constructs used

#include <malloc.h>
#include <string.h>

namespace quan{

  struct string{
     string():m_c_str{0}{}
     string(const char* str){
       if ( str){
          auto len = strlen(str);
          this->m_c_str = static_cast<char*>(malloc(len));
          if(this->m_c_str !=0){
             strcpy(this->m_c_str,str.m_c_str);
          }
          // else error ...
       }
     }
     string (string const& str):m_c_str(0)
     {
        if( str.c_str()){
			  auto len = strlen(str);
			  m_c_str() = static_cast<char*>(malloc(len));
			  if(this->m_c_str !=0){
				 strcpy(this->m_c_str,str.m_c_str);
			  }
          // else error ...
        }
       
     }
     string (string&& str):m_c_str(0)
     {
        this->m_c_str = str.m_c_str;
        str.m_c_str = 0;
     }

     string & operator = (string const & str)
     {
			if (*this != str){
            auto len = strlen(str);
            m_c_str() = static_cast<char*>(malloc(len));
            if(this->m_c_str !=0){
				 strcpy(this->m_c_str,str.m_c_str);
			   }
         }
     }
     string & operator = (string && str)
     {
       if ( *this !=str){
           if (m_c_str != 0) {
					free( m_c_str());
           }
           this->m_c_str = str.m_c_str;
           str.m_c_str = 0;
       }
       return *this;
     }
     ~string(){ if( m_c_str != 0) free( m_c_str());
     
     
     private:
     // if pointer is non-zero the deallocate on out of scope;
     char * m_c_str;
     
  };

}


#endif // STRING_HPP_INCLUDED
