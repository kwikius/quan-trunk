#ifndef QUAN_THREE_D_QUAT_TO_MATRIX_OPEN_GL_HPP_INCLUDED
#define QUAN_THREE_D_QUAT_TO_MATRIX_OPEN_GL_HPP_INCLUDED

#include <quan/three_d/quat.hpp>
#include <quan/basic_matrix/basic_matrix.hpp>

namespace quan{namespace three_d{
   /**
   *  Set mR matrix above to quaternion rotation.
   *  \param[in] q quaternion to convert to openGL matrix.
   *  \param[out] mR matrix to convert into
   *  \pre rot_quat is a unit quaternion
   *   use mR.get_array() to send to OpenGL functions
   */
   inline void quatToMatrixOpenGL(quan::three_d::quat<double> const & q, quan::basic_matrix<4,4,float> & mR)
   {

     // Fill matrix dependent or which way matrix is represented
     // This way works in OpenGL
      mR.at(0,0) = q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z;
         mR.at(1,0) = 2.f * (q.x * q.y - q.w * q.z);
            mR.at(2,0) = 2.f * ( q.x * q.z + q.w * q.y);
               mR.at(3,0) = 0.f;

      mR.at(0,1) = 2.f * (q.x * q.y + q.w * q.z);
         mR.at(1,1) = q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z;
            mR.at(2,1) = 2.f * ( q.y * q.z  - q.w * q.x);
               mR.at(3,1) = 0.f;

      mR.at(0,2) = 2 * ( q.x * q.z - q.w * q.y);
         mR.at(1,2) = 2 * ( q.y * q.z + q.w * q.x);
            mR.at(2,2) = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;
               mR.at(3,1) = 0.f;

      mR.at(0,3) = 0.f;
         mR.at(1,3) = 0.f;
            mR.at(2,3) = 0.f;
               mR.at(3,3) = 1.f;

   }

}} //quan::three_d

#endif // QUAN_THREE_D_QUAT_TO_MATRIX_OPEN_GL_HPP_INCLUDED
