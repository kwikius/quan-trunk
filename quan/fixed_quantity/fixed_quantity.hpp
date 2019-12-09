#ifndef QUAN_FIXED_QUANTITY_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_HPP_INCLUDED

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
    fixed_quantity class template definition
*/
#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity_fwd.hpp>
#include <quan/meta/is_lossless_calculation.hpp>
#include <quan/archetypes/meta/static_unit_concept.hpp>
#include <quan/detail/united_value/united_value.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/unit.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/eq.hpp>
#include <quan/where.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/is_scalar.hpp>
#include <quan/meta/is_fixed_quantity.hpp>
#include <quan/meta/is_valid_binary_op.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_convertible.hpp>
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan {

    template<
        typename StaticUnit,
        typename NumericType
    >
    class fixed_quantity {

        template <
            typename StaticUnit_In, 
            typename NumericType_In
        >
        friend class fixed_quantity;

    public:
        typedef StaticUnit unit;
        typedef NumericType value_type;

    private:
        typedef detail::united_value<
            typename meta::get_conversion_factor<
                unit
            >::type,
            value_type
        > united_value;

        united_value m_united_value;
    

        QUAN_CONSTEXPR
        united_value
        get_united_value()const
        {
             return this->m_united_value;  
        }
    
        // maybe add a check for a const value_type
        template <typename NumericType_In>
        struct is_compatible_value_type : meta::and_<
             std::is_convertible<
                NumericType_In,
                value_type
            >,
            quan::meta::is_numeric<NumericType_In>
        >{};

        template <
            typename StaticUnit_In,
            typename NumericType_In
        >
        struct m_is_unit_convertible : meta::and_<
            meta::dimensionally_equivalent<
                StaticUnit_In,
                unit
            >,
            is_compatible_value_type<
                NumericType_In
            >
        >{};

        template <
            typename StaticUnit_In,
            typename NumericType_In
        >
        struct m_is_convertible : meta::and_<
            meta::dimensionally_equivalent<
                StaticUnit_In,
                unit
            >,
            meta::and_<
               meta::or_<
                  meta::allow_implicit_unit_conversions<
                     StaticUnit
                  >,
                  meta::is_math_same_conversion_factor<
                     typename meta::get_conversion_factor<
                           StaticUnit
                     >::type,
                     typename meta::get_conversion_factor<
                           StaticUnit_In
                     >::type
                  >   
               >,
               is_compatible_value_type<
                  NumericType_In
               >
            >
        >{};

    public:

        // A dimensionless type is replaced by
        // its value_type;
        typedef typename meta::if_<
            quan ::meta::is_dimensionless<
                unit
            >,
            value_type,
            fixed_quantity
        >::type type;


       QUAN_CONSTEXPR
       fixed_quantity() :  m_united_value(static_cast<NumericType>(0)){}

        // value initialisation ctor
        template<typename NumericType_In>
        explicit 
        QUAN_CONSTEXPR fixed_quantity(
            NumericType_In const& value_in,
             typename quan::where_<
                is_compatible_value_type<NumericType_In>,
                void*
             >::type = 0

        ) : m_united_value(value_in){}

        template< 
            typename StaticUnit_In,
            typename NumericType_In
        >
        QUAN_CONSTEXPR
        fixed_quantity( 
            fixed_quantity<
                StaticUnit_In,
                NumericType_In
            > const & in,
            typename quan::where_< 
                m_is_convertible<
                    StaticUnit_In,NumericType_In
                >,
                void*
            >::type = 0
        ) : m_united_value(in.m_united_value){}

        template< 
            typename StaticUnit_In,
            typename NumericType_In
        >
        QUAN_CONSTEXPR
        explicit fixed_quantity( 
            fixed_quantity<
                StaticUnit_In,
                NumericType_In
            > const & in,
            typename quan::where_< 
                meta::and_<
                    m_is_unit_convertible<
                        StaticUnit_In,NumericType_In
                    >,
                    meta::not_<
                        m_is_convertible<
                            StaticUnit_In,NumericType_In
                        >
                    >
                >,
                void*
            >::type = 0
        ) : m_united_value(in.m_united_value){}

        // assignment 

        template< 
            typename StaticUnit_In,
            typename NumericType_In
        >
        typename quan::where_<
            m_is_convertible<
                StaticUnit_In,NumericType_In
            >,
            fixed_quantity& 
        >::type 
        operator = (
            fixed_quantity<
                StaticUnit_In,
                NumericType_In
            > const  & in
        )
        {
            this->m_united_value = in.m_united_value;
            return *this;
        }

        template< 
            typename StaticUnit_In,
            typename NumericType_In
        >
        typename quan::where_<
            m_is_convertible<
                StaticUnit_In,NumericType_In
            >,
            fixed_quantity& 
        >::type 
        operator += (
            fixed_quantity<
                StaticUnit_In,
                NumericType_In
            > const  & in
        )
        {
            this->m_united_value += in.m_united_value;
            return *this;
        }

        template< 
            typename StaticUnit_In,
            typename NumericType_In
        >
        typename quan::where_<
            m_is_convertible<
                StaticUnit_In,NumericType_In
            >,
            fixed_quantity& 
        >::type 
        operator -= (
            fixed_quantity<
                StaticUnit_In,
                NumericType_In
            > const  & in
        )
        {
            this->m_united_value -= in.m_united_value;
            return *this;
        }

        template <typename NumericType_In>
        typename quan::where_<
           /* is_compatible_value_type<
                NumericType_In
            >,*/
            std::is_convertible<
               typename quan::meta::binary_op<
                  value_type, quan::meta::times,NumericType_In
               >::type,
               value_type
            >,
           /* >
            quan::meta::and_<
               quan::meta::is_valid_binary_op<
                  value_type, quan::meta::times,NumericType_In
               >,*/
            fixed_quantity&
        >::type
        operator *= (NumericType_In const & in)
        {
            this->m_united_value *= in;
            return *this;
        }

        template <typename NumericType_In>
        typename quan::where_<
            /*is_compatible_value_type<
                NumericType_In
            >,*/
            std::is_convertible<
               typename quan::meta::binary_op<
                  value_type, quan::meta::divides,NumericType_In
               >::type,
               value_type
            >,
            fixed_quantity&
        >::type
        operator /= (NumericType_In const & in)
        {
            this->m_united_value /= in;
            return *this;
        }

QUAN_CONSTEXPR
        fixed_quantity
        operator +()const
        {
            return  *this;
        }
QUAN_CONSTEXPR
        fixed_quantity
        operator -()const
        { 
            return fixed_quantity ( - this->m_united_value.raw_value()); 
        }
QUAN_CONSTEXPR
        bool operator!()const
        {
            return this->m_united_value.raw_value() == 0;
        }

        fixed_quantity& operator++()
        {
            ++ this->m_united_value.raw_value_ref();
            return *this;
        }

        fixed_quantity operator++(int)
        {
            fixed_quantity result = *this;
            ++ this->m_united_value.raw_value_ref();
            return result;
        }

        fixed_quantity& operator--()
        {
            --this->m_united_value.raw_value_ref();
            return *this;
        }

        fixed_quantity  operator--(int)
        {
            fixed_quantity result = *this;
            --this->m_united_value.raw_value_ref();
            return result;
        }
        QUAN_CONSTEXPR
        typename std::remove_const<
            NumericType
        >::type 
        numeric_value()const
        {
            return this->m_united_value.raw_value();        
        }

        template <typename Quantity>
        typename quan::where_<
            std::is_same<Quantity,fixed_quantity>,
            void
        >::type
        set_numeric_value(NumericType const & v)
        {
            this->m_united_value.raw_value_ref() = v;
        }

        template <typename Quantity>

        typename quan::where_<
            std::is_same<Quantity,fixed_quantity>,
            NumericType&
        >::type
        reference_numeric_value()
        {
            return this->m_united_value.raw_value_ref() ;
        }

        template <typename Quantity>
        QUAN_CONSTEXPR
        typename quan::where_<
            std::is_same<Quantity,fixed_quantity>,
            NumericType const &
        >::type
        reference_numeric_value()const
        {
            return this->m_united_value.raw_value_ref() ;
        }

        template <typename Quantity>
        QUAN_CONSTEXPR
        typename quan::where_<
            std::is_same<Quantity,fixed_quantity>,
            NumericType const &
        >::type
        const_reference_numeric_value()const
        {
            return this->m_united_value.raw_value_ref() ;
        }


        static
        QUAN_CONSTEXPR
        default_fixed_quantity_unit<unit>
        get_unit()
        {
            return default_fixed_quantity_unit<unit>();
        }             
    }; // fixed_quantity

} // quan

