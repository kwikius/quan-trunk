#ifndef QUAN_UNITED_VALUE_HPP_INCLUDED
#define QUAN_UNITED_VALUE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    united_value is a quantity without dimensional analysis
*/
#include <quan/config.hpp>
#include <quan/quantity_traits.hpp>
#include <quan/detail/united_value/united_value_fwd.hpp>
#include <quan/detail/united_value/operations/value_cast.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/where.hpp>

namespace quan{ namespace meta{

  namespace impl{
#define QUAN_UNITED_VALUE_BINOP(Op) \
    template < \
        typename ConversionFactor_L , \
        typename NumericType_L , \
        typename ConversionFactor_R , \
        typename NumericType_R \
    > \
    struct binary_op_impl< \
        quan ::detail::united_value<ConversionFactor_L , NumericType_L> , \
        Op ,\
        quan ::detail::united_value<ConversionFactor_R , NumericType_R> \
    >{ \
        typedef quan ::detail::united_value<\
            typename binary_op<\
                ConversionFactor_L ,\
                Op ,\
                ConversionFactor_R \
            >::type , \
            typename binary_op< \
                NumericType_L , \
                Op , \
                NumericType_R \
            >::type \
        > type; \
    };

    QUAN_UNITED_VALUE_BINOP(plus)
    QUAN_UNITED_VALUE_BINOP(minus)

#undef QUAN_UNITED_VALUE_BINOP

    template<
        typename ConversionFactor, 
        typename NumericType, 
        typename PowType
    >
    struct binary_op_impl<
        quan ::detail::united_value<ConversionFactor,NumericType>,
        pow,
        PowType 
    >{
        typedef quan ::detail::united_value<
            typename binary_op<
                ConversionFactor,
                pow,
                PowType
            >::type,
            typename binary_op<
                NumericType,
                quan ::meta::pow,
                PowType
            >::type
        > type;
    };
        
   } // impl 
} }//quan::meta

namespace quan{ namespace detail{

    template <
        typename ConversionFactor, 
        typename NumericType
    >
    class united_value{
    public:
        typedef ConversionFactor conversion_factor;
        typedef NumericType value_type;

        inline
        QUAN_CONSTEXPR
        explicit united_value(value_type const & in) ;
      
        template<typename Value_typeIn>
        inline 
         QUAN_CONSTEXPR
         explicit united_value(Value_typeIn const & in) ;
      //  inline united_value(united_value const & in);
        template <typename UnitsIn, typename Value_typeIn>
        QUAN_CONSTEXPR
        inline united_value(united_value<UnitsIn,Value_typeIn> const & in);

#define QUAN_UNITED_VALUE_ASSIGNMENT_OP(Op)\
        inline united_value & operator Op (united_value const & in);\
        template <typename UnitsIn, typename NumericTypeIn>\
        inline united_value & operator Op (\
            united_value<UnitsIn,NumericTypeIn> const & in\
        );
       // QUAN_UNITED_VALUE_ASSIGNMENT_OP(=)
        template <typename UnitsIn, typename NumericTypeIn>
        inline united_value & operator = (
            united_value<UnitsIn,NumericTypeIn> const & in
        );
        QUAN_UNITED_VALUE_ASSIGNMENT_OP(+=)
        QUAN_UNITED_VALUE_ASSIGNMENT_OP(-=)

        template <typename Arithmetic>
        typename quan::where_<
           quan ::meta::is_numeric<Arithmetic>,
            united_value &
        >::type
        operator *= ( Arithmetic const & in){
            this->m_value *= in;
            return *this;
        }
        template <typename Arithmetic>
        typename quan::where_<
            quan ::meta::is_numeric<Arithmetic>,
            united_value &
        >::type
        operator /= ( Arithmetic const & in){
            this->m_value /= in;
            return *this;
        }

#undef QUAN_UNITED_VALUE_ASSIGNMENT_OP

