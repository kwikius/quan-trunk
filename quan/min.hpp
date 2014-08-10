#ifndef QUAN_MIN_HPP_INCLUDED
#define QUAN_MIN_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>

namespace quan{

   template <typename TL, typename TR>
   inline
   typename quan::meta::binary_op<
      TL, quan::meta::minus, TR
   >::type
   min( TL const & lhs, TR const & rhs)
   {
      return ( lhs < rhs ) ? lhs:rhs;
   }

}//quan

#endif
