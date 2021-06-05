#include <quan/uav/position.hpp>
#include <quan/out/length.hpp>
#include <quan/out/angle.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <cstdio>
#include <curl/curl.h>

namespace {

   QUAN_QUANTITY_LITERAL(angle,deg)
   QUAN_QUANTITY_LITERAL(length,m)

   using gps_location = quan::uav::position<quan::angle::deg,quan::length::m>;

//-0.608432 51.842102
   gps_location constexpr IvinghoeBeacon = {51.842105956934176_deg,-0.608274007893641_deg,233_m};

   template <typename T>
   void qprintf( T const & v, const char* format)
   {
      fprintf(stdout,format,v.numeric_value(),units_str(v).c_str());
   }
}

int main()
{
   qprintf(IvinghoeBeacon.lat,"% 20.15f %s\n");
   qprintf(IvinghoeBeacon.lon,"% 20.15f %s\n");
   qprintf(IvinghoeBeacon.alt,"% 6.1f %s\n");
}


