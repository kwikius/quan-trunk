#ifndef QUAN_META_NUMBITS_HPP_INCLUDED
#define QUAN_META_NUMBITS_HPP_INCLUDED

#ifndef __AVR__
#include <climits>
#else
#include <limits.h>
#endif

namespace quan { namespace meta{

   template <typename T>
   struct numbits{
     static const int value = sizeof(T) * CHAR_BIT;
   };

}}


#endif // QUAN_META_NUMBITS_HPP_INCLUDED
