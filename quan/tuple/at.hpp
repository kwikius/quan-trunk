#ifndef QUAN_TUPLE_AT_HPP_INCLUDED
#define QUAN_TUPLE_AT_HPP_INCLUDED

// Copyright (C) Andrew Little 2007

#include <quan/access_modifiers.hpp>
#include <quan/concepts/tuple.hpp>
#include <quan/concepts/meta/type_sequence.hpp>
#include <quan/static_assert.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>
#include <type_traits>
#include <quan/meta/strip_cr.hpp>
#include <quan/meta/if.hpp>

namespace quan{ namespace tuple{

   namespace impl{

      template<int N,typename Tuple_,typename Access ,typename Where= void>
      struct at_impl;
   }

   template<int N,typename Access = quan::as_value>
   struct at {
      template <typename Tuple_>
      struct apply {
         QUAN_STATIC_ASSERT((quan::is_model_of<quan::meta::TypeSequence,Tuple_>::value));

         typedef typename impl::at_impl<N,Tuple_,Access>::type type;
         //############# Static Assertion failure ##################################
         // asserts when attempting to get non const ref on const type
         typedef quan::meta::and_<
               std::is_same<Access,quan::as_ref>,
               quan::meta::or_<
                  std::is_const<Tuple_>,
                  std::is_const<type>
            >
         > bad_access;
         QUAN_STATIC_ASSERT((bad_access::value==0));
         //######################################################################      
      };

      template <typename Tuple_>
      typename apply<Tuple_>::type
      operator ()(Tuple_ & seq)const 
      {
         return impl::at_impl<N,Tuple_ ,Access>()(seq);
      }

      template <typename Tuple_>
      typename apply<const Tuple_>::type
      operator ()(Tuple_ const & seq)const 
      {
         return impl::at_impl<N, const Tuple_,Access>()(seq);
      }
   };

   template <int N>
   struct auto_at {
      template <typename Tuple_>
      struct apply {
         typedef typename quan::meta::if_<
            std::is_const<Tuple_>,
            quan::as_cref,
            quan::as_ref
         >::type access;
         typedef typename at<N,access>::apply<Tuple_>::type type;
      };
         
      template <typename Tuple_>
      typename apply<Tuple_>::type
      operator ()(Tuple_ & seq)const 
      {
         return impl::at_impl<N,Tuple_,typename apply<Tuple_>::access>()(seq);
      }
   
      template <typename Tuple_>
      typename apply<const Tuple_>::type
      operator ()(Tuple_ const & seq)const 
      {
         return impl::at_impl<N, const Tuple_,typename apply< const Tuple_>::access>()(seq);
      }

   };
      
}}//quan::tuple

#endif

