#ifndef QUAN_FUSION_MAKE_3D_Y_ROTATION_MATRIX_HPP_INCLUDED
#define QUAN_FUSION_MAKE_3D_Y_ROTATION_MATRIX_HPP_INCLUDED

#include <quan/fusion/make_matrix.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/vector.hpp>
#include <quan/three_d/vect.hpp>

namespace quan{ namespace fusion{

   namespace detail{

      struct make_3d_y_rotation_matrix_impl{

         template <typename Q>
         struct apply {
            typedef typename quan::meta::binary_op<int, quan::meta::divides,Q>::type div_q;
            typedef QUAN_FLOAT_TYPE float_type;
            typedef quan::fun::vector<
               float_type, int, float_type, div_q,
               int       , int,        int, div_q,
               float_type, int, float_type, div_q,
                        Q,   Q,          Q,   int
            > vect_type;

            typedef quan::fun::matrix<4,4,vect_type> type;
         };

         template <typename Q>
         typename apply<Q>::type
         operator()( Q const & , quan::angle::rad theta) const
         {
            return quan::fusion::make_matrix<4>(
               cos(theta),   0,sin(theta), 0/Q{1},
                        0,   1,          0, 0/Q{1},
               -sin(theta),   0, cos(theta), 0/Q{1},
                      Q{}, Q{},        Q{},      1
            );
         }
      };
   }

   template <typename Q>
   inline
   typename quan::fusion::detail::make_3d_y_rotation_matrix_impl::apply<Q>::type
   make_3d_y_rotation_matrix(quan::angle::rad const & theta)
   {
      return quan::fusion::detail::make_3d_y_rotation_matrix_impl{} (Q{}, theta);
   }

}} // quan::fusion

#endif // QUAN_FUSION_MAKE_3D_Y_ROTATION_MATRIX_HPP_INCLUDED
