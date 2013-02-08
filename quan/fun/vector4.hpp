#ifndef QUAN_FUN_VECTOR4_HPP_INCLUDED
#define QUAN_FUN_VECTOR4_HPP_INCLUDED

 // Copyright (c) 2005-2006 Andrew Little.  ALL RIGHTS RESERVED.
 // No part of this document may be reproduced or transmitted 
 // in any form or by any means without the written permission 
 // of the author.

/*
   fixed length vector of 4 elements
*/
#include <quan/fun/vector4_fwd.hpp>
#include <quan/fun/seq_ops.hpp>
#include <quan/fun/detail/at_vector.hpp>
#include <quan/fun/access_modifiers.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/detail/arg_type.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/meta/int32.hpp>
#include <quan/fun/same_size_seq.hpp>
#include <quan/where.hpp>
#include <quan/implicit_cast.hpp>

namespace quan{ namespace fun{
   
   template <typename T0,typename T1,typename T2,typename T3,typename F>
   struct is_fun_sequence_impl<vector4<T0,T1,T2,T3,F> > : std::true_type{};

   template<
      typename T0,typename T1,typename T2,typename T3,typename F
   > struct vector4{

      typedef F access_type;

      typedef typename F::template result<T0>::type t0;
      typedef typename F::template result<T1>::type t1;
      typedef typename F::template result<T2>::type t2;
      typedef typename F::template result<T3>::type t3;

      t0 v0;
      t1 v1;
      t2 v2;
      t3 v3;

      static const int size = 4;
      typedef typename detail::arg_type<t0>::type t0_arg;
      typedef typename detail::arg_type<t1>::type t1_arg;
      typedef typename detail::arg_type<t2>::type t2_arg;
      typedef typename detail::arg_type<t3>::type t3_arg;
      
      vector4()
      :v0(T0()),v1(T1()),v2(T2()),v3(T3()){}

      vector4(t0_arg t0_in, t1_arg  t1_in, t2_arg t2_in, t3_arg t3_in)
      : v0(t0_in),
         v1(t1_in),
         v2(t2_in),
         v3(t3_in){}

      template<typename Seq>
      vector4(Seq & seq,
         typename quan::where_<
            quan::fun::is_fun_sequence<Seq>,
            void*
         >::type = 0
      ): 
      v0(implicit_cast<t0>(at_seq<0,Seq,as_ref>()(seq))),
      v1(implicit_cast<t1>(at_seq<1,Seq,as_ref>()(seq))),
      v2(implicit_cast<t2>(at_seq<2,Seq,as_ref>()(seq))),
      v3(implicit_cast<t3>(at_seq<3,Seq,as_ref>()(seq))){}

      template<typename Seq>
      vector4(Seq const & seq,
          typename quan::where_<
            quan::fun::is_fun_sequence<Seq>,
            void*
         >::type = 0): 
      v0(implicit_cast<t0>(at_seq<0,Seq,as_const_ref>()(seq))),
      v1(implicit_cast<t1>(at_seq<1,Seq,as_const_ref>()(seq))),
      v2(implicit_cast<t2>(at_seq<2,Seq,as_const_ref>()(seq))),
      v3(implicit_cast<t3>(at_seq<3,Seq,as_const_ref>()(seq))){}
      
      template <typename Seq>
      typename quan::where_<
         quan::fun::is_fun_sequence<Seq>,
         vector4 &
      >::type
      operator=(Seq const & in)
      {         
         sequence_assign_op<3,operator_equals> ass;
         ass(*this,in);
         return *this;
      }
      typedef vector4 type;
   };

   template <int N, typename T0,typename T1,typename T2, typename T3, typename F, typename AtF>
   struct at_seq_impl<N,vector4<T0,T1,T2,T3,F>,AtF> 
   : detail::at_vector<N,vector4<T0,T1,T2,T3,F>,AtF>{};

   template <typename T0,typename T1,typename T2, typename T3, typename F>
   struct size_seq_impl<vector4<T0,T1,T2,T3,F> > : quan::meta::int32<4>{};
  
}}//quan::fun

#endif
