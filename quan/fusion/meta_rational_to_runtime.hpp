#ifndef QUAN_FUSION_META_RATIONAL_TO_RUNTIME_HPP_INCLUDED
#define QUAN_FUSION_META_RATIONAL_TO_RUNTIME_HPP_INCLUDED

#include <quan/fusion/to_runtime.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/eval_rational.hpp>

namespace quan{ namespace fusion{

    namespace impl{

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
}} //quan::fusion

#endif // QUAN_FUSION_META_RATIONAL_TO_RUNTIME_HPP_INCLUDED
