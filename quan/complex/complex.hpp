#ifndef QUAN_COMPLEX_HPP_INCLUDED
#define QUAN_COMPLEX_HPP_INCLUDED
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
    quan::complex definition
*/
#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/is_numeric.hpp>
#include <type_traits>
#include <quan/meta/is_scalar.hpp>

namespace quan{

   template <typename QReal, typename QImag = QReal>
   class complex;

    template <typename Q>
    class complex<Q,Q>{
        Q m_array[2];
    public:
        
        typedef Q value_type;

        value_type real() const {return m_array[0];}
        value_type imag() const {return m_array[1];}
        complex()
        : m_array{static_cast<Q>(0),static_cast<Q>(0)}
        {
           // m_array[0] = static_cast<Q>(0);
           // m_array[1] = static_cast<Q>(0);
        }

        template <typename Q1>
        complex( Q1 const & in,
            typename quan::where_<
                std::is_convertible<Q1, Q>,
                void*
            >::type =0
        )
        {
            m_array[0] = in;
            m_array[1] = static_cast<Q>(0);
        }

        template <typename Q1, typename Q2>
        complex( Q1 const & in1,Q2 const & in2,
            typename quan::where_<
                quan::meta::and_<
                    std::is_convertible<Q1, Q>,
                    std::is_convertible<Q2, Q>
                >,
                void*
            >::type =0
        )
        {
            m_array[0] = in1;
            m_array[1] = in2;
        } 

        template <typename Q1>
        complex( complex<Q1> const & in,
            typename quan::where_<
                std::is_convertible<Q1, Q>,
                void*
            >::type =0
        )
        {
            m_array[0] = in.real();
            m_array[1] = in.imag();
        } 

        template <typename Q1>
        typename quan::where_<
            std::is_convertible<Q1, Q>,
            complex &
        >::type
        operator =( Q1 const & in)
        {
            m_array[0] = in;
            m_array[1] = static_cast<Q>(0);
            return *this;
        }

        template <typename Q1>
        typename quan::where_<
            std::is_convertible<Q1, Q>,
            complex &
        >::type
        operator =( complex<Q1> const & in)
        {
            m_array[0] = in.real();
            m_array[1] = in.imag();
            return *this;
        }
 
        template <typename Q1>
        typename quan::where_<
            std::is_convertible<Q1, Q>,
            complex &
        >::type
        operator +=( Q1 const & in)
        {
            m_array[0] += in;
            return *this;
        }

        template <typename Q1>
        typename quan::where_<
            std::is_convertible<Q1, Q>,
            complex &
        >::type
        operator +=( complex<Q1> const & in)
        {
            m_array[0] += in.real();
            m_array[1] += in.imag();
            return *this;
        } 
        
        template <typename Q1>
        typename quan::where_<
            std::is_convertible<Q1, Q>,
            complex &
        >::type
        operator -=( Q1 const & in)
        {
            m_array[0] -= in;
            return *this;
        }

        template <typename Q1>
        typename quan::where_<
            std::is_convertible<Q1, Q>,
            complex &
        >::type
        operator -=( complex<Q1> const & in)
        {
            m_array[0] -= in.real();
            m_array[1] -= in.imag();
            return *this;
        } 

        template <typename Numeric>
        typename quan::where_<
            std::is_convertible<
                Q,
                typename quan::meta::binary_op<
                    Q ,quan::meta::times,Numeric
                >::type
            >,
            complex &
        >::type
        operator *=( Numeric const & in)
        {
            m_array[0] *= in;
            m_array[1] *= in;
            return *this;
        }

        template <typename Numeric>
        typename quan::where_<
            std::is_convertible<
                Q,
                typename quan::meta::binary_op<
                    Q ,quan::meta::times,Numeric
                >::type
            >,
            complex &
        >::type
        operator *=( complex<Numeric> const & in)
        {
            Numeric ini = in.imag();
            value_type tr = m_array[0];
            tr *= ini;
            value_type ti = m_array[1];
            ti *= ini;
            Numeric inr = in.real();
            m_array[0] *= inr;
            m_array[1] *= inr;
            m_array[0] -= ti;
            m_array[1] += tr;
            return *this;
        } 

        template <typename Numeric>
        typename quan::where_<
            std::is_convertible<
                Q,
                typename quan::meta::binary_op<
                    Q ,quan::meta::divides,Numeric
                >::type
            >,
            complex &
        >::type
        operator /=( Numeric const & in)
        {
            m_array[0] /= in;
            m_array[1] /= in;
            return *this;
        }

        template <typename Numeric>
        typename quan::where_<
            std::is_convertible<
                Q,
                typename quan::meta::binary_op<
                    Q ,quan::meta::divides,Numeric
                >::type
            >,
            complex &
        >::type
        operator /=( complex<Numeric> const & in)
        {
            typename quan::meta::binary_op<
                    Numeric,
                    quan::meta::times,
                    Numeric
            >::result_type denom = in.real() * in.real() + in.imag() * in.imag(); 
            // check for division by zero
            value_type t_real
            =(this->real() * in.real() + this->imag() * in.imag()) / denom;
            m_array[1] 
            = (in.real() * this->imag() - this->real() * in.imag()) / denom;
            m_array[0] = t_real;
            return * this;
        }        
    };

}//quan
namespace quan{namespace meta{

   namespace impl {
      template <typename QL, typename Op, typename QR>
      struct binary_op_impl<
         quan::complex<QL>,Op,quan::complex<QR>
      > {
         typedef quan::complex<
            typename binary_op<
               QL,Op,QR
            >::type
         > type;
      };
      template <typename QL, typename Op, typename QR>
      struct binary_op_impl<
         quan::complex<QL>,Op,QR,
         typename quan::where_<
            quan::meta::is_scalar<QR>
         >::type
      > {
         typedef quan::complex<
            typename binary_op<
               QL,Op,QR
            >::type
         > type;
      };

      template <typename QL, typename Op, typename QR>
      struct binary_op_impl<
         QL,Op,quan::complex<QR>,
         typename quan::where_<
            quan::meta::is_scalar<QL>
         >::type
      > {
         typedef quan::complex<
            typename binary_op<
               QL,Op,QR
            >::type
         > type;
      };
   }// impl

}}

namespace quan {

      template <typename QL, typename QR>
      typename quan::meta::binary_op<
         quan::complex<QL>,quan::meta::times,quan::complex<QR>
      >::type
      operator *(quan::complex<QL> const & lhs,quan::complex<QR> const & ths);

      template <typename QL, typename QR>
      typename quan::meta::binary_op<
         quan::complex<QL>,quan::meta::divides,quan::complex<QR>
      >::type
      operator /(quan::complex<QL> const & lhs,quan::complex<QR> const & ths);

} //quan

#endif
