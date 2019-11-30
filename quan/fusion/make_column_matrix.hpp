#ifndef QUAN_FUSION_MAKE_COLUMN_MATRIX_HPP_INCLUDED
#define QUAN_FUSION_MAKE_COLUMN_MATRIX_HPP_INCLUDED

#include <quan/fusion/make_matrix.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/vector.hpp>
#include <quan/three_d/vect.hpp>

namespace quan { namespace fusion {

   namespace detail{

      struct make_3d_column_matrix_impl{

         template <typename Q>
         struct apply {
            typedef quan::fun::vector<Q,Q,Q,int> vect_type;
            typedef quan::fun::matrix<4,1,vect_type > type;
         };
         template <typename Q>
         constexpr
         typename apply<Q>::type
         operator()( quan::three_d::vect<Q> const & in) const
         {
            return quan::fusion::make_matrix<4>(in.x, in.y, in.z, 1);
         }

      };

   }

   template <typename Q>
   inline
   constexpr
   typename quan::fusion::detail::make_3d_column_matrix_impl::apply<Q>::type
   make_column_matrix(quan::three_d::vect<Q> const & in)
   {
      return quan::fusion::detail::make_3d_column_matrix_impl{} (in);
   }

}}


#endif // QUAN_FUSION_MAKE_COLUMN_MATRIX_HPP_INCLUDED
