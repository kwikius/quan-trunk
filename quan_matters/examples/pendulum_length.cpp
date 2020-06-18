
#include <quan/out/acceleration.hpp>
#include <quan/out/length.hpp>
#include <quan/out/time.hpp>
#include <quan/constants/constant.hpp>

/*
   find length of a pendulum for 1_s period
*/

namespace {

   QUAN_QUANTITY_LITERAL(time,s)

}

int main()
{
    auto constexpr period = 1_s; 

    quan::length::mm constexpr length = quan::pow<2>(period / (2 * quan::constant::pi)) * quan::acceleration::g ;

    std::cout << "pendulum length for " << period << " period = " << length  <<'\n';
}