namespace quan { namespace meta {

    template<
        typename StaticUnit,
        typename NumericType
    > struct unary_operation<
        reciprocal,
        quan::fixed_quantity<
            StaticUnit,
            NumericType
        >
    >{
        typedef fixed_quantity<
            typename unary_operation<
                reciprocal,
                StaticUnit
            >::type,
            typename unary_operation<
                reciprocal,
                NumericType
            >::type
        > type;
    };

    template <
        typename StaticUnit_L,
        typename NumericType_L,
        typename StaticUnit_R,
        typename NumericType_R
    > struct dimensionally_equivalent<
        quan ::fixed_quantity<
            StaticUnit_L,
            NumericType_L
        >,
        quan ::fixed_quantity<
            StaticUnit_R,
            NumericType_R
        >
    > : dimensionally_equivalent<
        StaticUnit_L,StaticUnit_R
    >{};

    namespace impl{
       template <
           typename StaticUnit,
           typename NumericType
       >
       struct is_scalar_impl<
         quan ::fixed_quantity<
               StaticUnit,
               NumericType
           >
       > : std::true_type{};
    }//impl

    template <
        typename StaticUnit,
        typename NumericType
    >
    struct is_named_quantity<
        quan ::fixed_quantity<
            StaticUnit,
            NumericType
        >
    > : is_named_quantity<StaticUnit>{};

