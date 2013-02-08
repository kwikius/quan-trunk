
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_shl_eq()
  {
    ll_bigint v = -1;
    v.arith_shl_eq(9);
   // std::cout << v.to_string_base<16>()<<'\n';
   // std::cout << v.to_string_base<2>() << '\n';
    QUAN_CHECK(v.to_string_base<16>() == "-200")
  }

}}

