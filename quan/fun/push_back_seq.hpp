#ifndef QUAN_FUN_PUSH_BACK_SEQ_HPP_INCLUDED
#define QUAN_FUN_PUSH_BACK_SEQ_HPP_INCLUDED
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

#include <quan/fun/cons.hpp>

namespace quan{namespace fun{

 template <typename T, typename Seq>
   struct push_back_seq;

   template <typename T>
   struct push_back_seq<T,nil>{
      typedef cons<T> type;
   };

   template <typename T, typename TL, typename TR>
   struct push_back_seq<T,cons<TL,TR> >{
      typedef cons<T,cons<TL,TR> > type;
   };

}}

#endif
