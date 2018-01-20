
#include <quan_matters/test/test.hpp>

void static_value_test();
void static_monoid_test();

int errors = 0;

int main()
{
  static_value_test();
  static_monoid_test();

  QUAN_EPILOGUE
}