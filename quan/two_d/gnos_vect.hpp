#ifndef QUAN_TWO_D_GNOS_VECT_HPP_INCLUDED
#define QUAN_TWO_D_GNOS_VECT_HPP_INCLUDED

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
 along with this program. If not, see http://www.gnu.org/licenses./
 */

/*
   2d homogeneous vector for use in matrices etc.
    ("gnos_vect" is meant to be short for homogeneous_vect)
    converts to from ordinary vect
*/

#include <tuple>
#include <quan/two_d/vect_def.hpp>
#include <quan/where.hpp>
#include <type_traits>
#include <quan/implicit_cast.hpp>

namespace quan{ namespace two_d{
 
    namespace detail{

        template <typename T>
        struct gnos_vect_base{
            typedef decltype( T() / T() ) value_type;
            typedef decltype( value_type() / T()) reciprocal_type;
            typedef std::tuple<
                value_type,
                value_type, 
                reciprocal_type
            > base_type;
        };
    }//detail

    template <typename T>
    struct gnos_vect : detail::gnos_vect_base<T>::base_type
    {
        typedef detail::gnos_vect_base<T> base_container_type;
        typedef typename base_container_type::base_type base_type;
        typedef typename base_container_type::value_type value_type;
        typedef typename base_container_type::reciprocal_type reciprocal_type;

        gnos_vect() 
        : base_type(value_type(0),value_type(0),reciprocal_type(1)){} 
        template <typename T1>
        gnos_vect(vect<T1> const & in)
        :base_type( 
             quan::implicit_cast<value_type>(in.x / T(1))
            ,quan::implicit_cast<value_type>(in.y / T(1))
            , reciprocal_type(1)
        ){} 
        template<typename T0, typename T1, typename T2>
        gnos_vect(T0 const & t0, T1 const & t1, T2 const & t2 ) 
        : base_type(
            quan::implicit_cast<value_type>(t0)
            ,quan::implicit_cast<value_type>(t1)
            ,quan::implicit_cast<reciprocal_type>(t2)
        ){} 
        template<typename T0, typename T1>
        gnos_vect(T0 const & t0, T1 const & t1 ) 
        : base_type(
            quan::implicit_cast<value_type>(t0)
            ,quan::implicit_cast<value_type>(t1)
           , reciprocal_type(1)
        ){}

       
        template <int N>
        struct type_at{
            typedef typename std::tuple_element<
                N,
               base_type
            >::type type;
        };

        template<int N>
        typename type_at<N>::type
        at()const
        {
            typename type_at<N>::type t = this->get<N>();
            return t;
        }
        template<int N>
        typename type_at<N>::type &
        at()
        {
            typename type_at<N>::type& t = this->get<N>();
            return t;
        }
        operator vect<T>() const
        {
            vect<T> t(
                this->at<0>() / this->at<2>(),
                this->at<1>() / this->at<2>()
            );
            return t;
        }
    };

}}//quan::three_d

#endif


