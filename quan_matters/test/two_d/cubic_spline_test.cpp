

#include <quan/two_d/cubic_spline.hpp>

#include <quan/out/length.hpp>
#include <iostream>

/*
   spline curve
*/

namespace {
   QUAN_QUANTITY_LITERAL(length,mm)
}


int main()
{
     typedef quan::two_d::vect<quan::length::mm> pt_t;

     std::cout << "----------------------------\n\n";
     quan::two_d::cubic_spline<quan::length::mm> spline;
     spline.push_back(pt_t{10.0_mm,50_mm});
     spline.push_back(pt_t{25_mm,80_mm});
     spline.push_back(pt_t{50_mm,90_mm});
     spline.push_back(pt_t{125_mm,70_mm});

     std::cout << "      {\n";
     auto const front = spline.front().x;
     auto const back = spline.back().x;
     for ( auto x = front; x <= back; x += 1_mm){
        auto const y = spline(x);
        std::cout <<  "         ";
        if ( x != front){
          std::cout << ',';
        }
        std::cout <<  "{ " << x.numeric_value() << "_mm , " << y.numeric_value()  << "_mm}\n";
     }
     std::cout << "      }\n";

}