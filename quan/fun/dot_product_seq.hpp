#ifndef QUAN_FUN_DOT_PRODUCT_SEQ_HPP_INCLUDED
#define QUAN_FUN_DOT_PRODUCT_SEQ_HPP_INCLUDED
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

#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/inner_product_seq.hpp>

namespace quan{namespace fun{

   struct dot_product_seq{

      template <typename SeqL, typename SeqR>
      struct result : inner_product_seq:: template result<
         SeqL,SeqR,quan::operator_plus, quan::operator_times
      >{};

      template <typename SeqL,typename SeqR>
      constexpr
      typename result<SeqL,SeqR>::type
      operator()(SeqL const &seqL, SeqR const & seqR)const
      {
         return inner_product_seq{}(seqL,seqR,quan::operator_plus{},quan::operator_times{});
      }
      typedef dot_product_seq type;
   };

}}//quan::fun

#endif
