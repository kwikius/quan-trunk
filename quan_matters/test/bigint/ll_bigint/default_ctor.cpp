
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_default_ctor()
  {
    ll_bigint v;
    QUAN_CHECK(v.eq_zero())
    QUAN_CHECK(v.get_num_elements() == 1); 
  }

}}

