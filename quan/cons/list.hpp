
#ifndef QUAN_CONS_LIST_HPP_INCLUDED
#define QUAN_CONS_LIST_HPP_INCLUDED
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

#include <quan/cons/list_def.hpp>
#include <type_traits>
#include <quan/meta/detail/type_sequence_at.hpp>

namespace quan{namespace cons{


   template <typename T0>
   struct list<T0,nil>{
      typedef T0 t0;
      typedef std::integral_constant<int,1> length;
      typedef list type;
   };

   template <typename T1,typename T0>
   struct list<T1, list<T0,nil> >{
      typedef T0 t0;
      typedef T1 t1;
      typedef std::integral_constant<int,2> length;
      typedef list type;
   };

   template <typename T2, typename T1, typename T0>
   struct list<T2,list<T1,list<T0,nil> > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef std::integral_constant<int,3> length;
      typedef list type;
   };
   
   template <typename T3,typename T2, typename T1, typename T0>
   struct list<T3,list<T2,list<T1,list<T0,nil> > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef std::integral_constant<int,4> length;
      typedef list type;
   };
   
   template <typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef std::integral_constant<int,5> length;
      typedef list type;
   };
   
   template <typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef std::integral_constant<int,6> length;
      typedef list type;
   };
   
   template <typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef std::integral_constant<int,7> length;
      typedef list type;
   };
   
   template < typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef std::integral_constant<int,8> length;
      typedef list type;
   };
   
   template <typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef std::integral_constant<int,9> length;
      typedef list type;
   };
   
   template <typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T9,list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef T9 t9;
      typedef std::integral_constant<int,10> length;
      typedef list type;
   };
   
   template <typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T10,list<T9,list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef T9 t9;
      typedef T10 t10;
      typedef std::integral_constant<int,11> length;
      typedef list type;
   };
   
   template <typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T11,list<T10,list<T9,list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef T9 t9;
      typedef T10 t10;
      typedef T11 t11;
      typedef std::integral_constant<int,12> length;
      typedef list type;
   };
   
   template <typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T12,list<T11,list<T10,list<T9,list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef T9 t9;
      typedef T10 t10;
      typedef T11 t11;
      typedef T12 t12;
      typedef std::integral_constant<int,13> length;
      typedef list type;
   };
   
   template <typename T13,typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T13,list<T12,list<T11,list<T10,list<T9,list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > > > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef T9 t9;
      typedef T10 t10;
      typedef T11 t11;
      typedef T12 t12;
      typedef T13 t13;
      typedef std::integral_constant<int,14> length;
      typedef list type;
   };
   
   template <typename T14,
   typename T13,typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T14,list<T13,list<T12,list<T11,list<T10,list<T9,list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > > > > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef T9 t9;
      typedef T10 t10;
      typedef T11 t11;
      typedef T12 t12;
      typedef T13 t13;
      typedef T14 t14;
      typedef std::integral_constant<int,15> length;
      typedef list type;
   };
   
   template <typename T15,typename T14,
   typename T13,typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct list<T15,list<T14,list<T13,list<T12,list<T11,list<T10,list<T9,list<T8,list<T7,
      list<T6,list<T5,list<T4,list<T3,list<T2,list<T1,list<T0,nil> > > > > > >
   > > > > > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      typedef T8 t8;
      typedef T9 t9;
      typedef T10 t10;
      typedef T11 t11;
      typedef T12 t12;
      typedef T13 t13;
      typedef T14 t14;
      typedef T15 t15;
      typedef std::integral_constant<int,16> length;
      typedef list type;
   };

   namespace impl{

      template <typename Seq, typename T> 
      struct push_back_impl : quan::undefined{};

   }

   template <typename Seq, typename T> 
   struct push_back : quan::cons::impl::push_back_impl< 
      typename quan::meta::strip_cr<Seq>::type,T
   >{};

   namespace impl{

      template <typename T>
      struct push_back_impl<nil,T>{
         typedef list<T> type;
      };


   template <typename T0, typename T1, typename T2>
   struct push_back_impl<quan::cons::list<T1,T0>,T2 >{
      typedef list<T2,quan::cons::list<T1,T0> > type;
   };
   }

}}//quan::cons

#endif

