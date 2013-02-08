
/*
   fixed_quantity semantics tests
*/

#include <quan_matters/test/fixed_quantity/test.hpp>

int errors =0;

int main()
{
   default_constructor();

   value_init();
   down_cast_value_init();
   out_of_range_value_init();

   EPILOGUE
}