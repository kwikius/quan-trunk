
#include <quan/utility/show_conversion_factor_working.hpp>
#include <quan/out/length.hpp>

int main()
{
   std::cout << "show conversion factor working\n\n";

   quan::length::km  qa {1};
   quan::length::mm  qb = qa;
   quan::length::ft  qc = qa;
   quan::length::yd  qd = qa;

   show_working(std::cout, qa,"qa");
   show_working(std::cout, qb,"qb");
   show_working(std::cout, qc,"qc");
   show_working(std::cout, qd,"qd");

}
