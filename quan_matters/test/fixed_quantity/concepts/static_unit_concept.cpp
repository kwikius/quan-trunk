#include <quan_matters/test/concepts/static_unit_concept.hpp>

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
*/


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


