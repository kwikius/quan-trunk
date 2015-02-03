#ifndef QUAN_FUN_OUT_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_OUT_SEQUENCE_HPP_INCLUDED
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

#include <quan/where.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/for_each.hpp>
#include <quan/fun/output.hpp>
#include <iostream>

namespace quan{namespace fun{

   template <typename Seq>
   typename quan::where_<
      is_fun_sequence<Seq>,
      std::ostream &
   >::type
   operator << ( std::ostream & os, Seq const & seq)
   {
      os << '[';for_each_and_last(seq,output(os,','),output(os,']'));
      return os;
   }

   template <typename Seq>
   typename quan::where_<
      is_fun_sequence<Seq>,
      std::ostream &
   >::type
   operator << ( std::ostream & os, Seq & seq)
   {
      os << '['; for_each_and_last(seq,output(os,','),output(os,']'));
      return os;
   }

}}//quan::fun

#endif
