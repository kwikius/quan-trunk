#ifndef QUAN_CONSTRAIN_HPP_INCLUDED
#define QUAN_CONSTRAIN_HPP_INCLUDED

namespace quan{

   template <typename T>
   T constrain(T const & val, T const & min_val, T const & max_val)
   {
      if ( val > max_val){
         return max_val;
      }else{
         if ( val < min_val){
            return min_val;
         }else{
            return val;
         }
      }
   }

} // quan

#endif // QUAN_CONSTRAIN_HPP_INCLUDED