    template <
        typename StaticUnitL,
        typename NumericTypeL,
        typename StaticUnitR,
        typename NumericTypeR
    >
    struct is_same_quantity<
        quan ::fixed_quantity<
            StaticUnitL,
            NumericTypeL
        >,
        quan ::fixed_quantity<
            StaticUnitR,
            NumericTypeR
        >
    > : is_same_quantity<
            StaticUnitL,
            StaticUnitR
    >{};
    
    template <
        typename StaticUnit,
        typename NumericType
    >
    struct get_nearest_si<
        quan::fixed_quantity<
            StaticUnit,
            NumericType
        >
    > {
        typedef typename quan::fixed_quantity<
            typename get_nearest_si<StaticUnit>::type,
            NumericType
        >::type type;
    };

   
    template <
        typename StaticUnit,
        typename NumericType
    >
    struct make_anonymous<
        fixed_quantity<
            StaticUnit,
            NumericType
        >
    >{
        typedef fixed_quantity<
            typename make_anonymous<StaticUnit>::type,
            NumericType
        > type;
    };

    template <
        typename StaticUnitL, typename NumericTypeL,
        typename Op,
        typename StaticUnitR, typename NumericTypeR
    > struct is_lossless_calculation<
        quan::fixed_quantity<StaticUnitL,NumericTypeL>,
        Op,
        quan::fixed_quantity<StaticUnitR,NumericTypeR> ,
        typename quan::where_<
            quan::meta::or_<
               quan::meta::is_additive_operator<Op>,
               quan::meta::is_equality_operator<Op>,
               quan::meta::is_relational_operator<Op>
            >
        >::type
    > : is_math_same_conversion_factor<
           typename get_conversion_factor<StaticUnitL>::type,
           typename get_conversion_factor<StaticUnitR>::type 
     >{};
    
    //// multiply conditions dimensionfull dimensionless
    namespace detail{

        template <typename StaticUnitL, typename StaticUnitR>
        struct is_lossless_dimensioned_mux{
            typedef typename quan::meta::get_conversion_factor<StaticUnitL>::type convL;
            typedef typename quan::meta::get_conversion_factor<StaticUnitR>::type convR;
            typedef typename quan::meta::get_multiplier<convL>::type muxL;
            typedef typename quan::meta::get_multiplier<convR>::type muxR;
            typedef typename quan::meta::binary_op<
                muxL, quan::meta::times,muxR
            >::type result_mux;
            typedef typename quan::meta::eq_one<result_mux>::type type;
            static constexpr bool value = type::value;
        };

        template <typename StaticUnitL, typename StaticUnitR>
        struct is_lossless_dimensionless_mux{
            typedef typename quan::meta::get_conversion_factor<StaticUnitL>::type convL;
            typedef typename quan::meta::get_conversion_factor<StaticUnitR>::type convR;
            typedef typename quan::meta::get_multiplier<convL>::type muxL;
            typedef typename quan::meta::get_multiplier<convR>::type muxR;
            typedef typename quan::meta::binary_op<
                muxL, quan::meta::times,muxR
            >::type result_mux;
            typedef typename quan::meta::get_exponent<convL>::type expL;
            typedef typename quan::meta::get_exponent<convR>::type expR;
            typedef typename quan::meta::binary_op<
                expL, quan::meta::plus,expR
            >::type result_exp;
            typedef typename quan::meta::and_<
                  quan::meta::eq_one<result_mux>,
                  quan::meta::eq_zero<result_exp>
            >::type type;
            static constexpr bool value = type::value;
        };

        template <typename StaticUnitL,typename StaticUnitR>
        struct is_lossless_mux : quan::meta::eval_if<
            quan::meta::is_dimensionless<
                typename quan::meta::binary_op<
                    StaticUnitL, quan::meta::times, StaticUnitR
                >::type
            >,
            is_lossless_dimensionless_mux<StaticUnitL,StaticUnitR>,
            is_lossless_dimensioned_mux<StaticUnitL,StaticUnitR>
        >{};

    }//detail
        
