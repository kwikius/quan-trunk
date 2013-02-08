// Copyright Andrew Little 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>
#include <quan/length.hpp>
#include <typeinfo>

/*
    check anonymous_cast function
    semantics of output changed
*/

void anonymous_cast_test()
{
    quan::length::m length(1);

    quan::meta::binary_op<
        quan::velocity::m_per_s,
        quan::meta::times,
        quan::time::s
    >::type auto_length;

#ifdef QUAN_ENABLE_SELECTED_HOISTED_QUANTITIES
// length is hoisted
    QUAN_CHECK( ( typeid(auto_length) == typeid(length)));
    QUAN_CHECK( ( typeid(auto_length) != typeid(anonymous_cast(length) )));
#else
   QUAN_CHECK( ( typeid(auto_length) != typeid(length)));
   QUAN_CHECK( ( typeid(auto_length) == typeid(anonymous_cast(length) )));
#endif
}


