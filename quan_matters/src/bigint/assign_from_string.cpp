
#include <quan/bigint.hpp>

#if(QUAN_BIGINT_VERSION == 1)

void quan::bigint::assign_from_string(std::string const & str)
{
      //if start is - send start to ll_bigint
   m_sign = 1;
   std::size_t const len = str.length();
   // probably aceptable to just do default initialisation here
   if (len == 0){
      throw std::runtime_error("attempt to initialise bigint with empty string");
   }
   
   if ( len > 2){
      if ( str[0] == '0'){
        if( ( ( str[1] =='x') || ( str[1] =='X') ) ){
            for (std::size_t i = 2; i < len; ++i){
               uint32 const cur = str[i];
               if(
                  ( ( cur >= '0') && (cur <= '9') )
                  || ( ( cur >= 'A') && (cur <= 'F') )
                  || ( ( cur >= 'a') && (cur <= 'f') )
               ){
                  continue;
               }
              else{
                throw std::runtime_error(
                  "attempt to initialise bigint with non digits in hexstring"
                );
              }
            }
            std::string str1 = str.substr(2,std::string::npos);
            m_rep.assign_from_hex_string(str1);
            return; 
         }
         else {
            if ( ( str[1] =='b') || ( str[1] =='B') ){
               for (std::size_t i = 2; i < len; ++i){
                  if( ( str[i] == '0') | (str[i] == '1') ){
                     continue;
                  }
                  else{
                   throw std::runtime_error(
                     "attempt to initialise bigint with non digits in hexstring"
                   );
                  } 
               }
               std::string str1 = str.substr(2,std::string::npos);
               m_rep.assign_from_stringbase2(str1); 
               return; 
            }
         }
      }
   }
   std::size_t start =0;
   if ( len > 1){
      if ( str[0] == '-'){
         m_sign = -1;
         start = 1;
      }else{
         if(m_sign == '+'){
            start = 1;
         }
      }
   }
   // do binary and hex versions

   for (std::size_t i = start; i < len; ++i){
      uint32 const cur = static_cast<uint32>( str[i] - '0');
      if( ( cur < 0U ) || (cur > 9U)){
         throw std::runtime_error("attempt to initialise bigint with non digits in string");
      }
   }
   if( start == 1){
      std::string str1 = str.substr(1,std::string::npos);
      m_rep.assign_from_string(str1);
   }else{
      m_rep.assign_from_string(str);
   }
}
#endif
