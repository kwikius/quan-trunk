
#include <quan/utility/show_conversion_factor_working.hpp>
#include <quan/out/length.hpp>

namespace {
   QUAN_QUANTITY_LITERAL(length,m)
}

int main()
{
   std::cout << "show conversion factor working\n\n";

   quan::length::m  qa = 1_m;
   quan::length::km  qb = qa;
   quan::length::mm  qc = qa;
   quan::length::ft  qd = qa;
   quan::length::yd  qe = qa;

   show_working(std::cout, qa,"qa");
   show_working(std::cout, qb,"qb");
   show_working(std::cout, qc,"qc");
   show_working(std::cout, qd,"qd");
   show_working(std::cout, qe,"qe");

}
