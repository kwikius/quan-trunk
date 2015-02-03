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

#include <quan/fun/at_seq.hpp>
#include <type_traits>

namespace quan{ namespace fun{

   template<int N, typename Seq>
   struct auto_at_seq {
      typedef typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type seq_type;
      typedef at_seq<N,seq_type,as_ref> access_modifier;
      typedef typename access_modifier::type type;
      
         type operator()(Seq & seq)
         {
            return access_modifier()(seq);
         }
      };
   
   template<int N, typename Seq>
   struct auto_at_seq<N,const Seq> {
      typedef typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type seq_type;
      typedef at_seq<N,seq_type,as_const_ref> access_modifier;
      typedef typename access_modifier::type type;
      
      type operator()(Seq const & seq)
      {
         return access_modifier()(seq);
      }     
   };
  
   
}}

#endif
