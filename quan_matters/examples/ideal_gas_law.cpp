// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.

// Calculation of amount of substance in a gas using gas constant

#include <quan/temperature.hpp>
#include <quan/pressure.hpp>
#include <quan/length.hpp>
#include <quan/volume.hpp>
#include <quan/out/substance.hpp>


#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#include <quan_matters/src/constant.cpp>
#include <quan_matters/src/gas_constant.cpp>
#else 
// pi etc
#include <quan/constants/constant.hpp>
// dimensionally correct gas_constant
#include <quan/constants/gas_constant.hpp>
#endif

void f1()
{
   
    using quan::gas_constant;
    using quan::pow;
    using quan::temperature;
    using quan::pressure;
    using quan::length;
    using quan::volume;
    using quan::substance;
    double const & pi = quan::constant::pi;

    temperature::K  T(310);
    pressure::Pa    P(1.01325e5);
    length::m       r(0.5e-6);
    volume::m3      V = 4.0 / 3.0 * pi * pow<3>(r);
    substance::mol  subst = P * V /(gas_constant::R * T);
    std::cout << subst << '\n';
}

double const gas_constant_R(8.3145);
void f2()
{
    using quan::pow;
    using quan::gas_constant;

    double const & pi = quan::constant::pi;
    double  T(310);
    double     P(1.01325e5);
    double      r(0.5e-6);
    double      V = 4.0 / 3.0 * pi * pow<3>(r);
    double  subst = P * V /(gas_constant_R * T);
    std::cout << subst << '\n';

}

int main()
{  
 f1();
 f2();
}
