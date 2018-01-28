#ifndef QUAN_FUN_VECTOR_HPP_INCLUDED
#define QUAN_FUN_VECTOR_HPP_INCLUDED

#include <quan/meta/type_sequence.hpp>
#include <quan/where.hpp>
#include <quan/meta/int32.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/access_modifiers.hpp>

namespace quan{ namespace fun{

   template <typename... T >
   struct vector;

   template <typename... T>
   struct is_fun_sequence_impl<vector<T...> > : std::true_type{};

   template <int N, typename AtF, typename... T>
   struct at_seq_impl<N,vector<T...>,AtF>{

      typedef vector<T...> vector_type;

      typedef typename AtF::template result<
          typename vector_type:: template result<N>::type 
      >::type type;

      constexpr type operator()(vector_type & vect) const
      {
         return AtF{}(vect. template at<N>());
      }

      constexpr type operator()(vector_type const & vect) const
      {
         return AtF{}(vect. template at<N>());
      }
   };

   template <typename... T>
   struct size_seq_impl<vector<T...> > : quan::meta::int32<sizeof ...(T)>{};

   template <typename TL , typename... TR>
   struct vector<TL,TR...> : vector<TR...>{
      constexpr vector( TL const & tl, TR const & ... rest): vector<TR...>{rest...},m_value{tl}{}

      typedef vector type;
      typedef quan::fun::as_value access_type;
      static constexpr int size = (sizeof  ...(TR)) + 1;
      
      template <typename S, typename = typename quan::where_<quan::fun::is_fun_sequence<S> >::type>
      constexpr 
      vector( S const & s )
      :vector<TR...>{s,quan::meta::int32<1>{} },m_value { quan::fun::at_seq<0,S>{}(s) }{}

    protected:
      template <typename S, int N, typename = typename quan::where_<quan::fun::is_fun_sequence<S> >::type>
      constexpr 
      vector( S const & s,quan::meta::int32<N> )
      :vector<TR...>{s,quan::meta::int32<N+1>{} },m_value { quan::fun::at_seq<N,S>{}(s) }{}

      TL m_value;
      public:

      template <int N>
      struct result{
         typedef typename quan::meta::at<N,quan::meta::type_sequence<TL,TR...> >::type type;
      };

      template <int N>
      constexpr 
      typename quan::where_c<
         (N==0), 
         TL 
      >::type const &
      at() const &
      {
         return m_value;
      }

      template <int N>
      constexpr 
      typename quan::where_c<
         ((N > 0) && ( N < size)), 
         typename result<N>::type
      >::type const &
      at() const &
      {
         return vector<TR...>:: template at<(N-1)>();
      }

      template <int N>
      constexpr 
      typename quan::where_c<
         (N==0), 
         TL 
      >::type &
      at() &
      {
         return m_value;
      }

      template <int N>
      constexpr 
      typename quan::where_c<
         ((N > 0) && ( N < size)), 
         typename result<N>::type
      >::type &
      at() &
      {
         return vector<TR...>:: template at<(N-1)>();
      }

      template <int N>
      constexpr 
      typename quan::where_c<
         (N==0), 
         TL 
      >::type 
      at() &&
      {
         return m_value;
      }

      template <int N>
      constexpr 
      typename quan::where_c<
         ((N > 0) && ( N < size)), 
         typename result<N>::type
      >::type 
      at() &&
      {
         return vector<TR...>:: template at<(N-1)>();
      }

   };

   template <typename T>
   struct vector<T>
   {
      typedef vector type;
      typedef quan::fun::as_value access_type;
      static constexpr int size = 1;
      constexpr vector(T const & t) : m_value{t}{}
      // n== 0 usually?
      protected:
      template <typename S, int N, typename T1 = typename quan::where_<quan::fun::is_fun_sequence<S> >::type>
      constexpr 
      vector( S const & s, quan::meta::int32<N> )
      :m_value { quan::fun::at_seq<N,S>{}(s) }{}
      T m_value;
      public:

      template <int N>
      struct result{
         static_assert ( N==0,"expected N to be zero");
         typedef typename quan::meta::at<N,quan::meta::type_sequence<T> >::type type;
      };

      template <int N>
      constexpr 
      typename quan::where_c<
         (N==0), 
         T 
      >::type const &
      at() const &
      {
         return m_value;
      }

      template <int N>
      constexpr 
      typename quan::where_c<
         (N==0), 
         T 
      >::type &
      at() &
      {
         return m_value;
      }

      template <int N>
      constexpr 
      typename quan::where_c<
         (N==0), 
         T 
      >::type 
      at() &&
      {
         return m_value;
      }
   };

}} //quan::fun

#endif // QUAN_FUN_VECTOR_HPP_INCLUDED
