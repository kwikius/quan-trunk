#include <quan_matters/test/test.hpp>

void root_test();
void vector_view_test();
void gcd_test();

int errors = 0;
int main()
{
  root_test();
  vector_view_test();
  gcd_test();
 
  QUAN_EPILOGUE
}