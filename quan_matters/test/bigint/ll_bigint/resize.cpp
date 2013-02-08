
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_resize()
  {
    ll_bigint v = 1;
   
    QUAN_CHECK(v.get_num_elements() == 1 );
    QUAN_CHECK(v.is_negative() == false)
    v.extend(20);
    QUAN_CHECK(v.get_num_elements() == 20);
    QUAN_CHECK(v.is_negative() == false)
    v.request_compact(1);
    QUAN_CHECK(v.get_num_elements() == 1);
    QUAN_CHECK(v.is_negative() == false)

    ll_bigint v1 = -1;
   
    QUAN_CHECK(v1.get_num_elements() == 1 );
    QUAN_CHECK(v1.is_negative() == true)
    v1.extend(2000);
    QUAN_CHECK(v1.get_num_elements() == 2000);
    QUAN_CHECK(v1.is_negative() == true)
    v1.request_compact(1);
    QUAN_CHECK(v1.get_num_elements() == 1);
    QUAN_CHECK(v1.is_negative() == true)
    v1.extend(2000);
    v1.negate();
    QUAN_CHECK(v1.eq_one())
    QUAN_CHECK(v1.get_num_elements() == 2000);
  
  }

}}

