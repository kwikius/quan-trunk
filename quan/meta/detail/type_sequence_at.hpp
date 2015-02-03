#ifndef QUAN_META_DETAIL_TYPE_SEQUENCE_AT_HPP_INCLUDED
#define QUAN_META_DETAIL_TYPE_SEQUENCE_AT_HPP_INCLUDED
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

#include <quan/macro/cat.hpp>
#include <quan/concepts/tuple.hpp>
#include <quan/concepts/meta/type_sequence.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>
#include <quan/undefined.hpp>

namespace quan{ namespace meta{ namespace detail{

   namespace impl{

      template <int N, typename S, typename F>
      struct type_sequence_at_impl : quan::undefined{};

   }

   template <int N, typename S, typename F>
   struct type_sequence_at : quan::meta::detail::impl::type_sequence_at_impl<
         N,typename quan::meta::strip_cr<S>::type,F
   >{};

   namespace impl{
   // if sequence is const or cref
   // then F cannot be ref ?
#define QUAN_META_DETAIL_TYPE_SEQUENCE_AT(N) \
    template <typename S, typename F>\
   struct type_sequence_at_impl<N,S,F>{\
      typedef typename F::template apply< QUAN_MACRO_CAT(typename S::t, N) >::type type;\
 \
      type operator()(S & s) const\
      {\
         return F()( QUAN_MACRO_CAT(s.v,N) );\
      }\
      type operator()(S const & s) const\
      {\
         return F()( QUAN_MACRO_CAT(s.v,N) );\
      }\
   }; 
 
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(0);
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(1); 
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(2);  
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(3);  
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(4);
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(5); 
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(6);  
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(7);  
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(8);
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(9); 
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(10);  
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(11);  
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(12);
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(13); 
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(14);  
         QUAN_META_DETAIL_TYPE_SEQUENCE_AT(15); 
       
         #undef  QUAN_META_DETAIL_TYPE_SEQUENCE_AT

      }//impl

}}}//quan::meta::detail

#endif

