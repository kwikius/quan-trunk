#ifndef QUAN_META_BINARY_OP_SEQ_HPP_INCLUDED2020
#define QUAN_META_BINARY_OP_SEQ_HPP_INCLUDED2020

#include <quan/meta/binary_op.hpp>

namespace quan{ namespace meta{


   template <typename TL, typename Op, typename ... TR>
   struct binary_op_seq;

   template <typename TL,typename Op, typename TR>
   struct binary_op_seq<TL,Op,TR> : quan::meta::binary_op<TL,Op,TR>{};
     
   template < typename TL, typename Op,typename TR,typename ... T>
   struct binary_op_seq<TL,Op,TR,T...> : quan::meta::binary_op<TL,Op,typename binary_op_seq<TR,Op, T...>::type>{};

}}

#endif // QUAN_META_BINARY_OP_SEQ_HPP_INCLUDED2020
