#ifndef QUAN_POP_HPP_INCLUDED
#define QUAN_POP_HPP_INCLUDED

#include <stack>

namespace quan{

   template <typename T>
    inline T  pop(std::stack<T> & s)
   {
      T res = s.top();
      s.pop();
      return res;
   }

} //quan


#endif // QUAN_POP_HPP_INCLUDED
