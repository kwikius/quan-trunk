#include <quan/length.hpp>

#include <quan_matters/test/test.hpp>

void fixed_quantity_concepts()
{
   quan::length::mm constexpr v1{1};

   QUAN_CHECK(quan::meta::is_scalar<decltype(v1)>::value)
   QUAN_CHECK(quan::meta::is_runtime_type<decltype(v1)>::value)
}