#define QUAN_NO_MATH_ANGLE_NUMERIC_CONVERSION

//// rad/s to freq.
#include <quan/out/angle.hpp>
#include <quan/out/reciprocal_time.hpp>
#include <quan/out/time.hpp>
#include <quan/out/length.hpp>
///for angle::pi def
#include <quan_matters/src/angle.cpp>
#include <quan_matters/src/constant.cpp>

int main()
{
   // use angle as value_type
   // radians
   typedef quan::reciprocal_time_<quan::angle::rad>::per_s rad_per_s;

   // quan::angle rev is a fraction of revolution 
   // representing an angle type of 1 revolution
   typedef quan::reciprocal_time_<quan::angle::rev>::per_min rev_per_min;

   rad_per_s mu( quan::angle::rad(1));

   rev_per_min rpm =mu;

   std::cout << "rpm = " << rpm <<'\n';

// compute an arc length from quantity with rev_per_min
   quan::length::m radius(12);
   quan::time::s t(1);
//using "strong" angle type arc length value_type must be angular...
#if (0)
// should fail 
   quan::length_<double>::m arc_length = rpm * radius * t;
#else
//should succeed
   quan::length_<quan::angle::rad>::m arc_length = rpm * radius * t;
#endif
   std::cout 
   << arc_length << " should be same as " << radius << " (but \"angular\")\n";
}