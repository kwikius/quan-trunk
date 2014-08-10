#ifndef QUAN_FUN_FILL_HPP_INCLUDED
#define QUAN_FUN_FILL_HPP_INCLUDED
namespace quan{namespace fun{
namespace impl_detail{
   template <typename T>
   struct fill{
      T const & val;
      fill(T const & in): val(in){}
      template <typename T1>
      void operator()(T1& t)const
      {
         t =val;
      }
   };
}

template <typename T>
impl_detail::fill<T> fill (T const & val)
{
   return impl_detail::fill<T>(val);
}
}}//quan::fun

#endif
