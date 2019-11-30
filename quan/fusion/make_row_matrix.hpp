#ifndef QUAN_FUSION_MAKE_ROW_MATRIX_HPP_INCLUDED
#define QUAN_FUSION_MAKE_ROW_MATRIX_HPP_INCLUDED

#include <quan/fusion/make_matrix.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/vector.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/fusion/static_value.hpp>

namespace quan { namespace fusion {

   namespace detail{

      struct make_3d_row_matrix_impl{
         typedef quan::fusion::static_value<int,quan::meta::rational<1> > one;
         template <typename Q>
         struct apply {
            
            typedef quan::fun::vector<Q,Q,Q,one> vect_type;
            typedef quan::fun::matrix<1,4,vect_type > type;
         };
         template <typename Q>
         constexpr
         typename apply<Q>::type
         operator()( quan::three_d::vect<Q> const & in) const
         {
            return quan::fusion::make_matrix<1>(in.x, in.y, in.z, one{});
         }

      };

   }

   template <typename Q>
   inline
   constexpr 
   typename quan::fusion::detail::make_3d_row_matrix_impl::apply<Q>::type
   make_row_matrix(quan::three_d::vect<Q> const & in)
   {
      return quan::fusion::detail::make_3d_row_matrix_impl{} (in);
   }

}}


#endif // QUAN_FUSION_MAKE_ROW_MATRIX_HPP_INCLUDED
