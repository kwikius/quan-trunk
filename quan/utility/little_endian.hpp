#ifndef QUAN_UTILITY_LITTLE_ENDIAN_HPP_INCLUDED
#define QUAN_UTILITY_LITTLE_ENDIAN_HPP_INCLUDED

// https://stackoverflow.com/questions/4181951/how-to-check-whether-a-system-is-big-endian-or-little-endian

namespace quan{
   // return true if little endian system
   inline bool little_endian()
   {
     int n = 1;
   // little endian if true
     return(*(char *)&n == 1);
   }   

}

#endif // QUAN_UTILITY_LITTLE_ENDIAN_HPP_INCLUDED
