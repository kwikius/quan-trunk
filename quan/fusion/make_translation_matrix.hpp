#ifndef QUAN_FUSION_MAKE_TRANSLATION_MATRIX_HPP_INCLUDED
#define QUAN_FUSION_MAKE_TRANSLATION_MATRIX_HPP_INCLUDED

#include <quan/fusion/make_matrix.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/vector.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/fusion/static_value.hpp>

namespace quan{ namespace fusion{

   namespace detail{

      struct make_3d_translation_matrix_impl{
         typedef quan::fusion::static_value<int,quan::meta::rational<1> > one;
         typedef quan::fusion::static_value<int,quan::meta::rational<0> > zero;
         
         template <typename Q>
         struct apply {
            
            typedef typename quan::meta::binary_op<int, quan::meta::divides,Q>::type rt_div_q;
            typedef quan::fusion::static_value<rt_div_q,quan::meta::rational<0> > zero_div_q;

           typedef quan::fun::vector<
                one, zero, zero, zero_div_q,
               zero,  one, zero, zero_div_q,
               zero, zero,  one, zero_div_q,
               Q,       Q,    Q,        one
            > vect_type;

            typedef quan::fun::matrix<4,4,vect_type> type;
         };

         template <typename Q>
         constexpr
         typename apply<Q>::type
         operator()( quan::three_d::vect<Q> const & in) const
         {
            typedef typename apply<Q>::zero_div_q zero_div_q;
            return quan::fusion::make_matrix<4> (
                one{}, zero{}, zero{}, zero_div_q{},
               zero{},  one{}, zero{}, zero_div_q{},
               zero{}, zero{},  one{}, zero_div_q{},
                 in.x,   in.y,   in.z,        one{}
            );
         }
      };

      // TODO 2d vect
  }//detail

   template <typename Q>
   inline
   constexpr
   typename quan::fusion::detail::make_3d_translation_matrix_impl::apply<Q>::type
   make_translation_matrix(quan::three_d::vect<Q> const & in)
   {
      return quan::fusion::detail::make_3d_translation_matrix_impl{} (in);
   }

}} // quan::fusion

#endif // QUAN_FUSION_MAKE_TRANSLATION_MATRIX_HPP_INCLUDED
