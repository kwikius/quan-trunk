#ifndef QUAN_FUSION_MAKE_VECTOR_HPP_INCLUDED
#define QUAN_FUSION_MAKE_VECTOR_HPP_INCLUDED

#include <quan/fun/vector.hpp>

namespace quan{ namespace fusion{

    template <typename ... Args>
    constexpr
    inline
    quan::fun::vector<Args...> make_vector( Args &&... args)
    {
        return quan::fun::vector<Args...>(args...);
    }

}}
#endif // QUAN_FUSION_MAKE_VECTOR_HPP_INCLUDED
