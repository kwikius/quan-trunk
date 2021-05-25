
#include <quan/out/temperature.hpp>

#define QUAN_DO_OUTPUT(x) std::cout << x <<'\n';

QUAN_QUANTITY_LITERAL(temperature,F)
QUAN_QUANTITY_LITERAL(temperature,C)

int main()
{
   auto constexpr t1 = 57_F;

   static_assert(t1.numeric_value() == 57,"");

   QUAN_DO_OUTPUT(t1)

   quan::temperature::F constexpr t2 = quan::temperature::K{373.15};

   static_assert(t2.numeric_value() == 212,"");

   QUAN_DO_OUTPUT(t2)

   quan::temperature::F constexpr t3 = quan::temperature::C{0};

   static_assert(t3.numeric_value() == 32,"");

  QUAN_DO_OUTPUT(t3)

   quan::temperature::C constexpr t4 = quan::temperature::F{32};

   static_assert(t4.numeric_value() == 0,"");

   QUAN_DO_OUTPUT(t4)

   quan::temperature::C constexpr t5 = t2;

   static_assert(t5.numeric_value() == 100,"");

   QUAN_DO_OUTPUT(t5)
}


