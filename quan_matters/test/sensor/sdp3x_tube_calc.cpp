

#include <cstdint>
#include <quan_matters/test/test.hpp>
#include <quan/constants/constant.hpp>
#include <quan/length.hpp>

/*
  CRC test for Sensirion SDP3x digital differential pressure sensor
*/

namespace {

   float constexpr m_c = 4.79e-7f ;  // kg.s-1 
   float constexpr delta_p_c = 101.f; // Pa
   float constexpr hose_length = 0.3f;  // m
   float constexpr hose_inner_dia = 0.0018f; // m


   float const t_deg_C = 25.f; // deg_c from sensor
   float const p_abs_bar = 1.f; // absolute pressure, get from baro
   float const delta_p_sensor = 250.f; // differential pressure reading

   float const n_air =  (18.205f + 0.0484f * (t_deg_C - 20 )) * 1.e-6f; //( Pa.s-1)

   float const p_air = (1.1885f * p_abs_bar) * 293.15f / (273.15f + t_deg_C); // kg.m-3
 
}

int errors = 0;

int main()
{
  float const c1 = -64/ quan::constant::pi * n_air/ p_air * m_c / delta_p_sensor * ( quan::sqrt(1.f + 8.f * delta_p_sensor/delta_p_c) -1.f);

  float const epsilon = c1 * hose_length / quan::pow<4>(hose_inner_dia); 

  float dp_eff = delta_p_sensor / (1 + epsilon);

  std::cout << dp_eff <<'\n';

  QUAN_EPILOGUE
   
}


