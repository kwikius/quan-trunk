#ifndef QUAN_FUN_AT_HPP_INCLUDED
#define QUAN_FUN_AT_HPP_INCLUDED

#include <quan/fun/access_modifiers.hpp>
#include <type_traits>
#include <tuple>

namespace quan{ namespace fun{

    template<int N, typename Seq, typename Access>
    struct at_seq_impl;

    template<int N, typename Seq, typename Access = as_value>
    struct at_seq : at_seq_impl<
      N,
      typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type,
      Access
    >{};

    
    template<int N, typename ...Elements , typename Access>
    struct at_seq_impl<N,std::tuple<Elements...>, Access>{
         
        typedef typename std::tuple_element<N, std::tuple<Elements...> >::type type;

        type operator() ( std::tuple<Elements...> & in)
        {
               return std::get<N>(in);
        }

        type operator() ( std::tuple<Elements...> const & in)
        {
               return std::get<N>(in);
        }
        
    };

}}//quan::fun

#endif
