#ifndef QUAN_SEQ_VECTOR2_HPP_INCLUDED
#define QUAN_SEQ_VECTOR2_HPP_INCLUDED

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
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
   fixed length vector of 2 elements
*/
//#include <quan/seq/concepts/vector.hpp>
//#include <quan/seq/vector/vector2_fwd.hpp>
//#include <quan/fun/arg_type.hpp>
//#include <quan/fun/binary_op.hpp>
#include <quan/implicit_cast.hpp>

namespace quan{ namespace seq{
   
   template<
      typename T0,typename T1
   > struct vector2 /*: vector_base */{

     // typedef F access_type;
      typedef vector2 type;
      typedef std::integral_constant<int,2> length;

     // typedef typename F::template apply<T0>::type t0;
     // typedef typename F::template apply<T1>::type t1;
      typedef T0 t0;
      typedef T1 t1;

      t0 v0;
      t1 v1;

      //typedef typename quan::fun::arg_type<t0>::type t0_arg;
      //typedef typename quan::fun::arg_type<t1>::type t1_arg;
    
      vector2(){}

      vector2(t0_arg v0_in, t1_arg  v1_in)
      : v0(v0_in),v1(v1_in){}

      template<typename Seq>
      vector2(Seq & seq,
         typename quan::where_<
            quan::meta::and_<
               is_ref_sequence<type>,
               quan::meta::and_<
                  quan::meta::or_<
                     quan::seq::is_value_sequence<Seq>,
                     quan::seq::is_ref_sequence<Seq>
                  >,
                  quan::meta::eq_<length,quan::seq::num_elements<Seq> >
               >
            >,
            void*
         >::type = 0
      ): 
      v0(quan::implicit_cast<t0>(at<0,quan::fun::as_ref>()(seq))),
      v1(quan::implicit_cast<t1>(at<1,quan::fun::as_ref>()(seq)))
      {}

      template<typename Seq>
      vector2(Seq const & seq,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::not_<is_ref_sequence<type> >,
               same_size<type,Seq>
            >,
            void*
         >::type = 0
      ): 
      v0(quan::implicit_cast<t0>(at<0,quan::fun::as_cref>()(seq))),
      v1(quan::implicit_cast<t1>(at<1,quan::fun::as_cref>()(seq)))
      {}

      template <typename Seq>
      typename quan::where_<
         same_size<type,Seq>,
         type &
      >::type operator=(Seq const & in)
      {    
         op_assign<quan::fun::equals> ass;
         ass(*this,in);
         return *this;
      }     
   };
  
}}//qlib::fun

#endif

