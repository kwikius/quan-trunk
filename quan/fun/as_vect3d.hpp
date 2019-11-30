#ifndef QUAN_FUN_AS_VECT3D_HPP_INCLUDED
#define QUAN_FUN_AS_VECT3D_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/bool.hpp>
#include <quan/fusion/matrix.hpp>
#include <quan/fun/matrix.hpp>
#include <quan/three_d/vect.hpp>

namespace quan{ namespace fun{
    
   template <typename M>
   inline
   typename quan::where_< 
      quan::meta::and_<
         quan::fun::is_fun_matrix<M>
         ,quan::meta::bool_< (quan::fusion::num_rows<M> == 1)>
         ,quan::meta::bool_<(quan::fusion::num_columns<M> == 4)>
      >,
      quan::three_d::vect<typename quan::fusion::matrix_at_t<0,0,M>::type>
   >::type
   as_vect3d( M const & in)
   {
       typedef typename quan::fusion::matrix_at_t<0,0,M>::type value_type;
       return quan::three_d::vect<value_type>{in. template at<0,0>(),in. template at<0,1>(),in.template at<0,2>()};
   }

}}

#endif // QUAN_FUN_AS_VECT3D_HPP_INCLUDED
