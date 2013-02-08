#ifndef QUAN_MOVE_HPP_INCLUDED
#define QUAN_MOVE_HPP_INCLUDED

#include <cassert>

namespace quan{

   template <typename Target, typename Src >
   void move( Target* & target, Src* & src)
   {
     assert(target ==0);
     assert(src !=0);
     target = src;
     src = 0;
   }

   template <typename Src >
   Src* move( Src* & src)
   {
     assert(src !=0);
     auto tmp = src;
     src = 0;
     return tmp;
   }

}

#endif

