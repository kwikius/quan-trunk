
#ifndef QUAN_FUN_RANGE_HPP_INCLUDED
#define QUAN_FUN_RANGE_HPP_INCLUDED
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

#include <quan/fun/range_seq.hpp>
namespace quan{ namespace fun{

   template <int First, int Last, typename Seq>
   inline
   range_seq<Seq,First,Last>
   range(Seq & seq)
   {
      return range_seq<Seq,First,Last>(seq);
   }
   
   template <int First, int Last,typename Seq>
   inline
   range_seq<const Seq,First,Last>
   range(Seq const & seq)
   {
      return range_seq<const Seq,First,Last>(seq);
   }
}}
#endif