        QUAN_CONSTEXPR
        typename std::remove_const<value_type>::type 
        raw_value() const {return m_value;} 
        value_type & raw_value_ref()
        {
           return  m_value;
        }
        QUAN_CONSTEXPR
        value_type const & raw_value_ref()const
        {
           return  m_value;
        }
    private:
        value_type m_value; 
    };

///////////////united_value definitions/////////////////


// value ctor where in.type == NumericType
    template <
        typename ConversionFactor, 
        typename NumericType
    >
    inline
    QUAN_CONSTEXPR   
    united_value<ConversionFactor,NumericType>::united_value(
        NumericType const& in 
    ) 
    : m_value(in)
    {}
    // value ctor where in.type implicit convertible to NumericType
    template <
        typename ConversionFactor, 
        typename NumericType
    >
    template<
        typename NumericTypeIn
    >
    inline
QUAN_CONSTEXPR
    united_value<ConversionFactor,NumericType>::united_value(
        NumericTypeIn const & in
    ) : m_value (
			typename quantity_traits:: template value_type_converter<
            NumericType, NumericTypeIn
        >()(in)
		){}

// copy ctor where in has different value_type and units
    template <
        typename ConversionFactor,
        typename NumericType
    >
    template <
        typename UnitsIn,
        typename NumericTypeIn
    >
    inline  
    QUAN_CONSTEXPR
    united_value<ConversionFactor,NumericType>::united_value(
        united_value<UnitsIn,NumericTypeIn> const & in
    )
    : m_value(detail::united_value_cast<united_value>(in))
    {}

#define QUAN_UNITED_VALUE_ASSIGNMENT_OP(Op) \
    template <typename ConversionFactor,typename NumericType>\
    inline united_value<ConversionFactor, NumericType> & \
    united_value<ConversionFactor, NumericType>::operator Op (united_value const & in)\
    { this->m_value Op in.m_value; return *this;}\
    \
    template <typename ConversionFactor,typename NumericType>\
    template <typename UnitsIn,typename NumericTypeIn>\
    inline united_value<ConversionFactor,NumericType>&\
    united_value<ConversionFactor, NumericType>:: operator Op (\
        united_value<UnitsIn,NumericTypeIn> const & in\
    ) \
    { \
        this->m_value Op united_value{in}.m_value; \
        return *this; \
    }

    template <typename ConversionFactor,typename NumericType>
    template <typename UnitsIn,typename NumericTypeIn>
    inline united_value<ConversionFactor,NumericType>&\
    united_value<ConversionFactor, NumericType>:: operator = (
        united_value<UnitsIn,NumericTypeIn> const & in
    ) 
    { 
        this->m_value = united_value{in}.m_value; 
        return *this; 
    }

QUAN_UNITED_VALUE_ASSIGNMENT_OP(+=)
QUAN_UNITED_VALUE_ASSIGNMENT_OP(-=)

#undef QUAN_UNITED_VALUE_ASSIGNMENT_OP

    template < 
        typename ConversionFactor_L , 
        typename NumericType_L , 
        typename ConversionFactor_R , 
        typename NumericType_R 
    > 
QUAN_CONSTEXPR
    typename quan ::meta::binary_op< 
        united_value<ConversionFactor_L , NumericType_L> , 
        quan ::meta::plus , 
        united_value<ConversionFactor_R , NumericType_R> 
    >::type 
    operator  + ( 
        united_value<ConversionFactor_L , NumericType_L> const & lhs 
        , 
        united_value<ConversionFactor_R , NumericType_R> const & rhs ) 
    {   

       typedef typename quan ::meta::binary_op< 
        united_value<ConversionFactor_L , NumericType_L> , 
        quan ::meta::plus , 
        united_value<ConversionFactor_R , NumericType_R> 
        >::type result_type;

       return result_type{ result_type{lhs}.numeric_value() + result_type{rhs}.numeric_value()};

    }

    template < 
        typename ConversionFactor_L , 
        typename NumericType_L , 
        typename ConversionFactor_R , 
        typename NumericType_R 
    > 
   QUAN_CONSTEXPR
    typename quan ::meta::binary_op< 
        united_value<ConversionFactor_L , NumericType_L> , 
        quan ::meta::minus , 
        united_value<ConversionFactor_R , NumericType_R> 
    >::type 
    operator  - ( 
        united_value<ConversionFactor_L , NumericType_L> const & lhs, 
        united_value<ConversionFactor_R , NumericType_R> const & rhs ) 
    {   

      typedef typename quan ::meta::binary_op< 
         united_value<ConversionFactor_L , NumericType_L> , 
         quan ::meta::plus , 
         united_value<ConversionFactor_R , NumericType_R> 
      >::type result_type;

       return result_type{ result_type{lhs}.numeric_value() - result_type{rhs}.numeric_value() };
    }

} }//quan::detail

#endif
