

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
