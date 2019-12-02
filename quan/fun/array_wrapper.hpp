#ifndef QUAN_FUN_ARRAY_WRAPPER_HPP_INCLUDED
#define QUAN_FUN_ARRAY_WRAPPER_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/meta/int32.hpp>
#include <type_traits>

namespace quan{ namespace fun{

   template <typename T,int N>
   class array_wrapper{  
      T *  data_ ; 
   public: 
      typedef as_ref access_type;

      array_wrapper(T (&a) [N]): data_(a){}
      
      template <int I, typename F >
      typename F::template result<T>::type
      at(){ return data_[I];}

      template <int I, typename F>
      typename F::template result<T>::type
      at()const{ return data_[I];}
      typedef array_wrapper type;
   }; 

   template <typename T,int N>
   struct is_fun_sequence_impl<array_wrapper<T,N> > : std::true_type{};

   template <int I,typename T, int N, typename F>
   struct at_seq_impl<I,array_wrapper<T,N>,F>
   {
       typedef typename F::template result<T>::type type;

      /*  type operator()(array_wrapper<T,N> & arr)const
        {
            return arr. QUAN_MEMBER_TEMPLATE at<I,F>();
        }*/
         static_assert( I < N,"");
        type operator()(array_wrapper<T,N> const & arr) const
        {
           
           return arr. QUAN_MEMBER_TEMPLATE at<I,F>();
        }  
   };

   template <typename T, int N>
   struct size_seq_impl<array_wrapper<T,N> > : quan::meta::int32<N>{};
 
}}//quan::fun


#endif
