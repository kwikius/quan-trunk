#ifndef QUAN_FUSION_IS_STATIC_VALUE_HPP_INCLUDED
#define QUAN_FUSION_IS_STATIC_VALUE_HPP_INCLUDED

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/bool/false.hpp>

namespace quan{namespace fusion{

    template <typename T>
    struct is_static_value : quan::meta::false_{};

}}//quan::fusion

#endif
