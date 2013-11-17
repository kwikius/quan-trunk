#ifndef  QUAN_FUN_SIZE_SEQ_HPP_INCLUDED
#define  QUAN_FUN_SIZE_SEQ_HPP_INCLUDED

#include <type_traits>
#include <tuple>

namespace quan{ namespace fun{

   template <typename T>
   struct size_seq_impl {}; 

   template <typename T>
   struct size_seq : size_seq_impl<
      typename std::remove_const<
         typename std::remove_reference<T>::type
      >::type
   >{};

  
    template<typename ...Elements >
    struct size_seq_impl<std::tuple<Elements...> > : std::tuple_size<std::tuple<Elements...> >{};
         
        

}}//quan::fun
#endif
