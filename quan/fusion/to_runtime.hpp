#ifndef QUAN_FUSION_TO_RUNTIME_HPP_INCLUDED
#define QUAN_FUSION_TO_RUNTIME_HPP_INCLUDED

#include <quan/meta/rational.hpp>
#include <quan/meta/eval_rational.hpp>

namespace quan{ namespace fusion{

    namespace impl{

        template <typename T>
        struct to_runtime_impl{
            typedef T type;
            constexpr type operator()( T const & t) const 
            {
                return t;
            }
        };
       
        template <int64_t N, int64_t D>
        struct to_runtime_impl<
            quan::meta::rational<N,D>
        >{
            typedef typename quan::meta::rational<N,D>::type rational_type;
            typedef quan::meta::eval_rational<rational_type> eval;
            typedef typename eval::result_type type;
            constexpr type operator()(rational_type) const
            {
                return eval{}();
            }
        };
    } // impl

    struct to_runtime{

        template <typename T>
        struct result{
            typedef typename impl::to_runtime_impl<T>::type type;
        };

        template <typename T>
        constexpr typename result<T>::type
        operator()(T const & t)const
        {
            typedef impl::to_runtime_impl<T> f;
            return f{}(t);
        }
    };

}}

#endif // QUAN_FUSION_TO_RUNTIME_HPP_INCLUDED
