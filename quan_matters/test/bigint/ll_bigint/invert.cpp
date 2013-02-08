
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <iostream>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_invert()
  {
    ll_bigint v = 1;
   
    v.invert();
    QUAN_CHECK(v.to_string_base<2>() == "-10")
    v.invert();
    QUAN_CHECK(v.to_string_base<2>() == "1")
    
   
  }

}}

