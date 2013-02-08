#ifndef QUAN_BIGINT_BINARY_OPERATION_HPP_INCLUDED
#define QUAN_BIGINT_BINARY_OPERATION_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>

namespace quan{

   struct big_rational;
   struct bigint;

}

namespace quan{ namespace meta{

   template <typename Op>
   struct binary_op<
      quan::bigint,Op, quan::bigint,
      typename quan::where_<
         or_<
            is_additive_operator<Op>,
            or_< 
               is_shift_operator<Op>,
               or_<
                  is_multiplicative_operator<Op>,
                  is_bit_operator<Op>
               >
            >
         >
      >::type
   >{
      typedef quan::bigint type;
   };

   
  

}}

#endif // QUAN_BIGINT_BINARY_OPERATION_HPP_INCLUDED
