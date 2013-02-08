// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/all_types.hpp>
#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#include <quan_matters/src/constant.cpp>
#include <quan_matters/src/magnetic_constant.cpp>
#include <quan_matters/src/gas_constant.cpp>
#else
#include <quan/constants/constant.hpp>
#include <quan/constants/magnetic_constant.hpp>
#include <quan/constants/gas_constant.hpp>
#endif

/*
    Do some calculations to check for dimensional 
    errors in predefined quantities definitions
    Try to cover each type and link each one in

*/

namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(dims_check_test1)
    QUAN_TEST_FUN(dims_check_test2)
    QUAN_TEST_FUN(dims_check_test3)
    QUAN_TEST_FUN(gas_law)

#undef QUAN_TEST_FUN
}

void dim_checks_test()
{
#define QUAN_TEST_FUN(fun) fun();
    QUAN_TEST_FUN(dims_check_test1)
    QUAN_TEST_FUN(dims_check_test2)
    QUAN_TEST_FUN(dims_check_test3)
    QUAN_TEST_FUN(gas_law)

#undef QUAN_TEST_FUN
}

namespace {

   void dims_check_test1()
   {
       quan::length::m  length(1);
       quan::area::m2 area = length * length;
   // 'time' id causes issues on some gcc, hence add '_' suffix 
       quan::time::s    time_(1);
       quan::velocity::m_per_s velocity = length / time_;
       quan::acceleration::m_per_s2 acceleration = velocity / time_;
       quan::mass::kg mass(1);
       quan::force::N force = mass * acceleration;
       quan::energy::J  energy = force * length;
       quan::torque::N_m tq = force * length;
       quan::power::W  power = energy / time_;
       power = quan::voltage::V(1) * quan::current::A(1);
       quan::volume::m3 volume = area * length;
       quan::density::kg_per_m3 d = mass / volume;
       quan::frequency::Hz  freq = 1 / time_;
       quan::pressure::Pa  pressure = force / area;
       quan::mass_flow::kg_per_s mass_flow = mass / time_;
       quan::reciprocal_time::per_s reciprocal_time = 1/time_;
       quan::circulation::m2_per_s circulation = area / time_;
       quan::density::kg_per_m3 density = mass / volume;
       quan::reciprocal_mass::per_kg reciprocal_mass = 1/ quan::mass::kg(1);
   }


   void dims_check_test2()
   {
       quan::current::mA current(1);
       quan::resistance::kR resistance(2);
       quan::conductance::S conductance = 1/resistance;
       quan::voltage::V voltage = current * resistance;
       quan::potential_difference::V potd = voltage;
       voltage = quan::inductance::mH(1) * current / quan::time::s(1);
       quan::power::W power = voltage * current;
       quan::power::mW power1 = quan::pow<2>(voltage) / resistance;
       quan::power::MW power2 = quan::pow<2>(current) * resistance;
       quan::charge::mC charge = current * quan::time::s(1);
       quan::capacitance::uF capacitance = charge / voltage;
       

       QUAN_FLOAT_TYPE const & pi = quan::constant::pi;
       using quan::magnetic_constant;
       int num_turns = 5;
       quan::length::mm coil_radius(25);
       quan::magnetomotive_force::A mmf 
       = current * num_turns;
       
       quan::magnetic_field_strength::mA_per_m mfs 
       = mmf /( 2 * pi * coil_radius) ;

       quan::magnetic_flux_density::mT  B 
       = magnetic_constant::mu0 * mfs;
       double value = magnetic_constant::mu0 * quan::pow<2>(quan::current::A(1))/ quan::force::N(1);

       quan::magnetic_flux::mWb flux
       = B * pi * quan::pow<2>(coil_radius);
       quan::meta::binary_op<
           quan::magnetic_flux_density::mT,
           quan::meta::divides,
           quan::magnetic_field_strength::mA_per_m
       >::type perm = magnetic_constant::mu0; 
       quan::magnetic_permeability::mH_per_m mu = B / mfs;
   }

   void gas_law()
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
   }
   void dims_check_test3()
   {
       quan::length::m length(1);
       quan::time::s time_(1);
       quan::mass::kg mass(1);
       quan::temperature::K temperature(1);
       quan::current::A current(1);
       quan::substance::mol subst(1);
       quan::intensity::cd intensity(1);
       quan::energy::J energy(1); 
       quan::area::m2 area(1);
       quan::force::N force(1);
       quan::volume::m3 volume(1);
       quan::power::W power(1);
       quan::pressure::Pa pressure(1);

       quan::energy_per_mass:: J_per_kg e_per_kg = energy / mass;
       quan::energy_per_area_time::    W_per_m2 v1 = energy / (area * time_);
       v1 = power / area;
       quan::volume_flow:: m3_per_s v2 = volume / time_;
       quan::force_per_mass::  N_per_kg v3 = force / mass;
       quan::energy_per_area_time::    W_per_m2 v4 = energy / (area*time_);
       quan::force_per_length::    N_per_m v5 = force / length;
       quan::energy_per_volume::   J_per_m3 v6 = energy / volume;
       quan::energy_per_mass:: J_per_kg v7 = energy / mass;
       quan::heat_transfer_coefficient:: W_per_m2_K  v8= power / (area * temperature);
       quan::heat_density:: J_per_m2 v9 = energy / area;
       quan::heat_flow_density::W_per_m2 v10 = power / area;
       quan::volume_per_energy::m3_per_J v11 = volume / energy;
       quan::fuel_consumption::m_per_m3  v12 =  length / volume;
       quan::entropy::J_per_K v13 = energy / temperature;
       quan::heat_flow::W v14 = power;
       quan::specific_entropy::J_per_kg_K v15 = energy / (mass * temperature);
       quan::thermal_conductivity::W_per_m_K v16= power /(length * temperature);
       quan::thermal_diffusivity::m2_per_s v17 = area / time_;
       quan::thermal_insulance::m2_K_per_W v18 = area * temperature / (power);
       quan::thermal_resistance::K_per_W v19 = temperature / power;
       quan::thermal_resistivity::m_K_per_W v20 = length * temperature / power;
       quan::permeability::kg_per_Pa_s_m2 v21 = mass / (pressure * time_* area);
   }
}

