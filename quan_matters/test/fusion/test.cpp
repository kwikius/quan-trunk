
#include <quan_matters/test/test.hpp>

void static_value_test();
void static_monoid_test();
void inner_product_test();
void fold_test();
void matrix_test();

int errors = 0;

int main()
{
  std::cout << "fusion test\n";

  static_value_test();
  static_monoid_test();
  fold_test();
  inner_product_test();
  matrix_test();

  QUAN_EPILOGUE
}