#ifndef QUAN_FUN_CONTAINER_FUN_PUSH_HPP_INCLUDED
#define QUAN_FUN_CONTAINER_FUN_PUSH_HPP_INCLUDED

#include <quan/fun/container_fun_adapt1_macro.hpp>

namespace quan{ namespace fun{namespace impl_detail{

      template <typename Container>
      struct push_{
      Container & c;
      push_(Container & c_in):c(c_in){}

      template <typename T>
      struct result{
         typedef void type;
      };
      template <typename T>
      typename result<T>::type
      operator()(T const & t)const
      {
         return c.push(t);
      }
   };

   template <typename Fun, typename Container>
      struct push_fun{
      Container & c;
      Fun const & f;
      push_fun(Fun const & f_in,Container & c_in):f(f_in),c(c_in){}

      template <typename T>
      struct result{
         typedef void type;
      };
      template <typename T>
      typename result<T>::type
      operator()(T const & t)const
      {
         return c.push(f(t));
      }
   };
   
}
// function returns a functor
// this means you dont need parameters
// on the functor as you would when using direct
template <typename Container>
inline
impl_detail::push_<Container> push(Container & c)
{
   return impl_detail::push_<Container>(c);
}

template <typename F,typename Container>
inline
impl_detail::push_fun<F,Container> push(F const & f,Container & c)
{
   return impl_detail::push_fun<F,Container>(f,c);
}
}}

#endif
