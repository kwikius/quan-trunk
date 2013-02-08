#ifndef QUAN_META_DIGIT_TO_CHAR_HPP_INCLUDED
#define QUAN_META_DIGIT_TO_CHAR_HPP_INCLUDED

namespace quan{ namespace meta{

   template <int Base> struct digit_to_char;

   template <>  struct digit_to_char<16>{

       char operator()(int digit){
          static int const vals[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
          if ( ( digit >= 0) && (digit <= 15) ) {
            return vals[digit];
          }else{
            return '\0';
          }
       } 
   };

   template <>  struct digit_to_char<10>{

       char operator()(int digit){
          static int const vals[] = {'0','1','2','3','4','5','6','7','8','9'};
          if ( ( digit >= 0) && (digit <= 9) ) {
            return vals[digit];
          }else{
            return '\0';
          }
       } 
   };

    template <>  struct digit_to_char<2>{

       char operator()(int digit){
          static int const vals[] = {'0','1'};
          if ( ( digit >= 0) && (digit <= 1) ) {
            return vals[digit];
          }else{
            return '\0';
          }
       } 
   };

   


}}



#endif // QUAN_META_CHAR_TO_DIGIT_HPP_INCLUDED