    template <
        typename StaticUnitL, typename NumericTypeL,
        typename StaticUnitR, typename NumericTypeR
    > struct is_lossless_calculation<
        quan::fixed_quantity<StaticUnitL,NumericTypeL>,
        quan::meta::times,
        quan::fixed_quantity<StaticUnitR,NumericTypeR> 
     > : detail::is_lossless_mux<StaticUnitL,StaticUnitR>{};

    template <
        typename StaticUnit, typename NumericType,
        typename NumericTypeR
    > struct is_lossless_calculation<
        quan::fixed_quantity<StaticUnit,NumericType>,
        quan::meta::times,
        NumericTypeR,
        typename quan::where_<
            quan::meta::is_numeric<NumericTypeR>
        >::type 
    > : std::true_type{};

    template <
        typename NumericTypeL,
        typename StaticUnit, typename NumericType
    > struct is_lossless_calculation<
        NumericTypeL,
        quan::meta::times,
        quan::fixed_quantity<StaticUnit,NumericType>,
        typename quan::where_<
            quan::meta::is_numeric<NumericTypeL>
        >::type 
    > : std::true_type{};
 
    template<
        typename StaticUnit, typename NumericType,
        typename NumericTypeR
    > struct is_lossless_calculation<
        quan::fixed_quantity<StaticUnit,NumericType>,
        quan::meta::divides,
        NumericTypeR,
        typename quan::where_<
            quan::meta::is_numeric<NumericTypeR>
        >::type 
    > : std::true_type{};

    namespace detail{

        template <typename StaticUnit>
        struct is_lossless_divide_into_numeric{
            typedef typename quan::meta::get_conversion_factor<
                StaticUnit
            >::type conv_factor;
            typedef typename quan::meta::get_multiplier<conv_factor>::type mux;
            typedef typename quan::meta::eq_one<mux>::type type;
            static constexpr bool value = type::value;
        };
    }

    template <
        typename NumericTypeL,
        typename StaticUnit, typename NumericType
    > struct is_lossless_calculation<
        NumericTypeL,
        quan::meta::divides,
        quan::fixed_quantity<StaticUnit,NumericType>,
        typename quan::where_<
            quan::meta::is_numeric<NumericTypeL>
        >::type 
    > : detail::is_lossless_divide_into_numeric<StaticUnit>{};

    namespace detail{

        template <typename StaticUnitL, typename StaticUnitR>
        struct is_lossless_dimensioned_divide{
            typedef typename quan::meta::get_conversion_factor<StaticUnitL>::type convL;
            typedef typename quan::meta::get_conversion_factor<StaticUnitR>::type convR;
            typedef typename quan::meta::get_multiplier<convL>::type muxL;
            typedef typename quan::meta::get_multiplier<convR>::type muxR;
            typedef typename quan::meta::binary_op<
                muxL, quan::meta::divides,muxR
            >::type result_mux;
            typedef typename quan::meta::eq_one<result_mux>::type type; 
            static constexpr bool value = type::value;    
        };

        template <typename StaticUnitL, typename StaticUnitR>
        struct is_lossless_dimensionless_divide{
            typedef typename quan::meta::get_conversion_factor<StaticUnitL>::type convL;
            typedef typename quan::meta::get_conversion_factor<StaticUnitR>::type convR;
            typedef typename quan::meta::get_multiplier<convL>::type muxL;
            typedef typename quan::meta::get_multiplier<convR>::type muxR;
            typedef typename quan::meta::binary_op<
                muxL, quan::meta::divides,muxR
            >::type result_mux;

            typedef typename quan::meta::get_exponent<convL>::type expL;
            typedef typename quan::meta::get_exponent<convR>::type expR;
            typedef typename quan::meta::binary_op<
                expL, quan::meta::minus,expR
            >::type result_exp;
            typedef typename quan::meta::and_<
                quan::meta::eq_one<result_mux>,
                quan::meta::eq_zero<result_exp>
            >::type type;
           static constexpr bool value = type::value;
        };

        template <typename StaticUnitL,typename StaticUnitR>
        struct is_lossless_divide : quan::meta::eval_if<
            quan::meta::is_dimensionless<
                typename quan::meta::binary_op<
                    StaticUnitL, quan::meta::divides, StaticUnitR
                >::type
            >,
            is_lossless_dimensionless_divide<StaticUnitL,StaticUnitR>,
            is_lossless_dimensioned_divide<StaticUnitL,StaticUnitR>
        >{};

    }//detail

     template <
        typename StaticUnitL, typename NumericTypeL,
        typename StaticUnitR, typename NumericTypeR
    > struct is_lossless_calculation<
        quan::fixed_quantity<StaticUnitL,NumericTypeL>,
        quan::meta::divides,
        quan::fixed_quantity<StaticUnitR,NumericTypeR> 
     > : quan::meta::detail::is_lossless_divide<StaticUnitL,StaticUnitR>{};
    
} } // quan::meta

#endif
