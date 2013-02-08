#define QUAN_NO_MATH_ANGLE_NUMERIC_CONVERSION
// angles in convenient struct with output
// for quan::angle_<value_type> def see < quan/angle.hpp> line 1041
// derived quan::angle struct at line 1095
#include <quan/out/angle.hpp>
 ///for quan::angle::pi as radians
 #include <quan_matters/src/angle.cpp>
//for quan::constant::pi as double definition required in implementation
 #include <quan_matters/src/constant.cpp>
int main()
{
   
   quan::angle::rad alpha = quan::angle_<int>::rev(1);

// angles comparison (==)operator not working in quan-0-2-0
// hence using::compare(TL,TR, AcceptableErrorEpsilon) works AFAIK
// Note there should be no conversion error from deg to rad in this case
// as the conversion calc should be identical
// but if there is try eg 1e-12 for epsilon

   if ( compare(alpha, quan::angle::two_pi, quan::angle::rad(0)) ==0){
      std::cout << "alpha == 2 * pi\n";
   }
   else {
      std::cout << "conversion error = " << alpha - quan::angle::pi <<'\n';
  } 
}