

#include <quan/three_d/slerp.hpp>
#include <quan/three_d/out/quat.hpp>
#include <quan/angle.hpp>
#include <quan/fixed_quantity/literal.hpp>

namespace {
   QUAN_QUANTITY_LITERAL(angle,deg)
   QUAN_QUANTITY_LITERAL(angle,rad)
}

int main()
{
   std::cout << sin(0.1) <<'\n';

   auto q1 = quan::three_d::quatFrom(unit_vector(quan::three_d::vect<double>{1,0,0}),25.0_deg);
   auto q2 = quan::three_d::quatFrom(unit_vector(quan::three_d::vect<double>{0,1,0}),0.1);

   auto qR = slerp(q1,q2,0.5);

   std::cout << "q1 = " << q1 << '\n';
   std::cout << "q2 = " << q2 << '\n';
   std::cout << "qR = " << qR << '\n';

}
