#include <quan_matters/test/concepts/static_unit_concept.hpp>

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.
/*
    Static Unit Concept check
    Check that a type fulfills the StaticUnit requirements
*/
#include <quan/config.hpp>
#include <quan_matters/test/test.hpp>
#include "static_unit_concept.hpp"
#include <quan/length.hpp>

void test1()
{
    quan::meta::StaticUnitConcept<quan::length::mm::unit>();
    quan::meta::StaticUnitConcept<quan::length::ft::unit>();
    quan::meta::StaticUnitConcept<quan::length::mi::unit>();
}

#if 0
int errors =0;
int main()
{
   test1();
   EPILOGUE
}
#endif


