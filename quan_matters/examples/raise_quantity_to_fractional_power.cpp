

#include <quan/out/length.hpp>

/*
   si::length<si::decimetre> q1{100};

   std::cout << "q1 = " << q1 <<'\n';

   auto q2 = sqrt(q1);

   std::cout << "q2 ( square root of q1) =  " << q2 << '\n';

   si::length<si::decimetre> q3 = q2 * q2;

   std::cout << "q3 (q2^2 should be same as q1) = " << q3 << '\n';
*/

int main()
{
   quan::length::dm q1{100};

   std::cout << "q1 = " << q1 <<'\n';

   auto q2 = sqrt(q1);

   std::cout << "q2 ( square root of q1) =  " << q2 << '\n';

   quan::length::dm q3 = q2 * q2;

   std::cout << "q3 (q2^2 should be same as q1) = " << q3 << '\n';
}