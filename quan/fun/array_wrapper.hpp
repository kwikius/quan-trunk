#ifndef QUAN_FUN_ARRAY_WRAPPER_HPP_INCLUDED
#define QUAN_FUN_ARRAY_WRAPPER_HPP_INCLUDED

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

        type operator()(array_wrapper<T,N> const & arr) const
        {
           return arr. QUAN_MEMBER_TEMPLATE at<I,F>();
        }  
   };

   template <typename T, int N>
   struct size_seq_impl<array_wrapper<T,N> > : quan::meta::int32<N>{};
 
}}//quan::fun


#endif
