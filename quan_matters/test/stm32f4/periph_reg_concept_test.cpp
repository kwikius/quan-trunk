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

#include <quan/stm32f4/tim.hpp>
#include <quan/stm32f4/usart.hpp>
#include <quan_matters/test/test.hpp>

int errors =0;
int main()
{

   typedef quan::stm32f4::tim1  t1;

   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::cr1_type>::value == true) )
   static_assert( sizeof (quan::stm32f4::tim2::cr1_type) == 4,"error");
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::cr2_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::smcr_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::dier_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::sr_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::ccmr1_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::ccmr2_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::ccer_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::cnt_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::psc_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::arr_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::rcr_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::ccr1_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::ccr2_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::ccr3_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::ccr4_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::bdtr_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::dcr_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::dmar_type>::value == true) )
   QUAN_CHECK( (quan::is_model_of<quan::stm32f4::PeriphReg,quan::stm32f4::tim1::or__type>::value == false) )

   EPILOGUE
}
