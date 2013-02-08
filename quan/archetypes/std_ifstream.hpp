#ifndef QUAN_ARCHETYPES_STD_ISTREAM_HPP_INCLUDED
#define QUAN_ARCHETYPES_STD_ISTREAM_HPP_INCLUDED

#include <fstream>
#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>

namespace quan{ 

    struct StdIfstream;
}

namespace quan{ namespace impl{

    template <>
    struct is_model_of_impl<quan::StdIfstream,std::ifstream,void> : quan::meta::true_{};
}}


#endif // QUAN_ARCHETYPES_STD_ISTREAM_HPP_INCLUDED
