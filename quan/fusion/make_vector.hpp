#ifndef QUAN_FUSION_MAKE_VECTOR_HPP_INCLUDED
#define QUAN_FUSION_MAKE_VECTOR_HPP_INCLUDED

#include <quan/fun/vector.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan{ namespace fusion{

    template <typename ... Args>
    constexpr
    inline
    quan::fun::vector<typename quan::meta::strip_cr<Args>::type...> make_vector( Args &&... args)
    {
        return quan::fun::vector<typename quan::meta::strip_cr<Args>::type...>(args...);
    }

}}
#endif // QUAN_FUSION_MAKE_VECTOR_HPP_INCLUDED
