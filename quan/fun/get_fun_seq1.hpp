#ifndef QUAN_FUN_GET_FUN_SEQ1_HPP_INCLUDED
#define QUAN_FUN_GET_FUN_SEQ1_HPP_INCLUDED
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

#include <quan/fun/fun_seq1.hpp>
namespace quan{ namespace fun{

   template <typename F, typename Seq>
   inline
   fun_seq1<F,Seq>
   get_fun_seq1(F const & f, Seq & seq)
   {
      return fun_seq1<F,Seq>(f,seq);
   }
   template <typename F, typename Seq>
   inline
   fun_seq1<F,const Seq>
   get_fun_seq1(F const & f, Seq const & seq)
   {
      return fun_seq1<F,const Seq>(f,seq);
   }   
}}

#endif
