#ifndef QUAN_FUSION_STATIC_BOOL_HPP_INCLUDED
#define QUAN_FUSION_STATIC_BOOL_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_runtime_type.hpp>
#include <quan/fusion/static_value/is_static_value.hpp>

#include <quan/meta/bool.hpp>
#include <quan/fusion/meta_bool_to_runtime.hpp>

namespace quan{ namespace fusion{

   template <bool B>
   struct static_bool{
      typedef bool runtime_type;
      typedef quan::meta::bool_<B> static_value_type;
      explicit constexpr operator bool()const { return B;}
      static constexpr bool value = B;
      
      typedef static_bool type;
   };

   namespace impl{

      template <bool B>
      struct to_runtime_impl<
         static_bool<B>
      >
      {
         typedef bool type;
         constexpr type operator()( static_bool<B>) const
         {
            return B;
         }
      };

      template <bool B>
      struct is_static_value_impl<static_bool<B> > : std::true_type{};

      
   } // impl


}}

namespace quan{namespace meta{

   template <bool B>
   struct is_runtime_type<
      quan::fusion::static_bool<B>
   > : std::false_type{};

   namespace impl { 
      template <bool L,bool R>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::equal_to,
         quan::fusion::static_bool<R>
      > : quan::fusion::static_bool<(L && R) || !(L || R)>{};

      template <bool L,bool R>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::not_equal_to,
         quan::fusion::static_bool<R>
      > : quan::fusion::static_bool<(L!=R)>{};

      template <bool L,bool R>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::logical_or,
         quan::fusion::static_bool<R>
      > : quan::fusion::static_bool<(L || R)>{};

      template <bool L>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::logical_or,
         bool
      > {typedef bool type;};

      template <bool R>
      struct binary_op_impl<
         bool,
         quan::meta::logical_or,
         quan::fusion::static_bool<R>
      > {typedef bool type;};

      template <bool L,bool R>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::logical_and,
         quan::fusion::static_bool<R>
      > : quan::fusion::static_bool<(L && R)>{};

      template <bool L>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::logical_and,
         bool
      > {typedef bool type;};

      template <bool R>
      struct binary_op_impl<
         bool,
         quan::meta::logical_and,
         quan::fusion::static_bool<R>
      > {typedef bool type;};

      template <bool L,bool R>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::bit_and,
         quan::fusion::static_bool<R>
      > : quan::fusion::static_bool<(L & R)>{};

      template <bool L>
      struct binary_op_impl<
         quan::fusion::static_bool<L>,
         quan::meta::bit_and,
         bool
      > {typedef bool type;};

      template <bool R>
      struct binary_op_impl<
         bool,
         quan::meta::bit_and,
         quan::fusion::static_bool<R>
      > {typedef bool type;};
   }//impl
}} // quan::meta

namespace quan{namespace fusion{

   template <bool L, bool R>
   inline constexpr 
   static_bool< (L && R) || !(L || R)>

   operator== (static_bool<L> lhs, static_bool<R> rhs)
   {
      return static_bool<(L&&R) || !(L||R)>();
   }

   template <bool L>
   inline constexpr
   bool
   operator==(static_bool<L>, bool rhs)
   {
      return rhs == L;
   }

   template <bool R>
   inline constexpr
   bool
   operator==( bool lhs, static_bool<R> rhs)
   {
      return lhs == R;
   }
   
   template <bool L, bool R>
   inline constexpr
   static_bool<(L && !R) || ( R && !L)>
   operator!=(static_bool<L>, static_bool<R>)
   {
      return static_bool< (L && !R) || ( R && !L) >();
   }

   template <bool L>
   inline constexpr
   bool
   operator!=(static_bool<L>, bool rhs)
   {
      return  L != rhs;
   }

   template <bool R>
   inline constexpr
   bool
   operator!=( bool lhs, static_bool<R> rhs)
   {
      return lhs != R;
   }
//and
   template <bool L, bool R>
   inline constexpr
   static_bool<(L && R)>
   operator && (static_bool<L>, static_bool<R>)
   {
      return static_bool< (L && R) >();
   }

   template <bool L>
   inline constexpr
   bool
   operator &&(static_bool<L>, bool rhs)
   {
      return L && rhs;
   }

   template <bool R>
   inline constexpr
   bool
   operator &&( bool lhs, static_bool<R> rhs)
   {
      return lhs && R;
   }


   template <bool L, bool R>
   inline constexpr
   static_bool< static_cast<bool>(L && R) >
   operator & (static_bool<L>, static_bool<R>)
   {
      return static_bool< static_cast<bool>(L && R) >();
   }

   template <bool L>
   inline constexpr
   bool
   operator &(static_bool<L>, bool rhs)
   {
      return  L & rhs;
   }

   template <bool R>
   inline constexpr
   bool
   operator &( bool lhs, static_bool<R> rhs)
   {
      return lhs & R;
   }
   
   template <bool L, bool R>
   inline constexpr
   static_bool<(L && R)>
   operator | (static_bool<L>, static_bool<R>)
   {
      return static_bool< (L | R) >();
   }

   template <bool L>
   inline constexpr
   bool
   operator |(static_bool<L>, bool rhs)
   {
      return  L | rhs;
   }

   template <bool R>
   inline constexpr
   bool
   operator |( bool lhs, static_bool<R> rhs)
   {
      return lhs | R;
   }

   template <bool L, bool R>
   inline constexpr
   static_bool< static_cast<bool>(L | R) >
   operator || (static_bool<L>, static_bool<R>)
   {
      return static_bool< static_cast<bool>(L || R) >();
   }

   template <bool L>
   inline constexpr
   bool
   operator ||(static_bool<L>, bool rhs)
   {
      return  L || rhs;
   }

   template <bool R>
   inline constexpr
   bool
   operator ||( bool lhs, static_bool<R> rhs)
   {
      return lhs || R;
   }
   
}}//quan::fusion

#endif
