
#include <quan_matters/test/test.hpp>
#include <quan/fusion/static_monoid.hpp>

#include <quan/out/length.hpp>
#include <quan/fixed_quantity/literal.hpp>

using quan::fusion::to_runtime;

namespace{
    QUAN_QUANTITY_LITERAL(length,mm)
}

void static_monoid_test()
{
    typedef quan::fusion::static_monoid<quan::operator_plus,quan::length::mm> monoid_plus;
    QUAN_CHECK(to_runtime{}(monoid_plus::type{}) == 0_mm)

    typedef quan::fusion::static_monoid<quan::operator_minus,quan::length::mm> monoid_minus;
    QUAN_CHECK(to_runtime{}(monoid_minus::type{}) == 0_mm)

    typedef quan::fusion::static_monoid<quan::operator_times,quan::length::mm> monoid_times;
    QUAN_CHECK(to_runtime{}(monoid_times::type{}) == 1)

    typedef quan::fusion::static_monoid<quan::operator_logical_or,bool> monoid_logical_or;
    QUAN_CHECK(to_runtime{}(monoid_logical_or::type{}) == false)

    typedef quan::fusion::static_monoid<quan::operator_logical_and,bool> monoid_logical_and;
    QUAN_CHECK(to_runtime{}(monoid_logical_and::type{}) == true)

}