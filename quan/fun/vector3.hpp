#ifndef QUAN_FUN_VECTOR3_HPP_INCLUDED
#define QUAN_FUN_VECTOR3_HPP_INCLUDED

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

/*
   fixed length vector of 3 elements
*/
#include <quan/fun/vector3_fwd.hpp>
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
#include <quan/meta/and.hpp>

namespace quan{ namespace fun{
   
   template <
      typename T0,typename T1,typename T2,
      typename F
   >
   struct is_fun_sequence_impl<vector3<T0,T1,T2,F> > : quan::meta::bool_<true>{};

   template<
      typename T0,typename T1,typename T2,typename F
   > struct vector3{

      typedef F access_type;
      typedef typename F::template result<T0>::type t0;
      typedef typename F::template result<T1>::type t1;
      typedef typename F::template result<T2>::type t2;

      t0 v0;
      t1 v1;
      t2 v2;

      static const int size = 3;
      typedef typename detail::arg_type<t0>::type t0_arg;
      typedef typename detail::arg_type<t1>::type t1_arg;
      typedef typename detail::arg_type<t2>::type t2_arg;
      
      vector3()
      :v0(T0()), v1(T1()),v2(T2()){}

      vector3(t0_arg t0_in, t1_arg  t1_in, t2_arg  t2_in)
      : v0(t0_in), v1(t1_in),v2(t2_in){}

      template<typename Seq>
      vector3(Seq & seq,
         typename quan::where_<
            quan::meta::and_<
               quan::fun::is_fun_sequence<Seq>,
               quan::meta::bool_<((size_seq<Seq>::value)==3)>
            >,
            void*
         >::type = 0
      ): 
      v0(implicit_cast<t0>(at_seq<0,Seq,as_ref>()(seq))),
      v1(implicit_cast<t1>(at_seq<1,Seq,as_ref>()(seq))),
      v2(implicit_cast<t2>(at_seq<2,Seq,as_ref>()(seq)))
      {
         static_assert(quan::meta::bool_<size_seq<Seq>::value ==3>::value ==true,"error");
      }

      template<typename Seq>
      vector3(Seq const & seq,
         typename quan::where_<
            quan::fun::is_fun_sequence<Seq>,
            void*
         >::type = 0
      ): 
      v0(implicit_cast<t0>(at_seq<0,Seq,as_const_ref>()(seq))),
      v1(implicit_cast<t1>(at_seq<1,Seq,as_const_ref>()(seq))),
      v2(implicit_cast<t2>(at_seq<2,Seq,as_const_ref>()(seq)))
      {
          static_assert(quan::meta::bool_<size_seq<Seq>::value ==3>::value == true,"error");
      }

      template <typename Seq>
      typename quan::where_<
         quan::meta::and_<
            is_fun_sequence<Seq>,
            quan::meta::bool_<size_seq<Seq>::value ==3>
         >,
         vector3 &
      >::type operator=(Seq const & in)
      {    
         sequence_assign_op<2,operator_equals> ass;
         ass(*this,in);
         return *this;
      }
      template <typename Seq>
      typename quan::where_<
         quan::meta::and_<
            is_fun_sequence<Seq>,
            quan::meta::bool_<size_seq<Seq>::value ==3>
         >,
         vector3 &
      >::type
         operator=(Seq & in)
      {         
         sequence_assign_op<2,operator_equals> ass;
         ass(*this,in);
         return *this;
      }
      typedef vector3 type;
   };

   template <int N, typename T0,typename T1,typename T2, typename F, typename AtF>
   struct at_seq_impl<N,vector3<T0,T1,T2,F>,AtF> 
   : detail::at_vector<N,vector3<T0,T1,T2,F>,AtF>{};

   template <typename T0,typename T1,typename T2, typename F>
   struct size_seq_impl<vector3<T0,T1,T2,F> > : quan::meta::int32<3>{};
  
}}//quan::fun

#endif
