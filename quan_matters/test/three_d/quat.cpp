/*
Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses.
*/


#include <quan_matters/test/test.hpp>
#include <iomanip>
#include <quan/three_d/quat.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/length.hpp>
#include <quan/current.hpp>
#include <quan/angle.hpp>

#include <quan/three_d/rotation_from.hpp>

namespace {

   void rotation_from_id_test()
   {
       quan::three_d::vect<double> lhs{1,0,0};

       quan::three_d::vect<double> rhs{1,0,0};

       auto rot = rotation_from(lhs,rhs);
       QUAN_CHECK((rot == quan::three_d::quat<double>{1,0,0,0}));

     //  std::cout  << "rot = " << rot <<'\n';

       auto res = rot * lhs;

     //  std::cout << "res = "  << res <<'\n';

       QUAN_CHECK(   abs( magnitude(res) - 1.0)  == 0);

      // auto res1 = magnitude(res - rhs);
      // std::cout << res1 <<'\n';
   }

   void rotation_from_opposite_test_x()
   {
       
       quan::three_d::vect<double> lhs1{1,0,0};

       quan::three_d::vect<double> rhs1{-1,0,0};

     // std::cout << "v x rhs = " << rhs1 << "\n";
       auto rot1 = rotation_from(lhs1,rhs1);

     //  std::cout  << "rot1 = " << rot1 <<'\n';

       auto res1 = rot1 * lhs1;

      // std::cout << "res1 = "  << res1 <<'\n';

       QUAN_CHECK(   abs( magnitude(res1) - 1.0)  < 1.e-6);

     //  auto m1 = magnitude(res1 - rhs1);
     //  std::cout << "magnitude = " << m1 <<'\n';
   }

   void rotation_from_opposite_test_y()
   {

       quan::three_d::vect<double> lhs1{0,1,0};

       quan::three_d::vect<double> rhs1{0,-1,0};

      // std::cout << "v y rhs = " << rhs1 << "\n";
       auto rot1 = rotation_from(lhs1,rhs1);

      // std::cout  << "rot1 = " << rot1 <<'\n';

       auto res1 = rot1 * lhs1;

      // std::cout << "res1 = "  << res1 <<'\n';

       QUAN_CHECK(   abs( magnitude(res1) - 1.0)  < 1.e-6);

     //  auto m1 = magnitude(res1 - rhs1);
      // std::cout << "magnitude = " << m1 <<'\n';
   }

   void rotation_from_opposite_test_z()
   {
       quan::three_d::vect<double> lhs1{0,0,1};

       quan::three_d::vect<double> rhs1{0,0,-1};

      // std::cout << "v z rhs = " << rhs1 << "\n";

       auto rot1 = rotation_from(lhs1,rhs1);

     //  std::cout  << "rot1 = " << rot1 <<'\n';

       // apply the rotation
       auto res1 = rot1 * lhs1;

     //  std::cout << "res1 = "  << res1 <<'\n';

       QUAN_CHECK(   abs( magnitude(res1) - 1.0)  < 1.e-6);

      // auto m1 = magnitude(res1 - rhs1);
      // std::cout << "magnitude = " << m1 <<'\n';
   }

   void quat_test1()
   {
       // The use of these types is unorthodox, but it shows that
       // the quat is independent of the type of elements!
       // IOW its only the ratio between them that matters
       typedef quan::current::A type1;
       typedef quan::length::m type2;
       
       typedef quan::three_d::quat<type1> quat;
       typedef quan::three_d::vect<type2> vect;
       quat q(type1(2.5),type1(3.2),type1(-4.8),type1(.5));
       vect v(type2(2),type2(.5),type2(-20));
       vect v1 = q * v;
       vect v2 = multiply(q,v);
       // multiply is the previous version of operator*(quat,vect) 
       // just to check the result is equivalent
       // The calcs are done differently, with division on a different value
       // so there will be some difference in result
       // accuracy. Thats why I use a tolerance bucket:
       
       type2 epsilon(FP_MAX_DIFFERENCE);
       QUAN_CHECK( 
           (compare(v1.x,v2.x,epsilon)==0)
        && (compare(v1.y,v2.y,epsilon)==0)
        && (compare(v1.z,v2.z,epsilon)==0)
       );
   }

   void quat_rot_test()
   {

      typedef quan::three_d::quat<double> quat;
    
      // point to rotate, expressed as a quaternion ( w part is 0)
      quat pt{0,1,0,0};
      
      //axis to rotate around (unit vector)
      auto axis = unit_vector(quan::three_d::vect<double>{0,0,1}); // rotate around z

      // angle to rotate by around above axis
      quan::angle::deg angle{90}; 

      // calculate the rotation quaternion
     // quat rot{cos(angle/2),axis.x * sin(angle/2),axis.y * sin(angle/2),axis.z * sin(angle/2)};
      quat rot = quatFrom(axis,angle);
      //std::cout << std::fixed << std::setprecision(3) << "rotation quat = " <<  rot <<'\n';

      //calculate the resulting pont
      quat result = hamilton_product(hamilton_product(rot,pt),conjugate(rot));

      //std::cout << std::fixed << std::setprecision(3) << "result = " << result << '\n';
      double constexpr epsilon = 1e-6;
      QUAN_CHECK(
            (quan::compare(result.w,0,epsilon) == 0) &&
            (quan::compare(result.x,0,epsilon) == 0) &&
            (quan::compare(result.y,1,epsilon) == 0) &&
            (quan::compare(result.z,0,epsilon) == 0)
      )
   }
}


/*
    Basic go-no-go of quan::three_d::quat
*/

void quat_test()
{
    quat_test1();
    quat_rot_test();
    rotation_from_id_test();
    rotation_from_opposite_test_x();
    rotation_from_opposite_test_y();
    rotation_from_opposite_test_z();
}

#if 0
int errors = 0;
int main()
{
   quat_test();
   quat_rot_test();
   EPILOGUE
}
#endif



