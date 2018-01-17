#ifndef QUAN_FUSION_NUM_ARGS_HPP_INCLUDED
#define QUAN_FUSION_NUM_ARGS_HPP_INCLUDED

// Copyright Andrew Little 2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan/operators/binary_operator_functors.hpp>
#include <boost/mpl/int.hpp>

namespace quan{namespace fusion{

    template <typename F>
    struct num_args;
    
    template <> struct  num_args<quan::operator_equals> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_plus_equals> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_minus_equals> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_times_equals> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_divide_equals> : boost::mpl::int_<2>{};

    template <> struct  num_args<quan::operator_logical_or> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_logical_and> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_bit_or> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_bit_xor> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_bit_and> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_equal_to> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_not_equal_to> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_greater_equal> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_less_equal> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_greater> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_less> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_minus> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_plus> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_times> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_divides> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_shift_left> : boost::mpl::int_<2>{};
    template <> struct  num_args<quan::operator_shift_right> : boost::mpl::int_<2>{};
        
}}//quan::fusion

#endif

