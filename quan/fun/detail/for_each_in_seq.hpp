#ifndef QUANTA_DETAIL_FOR_EACH_IN_WRAPPER_N_HPP_INCLUDED
#define QUANTA_DETAIL_FOR_EACH_IN_WRAPPER_N_HPP_INCLUDED
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
#include <quan/fun/at.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/access_modifiers.hpp>


namespace quan{ namespace fun {namespace detail{
   
// compile time loop unrolling impl
   template <int N>
   struct for_each_in_seq_n;

   template <>
   struct for_each_in_seq_n<0>{
      template <typename Sequence, typename F>
      void
      operator()(Sequence& a, F const & f)const
      {
         typedef at_seq<0,Sequence,as_ref> at;
         f(at{}(a));
      }
      template <typename Sequence, typename F>
      void
      operator()(Sequence const& a, F const & f)const
      {
         typedef at_seq<0,Sequence,as_value> at;
         f(at{}(a));
      }
      typedef for_each_in_seq_n type;
   };

   template <int N>
   struct for_each_in_seq_n{
      template<typename Sequence, typename F>
      void
      operator()(Sequence& a, F const & f)const
      {
         static_assert( quan::fun::size_seq<Sequence>::value >= N ,"error" );
         typedef for_each_in_seq_n<N-1> prev;
         prev{}(a,f);
         typedef at_seq<N,Sequence,as_ref> at;
         f(at{}(a));
      }
      template <typename Sequence, typename F>
      void
      operator()(Sequence const & a, F const & f)const
      {
         static_assert( quan::fun::size_seq<Sequence>::value >= N ,"error" );
         typedef for_each_in_seq_n<N-1> prev;
         prev{}(a,f);
         typedef at_seq<N,Sequence,as_value> at;
         f(at{}(a));
      }
      typedef for_each_in_seq_n type;
   };

}}}//quan::fun::detail


#endif
