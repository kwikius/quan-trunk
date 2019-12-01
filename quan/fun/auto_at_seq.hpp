#ifndef QUAN_FUN_AUTO_AT_SEQ_HPP_INCLUDED
#define QUAN_FUN_AUTO_AT_SEQ_HPP_INCLUDED
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

#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/meta/if.hpp>
#include <type_traits>

namespace quan{ namespace fun{

   template<int N, typename Seq>
   struct auto_at_seq {
     static_assert(quan::fun::is_fun_sequence<Seq>::value,"");
#if 0
      typedef typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type seq_type;
  

      typedef at_seq<N,seq_type,as_ref> access_modifier;
      typedef typename access_modifier::type type;

      type operator()(seq_type & seq)
      {
      return access_modifier{}(seq);
      }

      typedef at_seq<N,seq_type,as_const_ref> const_access_modifier;
      typedef typename const_access_modifier::type const_type;
      const_type operator()(seq_type const & seq)const
      {
      return const_access_modifier{}(seq);
      }
#else
        /*
      if seq is const then use as_const_ref
      else use as_ref
      */
      typedef typename std::remove_reference<Seq>::type seq_type;
      typedef typename quan::meta::if_<
         std::is_const<seq_type>
         ,as_const_ref
         ,as_ref
      >::type access_type;
      typedef at_seq<N,seq_type,access_type> access_modifier;
      typedef typename access_modifier::type type;
      constexpr type operator()(seq_type & seq)
      {
         return access_modifier{}(seq);
      }
      
#endif
   };
   
//   template<int N, typename Seq>
//   struct auto_at_seq<N,const Seq> {
//      typedef typename std::remove_const<
//         typename std::remove_reference<Seq>::type
//      >::type seq_type;
//      typedef at_seq<N,seq_type,as_const_ref> access_modifier;
//      typedef typename access_modifier::type type;
//      
//      type operator()(Seq const & seq)
//      {
//         return access_modifier()(seq);
//      }     
//   };
  
   
}}

#endif
