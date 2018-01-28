#ifndef QUAN_FUN_FOR_EACH_HPP_INCLUDED
#define QUAN_FUN_FOR_EACH_HPP_INCLUDED
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

#include <quan/fun/detail/for_each_in_seq.hpp>
#include <quan/fun/array_wrapper.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/if.hpp>
#include <type_traits>
#include <algorithm>

namespace quan{ namespace fun{

   template <typename Sequence,typename F>

   typename quan::where_not<
      quan::meta::or_<
         is_fun_sequence<Sequence>,
         std::is_integral<Sequence>
      >,
      void
   >::type
   for_each(Sequence & seq,F const & f)
   {
     std::for_each(seq.begin(),seq.end(),f);
   }

   template <typename Sequence,typename F>
   typename quan::where_<
      is_fun_sequence<Sequence>,
      void
   >::type
   for_each(Sequence & seq,F const & f)
   {
      typedef detail::for_each_in_seq_n<size_seq<Sequence>::value -1> ff;
      ff{}(seq,f);
   }
   
   template <typename Sequence,typename F>
   typename quan::where_<
      is_fun_sequence<Sequence>,
      void
   >::type
   for_each(Sequence const & seq,F const & f)
   {
      typedef detail::for_each_in_seq_n<size_seq<Sequence>::value -1> ff;
      ff{}(seq,f);
   }

//overload for_each to wrap integral iterator...
   template <typename T, typename F>
   typename quan::where_<
      std::is_integral<T>,
      void
   >::type
   for_each(T const & n, F const & f)
   {
      for (T i =0; i !=n; ++ i) {
         f(i);
      }
   }
   
   template <typename Sequence,typename F, typename Fback>
   typename quan::where_<
      quan::meta::and_<
         is_fun_sequence<Sequence>,
         quan::meta::bool_<(size_seq<Sequence>::value >1)>
      >,
      void
   >::type
   for_each_and_last(Sequence & seq,F const & f, Fback const & f_back )
   {
      typedef detail::for_each_in_seq_n<size_seq<Sequence>::value -2> ff;
      ff{}(seq,f);
      f_back(at_seq<(size_seq<Sequence>::value -1),Sequence,as_ref>()(seq));
   }

   template <typename Sequence,typename F, typename Fback>
   typename quan::where_not<
      is_fun_sequence<Sequence>,
      void
   >::type
   for_each_and_last(Sequence & seq,F const & f, Fback const & f_back )
   {
      typedef typename quan::meta::if_<
         std::is_const<Sequence>,
         typename Sequence::const_iterator,
         typename Sequence::iterator
      >::type iterator;
      iterator last = seq.end()-1;
      std::for_each(seq.begin(),last,f);
      f_back(*last);
   }
   
   template <typename Sequence,typename F, typename Fback>
   typename quan::where_<
      quan::meta::and_<
         is_fun_sequence<Sequence>,
         quan::meta::bool_<(size_seq<Sequence>::value ==1)>
      >,
      void
   >::type
   for_each_and_last(Sequence & seq,F const & f, Fback const & f_back )
   {
      f_back(at_seq<0,Sequence,as_value>()(seq));
   }
   
   template <typename Sequence,typename F, typename Fback>
   typename quan::where_<
       quan::meta::and_<
         is_fun_sequence<Sequence>,
         quan::meta::bool_<(size_seq<Sequence>::value > 1)>
      >,
      void
   >::type
   for_each_and_last(Sequence const & seq,F const & f, Fback const & f_back )
   {
      typedef detail::for_each_in_seq_n<size_seq<Sequence>::value -2> ff;
      ff{}(seq,f);
      f_back(at_seq<(size_seq<Sequence>::value -1),Sequence,as_value>{}(seq));
   }
   
   template <typename Sequence,typename F, typename Fback>
   typename quan::where_<
       quan::meta::and_<
         is_fun_sequence<Sequence>,
         quan::meta::bool_<(size_seq<Sequence>::value == 1)>
      >,
      void
   >::type
   for_each_and_last(Sequence const & seq,F const & f, Fback const & f_back )
   {
      f_back(at_seq<0,Sequence,as_value>{}(seq));
   }
   
   namespace impl_detail{

      struct large_array_for_each{
         
          template <typename T,int N,typename F>
          void operator() (T (&ar)[N], F const & f) const
          {
            for (int i = 0; i != N; ++i){
              f(ar[i]);
            }
          }
      };
      
      struct small_array_for_each{
         
          template <typename T,int N,typename F>
          void operator() (T (&ar)[N], F const & f) const
          {
            //quan::fun::array_wrapper<T,N> arw(ar);
            quan::fun::for_each(quan::fun::array_wrapper<T,N>{ar},f);
          }
      };

   }
   template <typename T,int N,typename F>
   void for_each(T (&ar)[N],F const & f)
   {  
      typedef typename quan::meta::if_c<
         (N > 16),
         impl_detail::large_array_for_each,
         impl_detail::small_array_for_each
      >::type fun;
      //fun ff;
      fun{}(ar,f);
     /* array_wrapper<T,N> arw(ar);
      for_each(arw,f);*/
   }
  
}}//quan::fun

#endif
