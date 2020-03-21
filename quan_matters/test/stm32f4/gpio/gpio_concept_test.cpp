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
 along with this program. If not, see http://www.gnu.org/licenses.
*/
#if ! defined __MBED__

//!-!-!start
#include <quan/stm32f4/gpio.hpp>
#include <quan_matters/test/test.hpp>

int errors = 0;
int main()
{

   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::Gpio,quan::stm32f4::gpioa>::value));

   EPILOGUE
}
//!-!-!end

#endif
