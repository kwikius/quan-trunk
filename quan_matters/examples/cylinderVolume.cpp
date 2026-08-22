
#include <quan/constants/constant.hpp>
#include <quan/out/mass.hpp>
#include <quan/out/length.hpp>
#include <quan/out/volume.hpp>
#include <quan/out/density.hpp>

namespace {

    QUAN_QUANTITY_LITERAL(mass,kg)
    QUAN_QUANTITY_LITERAL(volume,m3)
    QUAN_QUANTITY_LITERAL(length,m)

    quan::volume::m3 cylinderVolume(quan::length::m radius,quan::length::m length)
    {
       return quan::constant::pi * quan::pow<2>(radius) * length;
    }
}

int main()
{
    quan::length::m radius = 0.005_m;
    quan::length::m length = 0.45_m;
    quan::volume::m3 volume = cylinderVolume(radius,length);
    quan::mass::kg mass = 0.023_kg;
    quan::density::kg_per_m3 density = mass / volume;

    std::cout << "density = " << density << '\n';
}
