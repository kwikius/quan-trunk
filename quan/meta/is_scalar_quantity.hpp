#ifndef QUAN_META_IS_SCALAR_QUANTITY_HPP_INCLUDED
#define QUAN_META_IS_SCALAR_QUANTITY_HPP_INCLUDED

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    is T either a quantity or arithmetic
#######################################################
    Note Well: this is not the same as ssd::is_scalar
    which allows pointers etc
#################################################

    In Quan vector quantities are distinguishable because they look like:

    some_vector<Dims,quantity> my_vector_quantity;

    Otherwise they are in scalar form. Simply put, even if a quantity is,
    by nature, a vector quantity,the information is not useful uunless the 
    vector information ( magnitude and direction) is provided.
*/

#include <type_traits>

namespace quan{ namespace meta{

    template <typename T>
    struct is_scalar_quantity : std::is_arithmetic<T>{};

}}//quan::meta

#endif
