#ifndef QUAN_FUN_VECTOR9_HPP_INCLUDED
#define QUAN_FUN_VECTOR9_HPP_INCLUDED

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */
 // No part of this document may be reproduced or transmitted 
 // in any form or by any means without the written permission 
 // of the author.

/*
   fixed length vector of 9 elements
*/
#include <quan/fun/vector9_fwd.hpp>

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
#include <quan/meta/and.hpp>
#include <quan/implicit_cast.hpp>

namespace quan{ namespace fun{
   
   template <
      typename T0,typename T1,typename T2,
      typename T3,typename T4,typename T5,
      typename T6,typename T7,typename T8,
      typename F
   >
   struct is_fun_sequence_impl<
      vector9<
         T0,T1,T2, T3,T4,T5, T6,T7,T8, F
      > 
   > : std::true_type{};

   template<
      typename T0,typename T1,typename T2,
      typename T3,typename T4,typename T5,
      typename T6,typename T7,typename T8,
      typename F
   > struct vector9{

      typedef F access_type;

      typedef typename F::template result<T0>::type t0;
      typedef typename F::template result<T1>::type t1;
      typedef typename F::template result<T2>::type t2;

      typedef typename F::template result<T3>::type t3;
      typedef typename F::template result<T4>::type t4;
      typedef typename F::template result<T5>::type t5;

      typedef typename F::template result<T6>::type t6;
      typedef typename F::template result<T7>::type t7;
      typedef typename F::template result<T8>::type t8;

      t0 v0; t1 v1; t2 v2;
      t3 v3; t4 v4; t5 v5;
      t6 v6; t7 v7; t8 v8;

      static const int size = 9;
      typedef typename detail::arg_type<t0>::type t0_arg;
      typedef typename detail::arg_type<t1>::type t1_arg;
      typedef typename detail::arg_type<t2>::type t2_arg;

      typedef typename detail::arg_type<t3>::type t3_arg;
      typedef typename detail::arg_type<t4>::type t4_arg;
      typedef typename detail::arg_type<t5>::type t5_arg;

      typedef typename detail::arg_type<t6>::type t6_arg;
      typedef typename detail::arg_type<t7>::type t7_arg;
      typedef typename detail::arg_type<t8>::type t8_arg;
      
      vector9()
      :  v0(T0()), v1(T1()),v2(T2()),
         v3(T3()), v4(T4()),v5(T5()),
         v6(T6()), v7(T7()),v8(T8())
      {}

      vector9(
         t0_arg t0_in, t1_arg  t1_in, t2_arg  t2_in,
         t3_arg t3_in, t4_arg  t4_in, t5_arg  t5_in,
         t6_arg t6_in, t7_arg  t7_in, t8_arg  t8_in
       )
      :  v0(t0_in), v1(t1_in),v2(t2_in),
         v3(t3_in), v4(t4_in),v5(t5_in),
         v6(t6_in), v7(t7_in),v8(t8_in)
      {}

      template<typename Seq>
      vector9(Seq & seq,
         typename quan::where_<
            quan::fun::is_fun_sequence<Seq>,
            void*
         >::type = 0
      ): 
         v0(implicit_cast<t0>(at_seq<0,Seq,as_ref>()(seq))),
         v1(implicit_cast<t1>(at_seq<1,Seq,as_ref>()(seq))),
         v2(implicit_cast<t2>(at_seq<2,Seq,as_ref>()(seq))),

         v3(implicit_cast<t3>(at_seq<3,Seq,as_ref>()(seq))),
         v4(implicit_cast<t4>(at_seq<4,Seq,as_ref>()(seq))),
         v5(implicit_cast<t5>(at_seq<5,Seq,as_ref>()(seq))),

         v6(implicit_cast<t6>(at_seq<6,Seq,as_ref>()(seq))),
         v7(implicit_cast<t7>(at_seq<7,Seq,as_ref>()(seq))),
         v8(implicit_cast<t8>(at_seq<8,Seq,as_ref>()(seq)))
      {
         static_assert(size_seq<Seq>::value ==9,"error");
      }

      template<typename Seq>
      vector9(Seq const & seq,
         typename quan::where_<
            quan::fun::is_fun_sequence<Seq>,
            void*
         >::type = 0
      ): 
         v0(implicit_cast<t0>(at_seq<0,Seq,as_const_ref>()(seq))),
         v1(implicit_cast<t1>(at_seq<1,Seq,as_const_ref>()(seq))),
         v2(implicit_cast<t2>(at_seq<2,Seq,as_const_ref>()(seq))),

         v3(implicit_cast<t3>(at_seq<3,Seq,as_const_ref>()(seq))),
         v4(implicit_cast<t4>(at_seq<4,Seq,as_const_ref>()(seq))),
         v5(implicit_cast<t5>(at_seq<5,Seq,as_const_ref>()(seq))),

         v6(implicit_cast<t6>(at_seq<6,Seq,as_const_ref>()(seq))),
         v7(implicit_cast<t7>(at_seq<7,Seq,as_const_ref>()(seq))),
         v8(implicit_cast<t8>(at_seq<8,Seq,as_const_ref>()(seq)))
      {
         static_assert(size_seq<Seq>::value ==9,"error");
      }

      template <typename Seq>
      typename quan::where_<
         quan::meta::and_<
            is_fun_sequence<Seq>,
            quan::meta::bool_<size_seq<Seq>::value ==9>
         >,
         vector9 &
      >::type
      operator=(Seq const & in)
      {         
         sequence_assign_op<8,operator_equals> ass;
         ass(*this,in);
         return *this;
      }

      template <typename Seq>
      typename quan::where_<
         quan::meta::and_<
            is_fun_sequence<Seq>,
            quan::meta::bool_<size_seq<Seq>::value ==9>
         >,
         vector9 &
      >::type
      operator=(Seq & in)
      {         
         sequence_assign_op<8,operator_equals> ass;
         ass(*this,in);
         return *this;
      }

      typedef vector9 type;
   };

   template <
      int N, 
      typename T0,typename T1,typename T2, 
      typename T3,typename T4,typename T5,
      typename T6,typename T7,typename T8,
      typename F, typename AtF
   >
   struct at_seq_impl<
      N,
      vector9<T0,T1,T2,T3,T4,T5,T6,T7,T8,F>,
      AtF
   > 
   : detail::at_vector<N,
         vector9<
            T0,T1,T2,
            T3,T4,T5,
            T6,T7,T8,
            F
         >,AtF>{};

   /*template <
      int N, 
      typename T0,typename T1,typename T2, 
      typename T3,typename T4,typename T5,
      typename T6,typename T7,typename T8,
      typename F, typename AtF
   >
   struct at_seq_impl<
      N,
      const vector9<T0,T1,T2,T3,T4,T5,T6,T7,T8,F>,
      AtF
   > 
   : detail::at_vector<N,
         vector9<
            T0,T1,T2,
            T3,T4,T5,
            T6,T7,T8,
            F
         >,AtF>{};
 */
   template <
      typename T0,typename T1,typename T2, 
      typename T3,typename T4,typename T5,
      typename T6,typename T7,typename T8,
      typename F
   >
   struct size_seq_impl<
      vector9<T0,T1,T2,T3,T4,T5,T6,T7,T8,F> 
   > : quan::meta::int32<9>{};
  
}}//quan::fun

#endif
