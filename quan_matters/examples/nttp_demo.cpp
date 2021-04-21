/* 
   nttp demo requires c++20
*/

#include <quan/rational.hpp>
#include <iostream>

template <quan::rational R>
void print()
{
   std::cout << R.num <<'/' << R.den <<'\n';
}

int main()
{
    print<quan::rational(static_cast<intmax_t>(123456789),static_cast<intmax_t>(3)) * quan::rational(static_cast<intmax_t>(3),static_cast<intmax_t>(467982))>();
}

