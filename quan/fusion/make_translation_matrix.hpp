#ifndef QUAN_FUSION_MAKE_TRANSLATION_MATRIX_HPP_INCLUDED
#define QUAN_FUSION_MAKE_TRANSLATION_MATRIX_HPP_INCLUDED

#include <quan/fusion/make_matrix.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/vector.hpp>
#include <quan/three_d/vect.hpp>

namespace quan{ namespace fusion{

   namespace detail{

      // TODO use static_value

      struct make_3d_translation_matrix_impl{

         template <typename Q>
         struct apply {
            typedef typename quan::meta::binary_op<int, quan::meta::divides,Q>::type div_q;
            typedef quan::fun::vector<
               int, int, int, div_q,
               int, int, int, div_q,
               int, int, int, div_q,
               Q  ,   Q,   Q,   int
            > vect_type;

            typedef quan::fun::matrix<4,4,vect_type> type;
         };

         template <typename Q>
         typename apply<Q>::type
         operator()( quan::three_d::vect<Q> const & in) const
         {
            return quan::fusion::make_matrix<4>(
                  1,   0,     0, 0/Q{1},
                  0,    1,    0, 0/Q{1},
                  0,    0,    1, 0/Q{1},
               in.x, in.y, in.z,      1
            );
         }
      };

      // TODO 2d vect
  }//detail

   template <typename Q>
   inline
   typename quan::fusion::detail::make_3d_translation_matrix_impl::apply<Q>::type
   make_translation_matrix(quan::three_d::vect<Q> const & in)
   {
      return quan::fusion::detail::make_3d_translation_matrix_impl{} (in);
   }

}} // quan::fusion

#endif // QUAN_FUSION_MAKE_TRANSLATION_MATRIX_HPP_INCLUDED
