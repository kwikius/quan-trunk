#ifndef QUAN_META_IS_MEMCOPYABLE_HPP_INCLUDED
#define QUAN_META_IS_MEMCOPYABLE_HPP_INCLUDED

#include <quan/meta/bool/false.hpp>
#include <quan/meta/strip_cr.hpp>
#include <type_traits>

namespace quan{ namespace meta{
 
  namespace impl{
     
     template <typename T, typename Enable = void>
     struct is_memcopyable_impl : quan::meta::false{};
     
     template <typename T>
     struct is_memcopyable_impl<T, quan::where_<std::is_pod<T> > : quan::meta::true_{};

  }
  
  template <typename T> 
  struct is_mem_copyable : impl::is_memcopyable_impl<
    typename quan::meta::strip_cr<T>::type 
  >{};

}}


#endif // QUAN_META_IS_MEMCOPYABLE_HPP_INCLUDED
