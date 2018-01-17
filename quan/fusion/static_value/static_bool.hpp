#ifndef QUAN_FUSION_STATIC_BOOL_HPP_INCLUDED
#define QUAN_FUSION_STATIC_BOOL_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_runtime_type.hpp>
#include <quan/fusion/static_value/is_static_value.hpp>

namespace quan{ namespace fusion{

   template <bool B>
   struct static_bool{
      typedef bool runtime_type;
      enum { value = B};
      typedef static_bool type;
   };

   namespace detail{

      template <typename T> struct to_runtime;

      template <bool B>
      struct to_runtime<
         static_bool<B>
      >
      {
         typedef bool type;
         type operator()( static_bool<B>) const
         {
               return B;
         }
      };
   }
   template <bool B>
   struct is_static_value<static_bool<B> > : std::true_type{};
}}

namespace quan{namespace meta{

   template <bool B>
   struct is_runtime_type<
      quan::fusion::static_bool<B>
   > : std::false_type{};

   template <bool L,bool R>
   struct binary_op<
      quan::fusion::static_bool<L>,
      equal_to,
      quan::fusion::static_bool<R>
   > : quan::fusion::static_bool<(L && R) || !(L || R)>{};

  
   template <bool L,bool R>
   struct binary_op<
      quan::fusion::static_bool<L>,
      not_equal_to,
      quan::fusion::static_bool<R>
   > : quan::fusion::static_bool<(L!=R)>{};

   template <bool L,bool R>
   struct binary_op<
      quan::fusion::static_bool<L>,
      logical_or,
      quan::fusion::static_bool<R>
   > : quan::fusion::static_bool<(L || R)>{};

   template <bool L>
   struct binary_op<
      quan::fusion::static_bool<L>,
      logical_or,
      bool
   > {typedef bool type;};

   template <bool R>
   struct binary_op<
      bool,
      logical_or,
      quan::fusion::static_bool<R>
   > {typedef bool type;};

   template <bool L,bool R>
   struct binary_op<
      quan::fusion::static_bool<L>,
      logical_and,
      quan::fusion::static_bool<R>
   > : quan::fusion::static_bool<(L && R)>{};

   template <bool L>
   struct binary_op<
      quan::fusion::static_bool<L>,
      logical_and,
      bool
   > {typedef bool type;};

   template <bool R>
   struct binary_op<
      bool,
      logical_and,
      quan::fusion::static_bool<R>
   > {typedef bool type;};

    template <bool L,bool R>
   struct binary_op<
      quan::fusion::static_bool<L>,
      bit_and,
      quan::fusion::static_bool<R>
   > : quan::fusion::static_bool<(L & R)>{};

   template <bool L>
   struct binary_op<
      quan::fusion::static_bool<L>,
      bit_and,
      bool
   > {typedef bool type;};

   template <bool R>
   struct binary_op<
      bool,
      bit_and,
      quan::fusion::static_bool<R>
   > {typedef bool type;};
}}

namespace quan{namespace fusion{

   template <bool L, bool R>
   inline
   static_bool< (L && R) || !(L || R)>

   operator== (static_bool<L> lhs, static_bool<R> rhs)
   {
      return static_bool<(L&&R) || !(L||R)>();
   }

   template <bool L>
   inline
   bool
   operator==(static_bool<L>, bool rhs)
   {
      return rhs == L;
   }

   template <bool R>
   inline
   bool
   operator==( bool lhs, static_bool<R> rhs)
   {
      return lhs == R;
   }
   
   template <bool L, bool R>
   inline
   static_bool<(L && !R) || ( R && !L)>
   operator!=(static_bool<L>, static_bool<R>)
   {
      return static_bool< (L && !R) || ( R && !L) >();
   }

   template <bool L>
   inline
   bool
   operator!=(static_bool<L>, bool rhs)
   {
      return  L != rhs;
   }

   template <bool R>
   inline
   bool
   operator!=( bool lhs, static_bool<R> rhs)
   {
      return lhs != R;
   }
//and
   template <bool L, bool R>
   inline
   static_bool<(L && R)>
   operator && (static_bool<L>, static_bool<R>)
   {
      return static_bool< (L && R) >();
   }

   template <bool L>
   inline
   bool
   operator &&(static_bool<L>, bool rhs)
   {
      return  L && rhs;
   }

   template <bool R>
   inline
   bool
   operator &&( bool lhs, static_bool<R> rhs)
   {
      return lhs && R;
   }


   template <bool L, bool R>
   inline
   static_bool< static_cast<bool>(L && R) >
   operator & (static_bool<L>, static_bool<R>)
   {
      return static_bool< static_cast<bool>(L && R) >();
   }

   template <bool L>
   inline
   bool
   operator &(static_bool<L>, bool rhs)
   {
      return  L & rhs;
   }

   template <bool R>
   inline
   bool
   operator &( bool lhs, static_bool<R> rhs)
   {
      return lhs & R;
   }
   
   template <bool L, bool R>
   inline
   static_bool<(L && R)>
   operator | (static_bool<L>, static_bool<R>)
   {
      return static_bool< (L | R) >();
   }

   template <bool L>
   inline
   bool
   operator |(static_bool<L>, bool rhs)
   {
      return  L | rhs;
   }

   template <bool R>
   inline
   bool
   operator |( bool lhs, static_bool<R> rhs)
   {
      return lhs | R;
   }

   template <bool L, bool R>
   inline
   static_bool< static_cast<bool>(L | R) >
   operator || (static_bool<L>, static_bool<R>)
   {
      return static_bool< static_cast<bool>(L || R) >();
   }

   template <bool L>
   inline
   bool
   operator ||(static_bool<L>, bool rhs)
   {
      return  L || rhs;
   }

   template <bool R>
   inline
   bool
   operator ||( bool lhs, static_bool<R> rhs)
   {
      return lhs || R;
   }
   
}}//quan::fusion

#endif
