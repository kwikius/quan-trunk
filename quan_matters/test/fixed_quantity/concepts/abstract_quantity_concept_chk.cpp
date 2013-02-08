

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
/*
    AbstractQuantity Concept check
    Check that a type fulfills the StaticAbstractQuantity requirements
*/
#include <quan_matters/test/test.hpp>
#include "quan/concept_check/meta/abstract_quantity_concept.hpp"
#include <quan/length.hpp>
void test1()
{
    quan::concept_check::meta::AbstractQuantityConcept<quan::length::abstract_quantity>();
}

int errors =0;
int main()
{
   test1();
}