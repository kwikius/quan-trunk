#ifndef QUAN_FUSION_TRANSFORMS_HPP_INCLUDED
#define QUAN_FUSION_TRANSFORMS_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/fusion/matrix_multiply.hpp>
#include <quan/static.hpp>

/*
    convenience transforms  for commonly use matrices,
    including translation, rotation, scaling
    needs diffeerntiatiinf 2d and 3d transforms
*/

namespace quan{ namespace fusion{

template <typename Quantity>
struct translation_matrix_elements{

    typedef Quantity quantity_type; 
    typedef typename quan::meta::binary_operation<
        quantity_type,
        quan::meta::divides,
        quantity_type
    >::type value_type;
     typedef typename quan::meta::binary_operation<
        value_type,
        quan::meta::divides,
        quantity_type
    >::type reciprocal_type;
   
    typedef typename quan::static_<value_type,0>::type zero;
    typedef typename quan::static_<value_type,1>::type one;
    typedef typename quan::static_<
        reciprocal_type,0
    >::type static_zero_reciprocal_type;

    typedef boost::fusion::vector9<
        one,            zero,           static_zero_reciprocal_type, 
        zero,           one,            static_zero_reciprocal_type, 
        quantity_type,   quantity_type,     one 
    > type;
};

template <int D>
struct translation_matrix;

template <>
struct translation_matrix<2>{

    template <typename Quantity>
    struct result{
        typedef quan::rc_matrix<
            3,3, typename translation_matrix_elements<Quantity>::type
        > type;
    };

    template <typename Quantity>
    typename result<Quantity>::type
    operator()(Quantity const & q1, Quantity const & q2)const
    {
        typedef typename result<Quantity>::type result_type;
        typedef translation_matrix_elements<Quantity> te;
        return result_type(
            typename te::type(
                typename te::one(),
                    typename te::zero(),
                        typename te::static_zero_reciprocal_type(), 
                typename te::zero(),
                    typename te::one(),
                        typename te::static_zero_reciprocal_type(), 
                q1, q2, typename te::one() 
            )
        );
    }
};

template <typename Quantity>
struct rotation_matrix_elements{

    typedef Quantity quantity_type; 
    typedef typename quan::meta::binary_operation<
        quantity_type,
        quan::meta::divides,
        quantity_type
    >::type value_type;
     typedef typename quan::meta::binary_operation<
        value_type,
        quan::meta::divides,
        quantity_type
    >::type reciprocal_type;
   
    typedef typename quan::static_<value_type,1>::type one;

    typedef typename quan::static_<
        reciprocal_type,0
    >::type static_zero_reciprocal_type;

     typedef typename quan::static_<
        quantity_type,0
    >::type static_zero_quantity_type;

    typedef boost::fusion::vector9<
        value_type, value_type,static_zero_reciprocal_type,
        value_type, value_type,static_zero_reciprocal_type,
        static_zero_quantity_type,static_zero_quantity_type,one
    > type;
};

template <typename Quantity, int D>
struct rotation_matrix;

template<typename Quantity>
struct rotation_matrix<Quantity,2>{

    struct result{
        typedef quan::rc_matrix<
            3,3,
            typename rotation_matrix_elements<Quantity>::type
        > type;
    };
    
    typename result::type
    operator()( double const & theta)const
    {
        typedef typename result::type result_type;
        typedef rotation_matrix_elements<Quantity> re;
        return result_type(
            typename re::type(
                cos(theta),
                    sin(theta),
                        typename re::static_zero_reciprocal_type(),
                -sin(theta),
                    cos(theta),
                        typename re::static_zero_reciprocal_type(),
                typename re::static_zero_quantity_type(),
                   typename re::static_zero_quantity_type(),
                        typename re::one()
            )
        );
    }
};

// should be ...<2>
template <typename Quantity>
struct scaling_matrix_elements{

    typedef Quantity quantity_type; 
    typedef typename quan::meta::binary_operation<
        quantity_type,
        quan::meta::divides,
        quantity_type
    >::type value_type;
    typedef typename quan::static_<value_type,0>::type zero;
    typedef typename quan::static_<value_type,1>::type one;
    typedef typename quan::static_<quantity_type,0>::type static_zero_quantity_type;

    typedef boost::fusion::vector9<
        quantity_type,  static_zero_quantity_type, static_zero_quantity_type, 
        static_zero_quantity_type, quantity_type, static_zero_quantity_type, 
        zero,                       zero,                       one
    > type;
};

template <int D> 
struct scaling_matrix;

template<>
struct scaling_matrix<2>{

    template <typename Quantity>
    struct result{
        typedef quan::rc_matrix<
            3,3,
            typename scaling_matrix_elements<Quantity>::type
        > type;
    };

    template<typename Quantity>
    typename result<Quantity>::type
    operator()(Quantity const & q1, Quantity const & q2) const
    {
        typedef typename result<Quantity>::type result_type;
        typedef scaling_matrix_elements<Quantity> se;
        return result_type(
            typename se::type(
                 q1,
                    typename se::static_zero_quantity_type(),
                        typename se::static_zero_quantity_type(), 
                typename se::static_zero_quantity_type(),
                    q2,
                        typename se::static_zero_quantity_type(), 
                typename se::zero(),
                    typename se::zero(),
                        typename se::one()
            )
        );
    }
};

template <int D> struct coordinate;
template <>
struct coordinate<2>{

    template <typename Quantity>
    struct result{
        typedef typename quan::meta::binary_operation<
            Quantity, quan::meta::divides,Quantity
        >::type value_type;
        typedef typename quan::static_<value_type,1>::type one;
        typedef boost::fusion::vector3<
            Quantity, Quantity, one
        > elements_type;
        
        typedef quan::rc_matrix<1,3,elements_type> type;
    };
    template <typename Quantity>
    typename result<Quantity>::type
    operator()(Quantity const & x, Quantity const & y) const
    {
       typedef  typename result<Quantity>::type result_type;
       typedef  typename result<Quantity>::elements_type elements_type;
       typedef  typename result<Quantity>::one one;
       return result_type(elements_type(x,y,one()));
    }
};

}}//quan::fusion


#endif
