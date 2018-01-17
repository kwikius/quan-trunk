#ifndef QUAN_FUSION_TYPEOF_REGISTER_HPP_INCLUDED
#define QUAN_FUSION_TYPEOF_REGISTER_HPP_INCLUDED

// Copyright Andrew Little 2005-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <boost/typeof/typeof.hpp>
#include <quan/fusion/static_value/static_value.hpp>
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
BOOST_TYPEOF_REGISTER_TEMPLATE(quan::fusion::static_value,2);

#endif
 