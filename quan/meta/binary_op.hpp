#ifndef QUAN_META_BINARY_OP_HPP_INCLUDED
#define QUAN_META_BINARY_OP_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2003-2019

#include <quan/meta/impl/binary_op_impl.hpp>
#if  defined __cpp_concepts
#include <quan/concepts/any_type.hpp>
#endif
#include <quan/archetypes/any_type.hpp>
#include <quan/meta/strip_cr.hpp>
#include <quan/is_model_of.hpp>

namespace quan{ namespace meta{

   template <typename TL, typename Op, typename TR>
   struct binary_op {
      typedef typename quan::meta::impl::binary_op_impl<
         typename strip_cr<TL>::type,Op,
         typename strip_cr<TR>::type
      >::type type;
   };

   template <typename Lhs, typename Op,  typename Rhs>
   struct is_valid_binary_op : quan::is_model_of<
      quan::AnyType_, typename binary_op<Lhs,Op,Rhs>::type
   >{};
  
}}//quan::meta

#endif

