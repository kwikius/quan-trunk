

#include <quan_matters/test/test.hpp>
#define QUAN_TEST_FUN(fun) void fun ();
#include "test.hpp"
#undef  QUAN_TEST_FUN 

int errors;
int main()
{
#define QUAN_TEST_FUN(fun) fun ();
#include "test.hpp"
#undef  QUAN_TEST_FUN 
	QUAN_EPILOGUE
}
