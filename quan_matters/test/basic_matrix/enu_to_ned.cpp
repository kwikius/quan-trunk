
#include <quan_matters/test/test.hpp>
#include <quan/basic_matrix/basic_matrix.hpp>

/*
   coordinate frames
   ENU == East North Down
   NED == North East Up

   ENU x:+E, y:+N, z:+Up
   NED x:+N, y:+E  z:+Down

   ENU to NED  NED.x <- ENU.y, NED.y <- ENU.x, NED.z <-ENU.z

   [ a, b, c    [ x      [ a x + by + cz,    x -> y  a = 0, b= 1, c = 0
     d, e, f      y        d x + ey + fz     y -> x  d = 1, e = 0, f = 0
     g, h, i ]    z ]      gx + hY + i z]    z -> -z g = 0, h = 0, i = -1

   so matrix for ENU to NED

   [ 0, 1, 0,     [ x,
     1, 0, 0,  *    y,
     0, 0, -1]      z ]
*/

int main()
{
   quan::basic_matrix<3,3> constexpr ENUtoNED{
      0,1,0,
      1,0,0,
      0,0,-1
   };

   quan::basic_matrix<3,1> constexpr pt{
         1,
         2,
         3
   };

   auto const res = ENUtoNED * pt;

   display(res,"ENUtoNed = ");

   QUAN_CHECK(( std::is_same<quan::meta::strip_cr<decltype(res)>::type, quan::basic_matrix<3,1,double> >::value));
   QUAN_CHECK( (res.at(0,0) == 2) );
   QUAN_CHECK( (res.at(0,1) == 1) );
   QUAN_CHECK( (res.at(0,2) == -3) );

   QUAN_EPILOGUE

}

int errors = 0;
