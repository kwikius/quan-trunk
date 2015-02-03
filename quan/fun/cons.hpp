
#ifndef QUAN_FUN_CONS_HPP_INCLUDED
#define QUAN_FUN_CONS_HPP_INCLUDED
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


#include <quan/fun/size_seq.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/detail/at_vector.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <type_traits>

namespace quan{namespace fun{

   struct nil{
      typedef nil type;
   };

   template <typename T, typename Next = nil>
   struct cons;

   template <typename TL,typename TR>
   struct is_fun_sequence<cons<TL,TR> > : std::true_type{};

   template <int N,typename T1, typename T2,typename AtF>
   struct at_seq<N,cons<T1,T2>,AtF> 
   : detail::at_vector<N,cons<T1,T2>,AtF>{};

   template <typename T1,typename T2>
   struct size_seq<cons<T1,T2> >{
      enum {value = cons<T1,T2>::size};
   };

   template <typename T0>
   struct cons<T0,nil>{
      typedef T0 t0;
      enum{ size = 1};
      typedef cons type;
   };

   template <typename T1,typename T0>
   struct cons<T1, cons<T0,nil> >{
      typedef T0 t0;
      typedef T1 t1;
      enum{ size = 2};
      typedef cons type;
   };

   template <typename T2, typename T1, typename T0>
   struct cons<T2,cons<T1,cons<T0,nil> > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      enum{ size = 3};
      typedef cons type;
   };
   
   template <typename T3,typename T2, typename T1, typename T0>
   struct cons<T3,cons<T2,cons<T1,cons<T0,nil> > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      enum{ size = 4};
      typedef cons type;
   };
   
   template <typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      enum{ size = 5};
      typedef cons type;
   };
   
   template <typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      enum{ size = 6};
      typedef cons type;
   };
   
   template <typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      enum{ size = 7};
      typedef cons type;
   };
   
   template < typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
   >{
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
      typedef T3 t3;
      typedef T4 t4;
      typedef T5 t5;
      typedef T6 t6;
      typedef T7 t7;
      enum{ size = 8};
      typedef cons type;
   };
   
   template <typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 9};
      typedef cons type;
   };
   
   template <typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T9,cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 10};
      typedef cons type;
   };
   
   template <typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T10,cons<T9,cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 11};
      typedef cons type;
   };
   
   template <typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T11,cons<T10,cons<T9,cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 12};
      typedef cons type;
   };
   
   template <typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T12,cons<T11,cons<T10,cons<T9,cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 13};
      typedef cons type;
   };
   
   template <typename T13,typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T13,cons<T12,cons<T11,cons<T10,cons<T9,cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 14};
      typedef cons type;
   };
   
   template <typename T14,
   typename T13,typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T14,cons<T13,cons<T12,cons<T11,cons<T10,cons<T9,cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 15};
      typedef cons type;
   };
   
   template <typename T15,typename T14,
   typename T13,typename T12,typename T11,typename T10,typename T9,typename T8, typename T7,
   typename T6,typename T5,typename T4,typename T3,typename T2, typename T1, typename T0>
   struct cons<T15,cons<T14,cons<T13,cons<T12,cons<T11,cons<T10,cons<T9,cons<T8,cons<T7,
      cons<T6,cons<T5,cons<T4,cons<T3,cons<T2,cons<T1,cons<T0,nil> > > > > > >
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
      enum{ size = 16};
      typedef cons type;
   };

   

}}//quan::fun

#endif
