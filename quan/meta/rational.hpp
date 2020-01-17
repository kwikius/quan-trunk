#ifndef QUAN_META_RATIONAL_HPP_INCLUDED
#define QUAN_META_RATIONAL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2003-2017 Andy Little.

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
    compile time rational number after Eric Ford
*/

#include <quan/config.hpp>
#include <type_traits>
#include <quan/meta/rational_fwd.hpp>
#include <quan/meta/numerator.hpp>
#include <quan/meta/denominator.hpp>

#include <quan/meta/is_lossless_calculation.hpp>

#include <quan/meta/detail/rational_impl.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_runtime_type.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/bool.hpp>

#include <quan/static_assert.hpp>
#include <quan/meta/int32.hpp>
#include <quan/meta/gt.hpp>
#include <quan/meta/lt.hpp>
#include <quan/meta/gte.hpp>
#include <quan/meta/lte.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/neq.hpp>

namespace quan{namespace meta{

    template<
       int64_t N,
       int64_t D 
    >
    struct rational {
        QUAN_STATIC_ASSERT((D != 0));
  
          static const int64_t numerator 
            = quan::meta::detail::rational_impl<
                N,D
            >::numerator;
          static const int64_t   denominator = detail::rational_impl<
                N,D
            >::denominator;        
        typedef rational<numerator,denominator> type;
    };

    template<
       int64_t N,
       int64_t D 
    > 
    struct numerator<
        rational<N,D>
    > : std::integral_constant<int64_t, rational<N,D>::numerator>{};

    template<
       int64_t N,
       int64_t D 
    > 
    struct denominator<
        rational<N,D>
    > : std::integral_constant<int64_t, rational<N,D>::denominator>{};


    template<
       int64_t N,
       int64_t D 
    > 
    struct is_runtime_type<
        rational<N,D>
    > : std::false_type{};

    template<
        int64_t N,
        int64_t D 
    > struct is_integer<
        rational<N,D>
    > : quan::meta::bool_<(rational<N,D>::denominator == 1)>{};
  
    template<
       int64_t N,
       int64_t D 
    > 
    struct eq_zero<
      rational<N,D>
    > : bool_<(rational<N,D>::numerator ==0)>{};

    template<
       int64_t N,
       int64_t D 
    > 
    struct eq_one<
      rational<N,D>
    > : bool_<((rational<N,D>::numerator ==1) && (rational<N,D>::denominator==1))>{};
   
   template<
       int64_t N,
       int64_t D 
    > 
    struct lt_zero<
      rational<N,D>
    > : bool_<(rational<N,D>::numerator < 0)>{};

   template<
       int64_t N,
       int64_t D 
    > 
    struct gt_zero<
      rational<N,D>
    > : bool_<(rational<N,D>::numerator > 0)>{};

    template<
       int64_t N,
       int64_t D 
    > 
    struct gte_zero<
      rational<N,D>
    > : bool_<(rational<N,D>::numerator >= 0)>{};

    template<
       int64_t N,
       int64_t D 
    > 
    struct lte_zero<
      rational<N,D>
    > : bool_<(rational<N,D>::numerator <= 0)>{};
         
    template<
       int64_t N,
       int64_t D 
    > 
    struct unary_operation<
         negate, 
         rational<N,D> 
    > : rational<-N,D>::type { };

    template<
        int64_t N,
        int64_t D 
    > 
    struct unary_operation<
         reciprocal, 
         rational<N,D>
    > : rational<D,N>::type {}; 


    namespace detail{

        template <int64_t N, typename Rational>
        struct rational_elements_in_range : quan::meta::bool_<
        (
            (-N <= quan::meta::numerator<Rational>::value)
            && (N >= quan::meta::numerator<Rational>::value)
            &&(-N <= quan::meta::denominator<Rational>::value)
            && (N >= quan::meta::denominator<Rational>::value)
        )
        >{};

        template <int64_t N,typename RationalL,typename RationalR >
        struct rational_elements_in_range2 : quan::meta::and_<
            rational_elements_in_range<N,RationalL>,
            rational_elements_in_range<N,RationalR>
        >{};
            
        template <typename RationalL, typename Op, typename RationalR>
        struct is_lossless_rational_calc;
         
// change to actually do calc using 64 bit ints
        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::plus, RationalR>
        : rational_elements_in_range2<32767,RationalL,RationalR>{};

   /* // n1/ d1 + n2/d2  ->  n1 * d2 + n2 * d1 / d1 * d2
     long long nume = RationalL::nume * RationalR::denom;
     long long denom = RationalL::denom * RationalR::denom;
     long long divider = RationalL::denom * RationalR::denom;
     
*/

        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::minus, RationalR>
        : rational_elements_in_range2<32767,RationalL,RationalR>{};

        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::less, RationalR>
        : rational_elements_in_range2<32767,RationalL,RationalR>{};

        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::less_equal, RationalR>
        : rational_elements_in_range2<32767,RationalL,RationalR>{};

        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::greater, RationalR>
        : rational_elements_in_range2<32767,RationalL,RationalR>{};
        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::greater_equal, RationalR>
        : rational_elements_in_range2<32767,RationalL,RationalR>{};


        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::times, RationalR>
        : rational_elements_in_range2<46340,RationalL,RationalR>{};

        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::divides, RationalR>
        : rational_elements_in_range2<46340,RationalL,RationalR>{};

        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::equal_to, RationalR>
        : std::true_type{};

        template <typename RationalL, typename RationalR>
        struct is_lossless_rational_calc<RationalL,quan::meta::not_equal_to, RationalR>
        : std::true_type{};

    }//detail

   template <
        int64_t Nlhs,
        int64_t Dlhs,
        int64_t Nrhs,
        int64_t Drhs
    > struct eq_<
        rational<Nlhs,Dlhs>,
        rational<Nrhs,Drhs>
    > : bool_<
      (( rational<Nlhs,Dlhs>::numerator == rational<Nrhs,Drhs>::numerator)
      && (rational<Nlhs,Dlhs>::denominator == rational<Nrhs,Drhs>::denominator)
      )>{};
      
   template <
        int64_t Nlhs,
        int64_t Dlhs,
        typename Op,
        int64_t Nrhs,
        int64_t Drhs
    > struct is_lossless_calculation<
        rational<Nlhs,Dlhs>,
        Op,
        rational<Nrhs,Drhs>
    > : detail::is_lossless_rational_calc<
        rational<Nlhs,Dlhs>,
        Op,
        rational<Nrhs,Drhs>
    >{};

    namespace impl{

       template <
           int64_t Nlhs,
           int64_t Dlhs,
           int64_t Nrhs,
           int64_t Drhs
       > struct binary_op_impl<
           rational<Nlhs,Dlhs>,
           plus,
           rational<Nrhs,Drhs>
       >{
#if 0
           typedef typename rational<Nlhs,Dlhs>::type lhs;
           typedef typename rational<Nrhs,Drhs>::type rhs;
   #ifndef QUAN_HAS_LONG_LONG
           typedef is_lossless_calculation<lhs,plus,rhs> lossless;
           enum{
               lhsn = lhs::numerator,
               lhsd = lhs::denominator,
               rhsn = rhs::numerator,
               rhsd = rhs::denominator
           };
           //+/- 32767
           typedef typename rational<
               static_cast<int64_t>(lhsn) * rhsd 
                   + static_cast<int64_t>(rhsn) * lhsd, 
               static_cast<int64_t>(lhsd) * rhsd
           >::type type;
   #else

           static const long long lhsn = lhs::numerator;
           static const long long lhsd = lhs::denominator;
           static const long long rhsn = rhs::numerator;
           static const long long rhsd = rhs::denominator;
           static const long long sum1 = lhsn * rhsd;
           static const long long sum2 = rhsn * lhsd;
           static const long long abs_sum1 = sum1<0?-sum1:sum1;
           static const long long abs_sum2 = sum2<0?-sum2:sum2;
           static_assert(abs_sum1 < INT_MAX,"rational value too big");
           static_assert(abs_sum2 < INT_MAX,"rational value too big");
           static const long long nume = sum1 + sum2;
           static const long long abs_nume = nume<0 ? -nume:nume;
           static_assert( abs_nume < INT_MAX,"rational value too big");
           
           static const long long denom = lhsd * rhsd;
           static const long long abs_denom = denom<0?-denom:denom;
           static_assert( abs_denom < INT_MAX,"rational value too big");

            typedef typename rational<
               static_cast<int64_t>(nume),
               static_cast<int64_t>(denom)
           >::type type;

         
  #endif  
#else
// implememnt using std:::ratio
        typedef typename std::ratio_add<std::ratio<Nlhs,Dlhs>,std::ratio<Nrhs,Drhs> >::type std_ratio_type;
        typedef typename rational<
            std_ratio_type::num,
            std_ratio_type::den
        >::type type;
#endif
       };

       
       //+/- 32767
       template <
          int64_t Nlhs,int64_t Dlhs,
          int64_t Nrhs,int64_t Drhs
       > struct binary_op_impl<
           rational<Nlhs,Dlhs>,
           minus,
           rational<Nrhs,Drhs>
       >{
#if 0
           typedef typename rational<Nlhs,Dlhs>::type lhs;
           typedef typename rational<Nrhs,Drhs>::type rhs;
           typedef is_lossless_calculation<lhs,minus,rhs> lossless;

           enum{
               lhsn = lhs::numerator,
               lhsd = lhs::denominator,
               rhsn = rhs::numerator,
               rhsd = rhs::denominator
           };
           
           typedef typename rational<
               static_cast<int64_t>(lhsn) * rhsd 
                   - static_cast<int64_t>(rhsn) * lhsd, 
               static_cast<int64_t>(lhsd) * rhsd
           >::type type;
#else
// implement using std:::ratio
        typedef typename std::ratio_subtract<std::ratio<Nlhs,Dlhs>,std::ratio<Nrhs,Drhs> >::type std_ratio_type;
        typedef typename rational<
            std_ratio_type::num,
            std_ratio_type::den
        >::type type;

#endif
       };
       
       template <
          int64_t Nlhs,int64_t Dlhs,
           int64_t Nrhs, int64_t Drhs
       > struct binary_op_impl<
           rational<Nlhs,Dlhs>,
           times,
           rational<Nrhs,Drhs>
       >{
           typedef typename rational<Nlhs,Dlhs>::type lhs;
           typedef typename rational<Nrhs,Drhs>::type rhs;

           enum{ 
               n = lhs::numerator * rhs::numerator,
               d = lhs::denominator * rhs::denominator
           };
           //+/- 46340
           typedef typename rational<
             n , d
           >::type type;
       };
      
       template <
           int64_t Nlhs,int64_t Dlhs,
           int64_t Nrhs, int64_t Drhs
       > struct binary_op_impl<
           rational<Nlhs,Dlhs>,
           divides,
           rational<Nrhs,Drhs>
       >{
           typedef typename rational<Nlhs,Dlhs>::type lhs;
           typedef typename rational<Nrhs,Drhs>::type rhs;
           typedef is_lossless_calculation<lhs,divides,rhs> lossless;

           enum{
               lhsn = lhs::numerator,
               lhsd = lhs::denominator,
               rhsn = rhs::numerator,
               rhsd = rhs::denominator
           };
           //+- 46340
           typedef typename rational<
               static_cast<int64_t>(lhsn) * rhsd , 
               (static_cast<int64_t>(lhsn) == 0) 
                   ? 1 
                   : static_cast<int64_t>(lhsd) * rhsn
           >::type type;
       };
    } // impl

    #define QUAN_META_RATIONAL_COMPARISON_OP( Operator,OpSymbol)\
    template <\
            int64_t Nlhs ,\
            int64_t Dlhs ,\
            int64_t Nrhs ,\
            int64_t Drhs\
    >\
    struct  Operator <\
        quan::meta::rational<Nlhs , Dlhs > ,\
        quan::meta::rational<Nrhs , Drhs >\
    >{\
        typedef typename quan::meta::rational<Nlhs , Dlhs>::type lhs;\
        typedef typename quan::meta::rational<Nrhs , Drhs>::type rhs;\
        static const long long lhsn = lhs::numerator;\
        static const long long lhsd = lhs::denominator;\
        static const long long rhsn = rhs::numerator;\
        static const long long rhsd = rhs::denominator;\
        static const long long lhsv = lhsn * rhsd ;\
        static const long long rhsv = rhsn * lhsd;\
        static const bool value = lhsv OpSymbol rhsv;\
        typedef bool_<value> type;\
    };

// defining these may be problematic  if large values are used
// could check values are in range

    QUAN_META_RATIONAL_COMPARISON_OP( lt_ , < )
    QUAN_META_RATIONAL_COMPARISON_OP( lte_, <= )
    QUAN_META_RATIONAL_COMPARISON_OP( gte_, >= )
    QUAN_META_RATIONAL_COMPARISON_OP( gt_, > )

    #undef QUAN_META_RATIONAL_COMPARISON_OP
    
    namespace impl {
     template <
        int64_t Nlhs,int64_t Dlhs,
        int64_t Nrhs, int64_t Drhs
    > struct binary_op_impl<
        rational<Nlhs,Dlhs>,
        less,
        rational<Nrhs,Drhs>
    >  : lt_<
         rational<Nlhs,Dlhs>,
         rational<Nrhs,Drhs>
     >{};

     template <
        int64_t Nlhs,int64_t Dlhs,
        int64_t Nrhs, int64_t Drhs
    > struct binary_op_impl<
        rational<Nlhs,Dlhs>,
        less_equal,
        rational<Nrhs,Drhs>
    >  : lte_<
         rational<Nlhs,Dlhs>,
         rational<Nrhs,Drhs>
     >{};

    template <
        int64_t Nlhs,int64_t Dlhs,
        int64_t Nrhs, int64_t Drhs
    > struct binary_op_impl<
        rational<Nlhs,Dlhs>,
        equal_to,
        rational<Nrhs,Drhs>
    >  : eq_<
         rational<Nlhs,Dlhs>,
         rational<Nrhs,Drhs>
     >{};

    template <
        int64_t Nlhs,int64_t Dlhs,
        int64_t Nrhs, int64_t Drhs
    > struct binary_op_impl<
        rational<Nlhs,Dlhs>,
        not_equal_to,
        rational<Nrhs,Drhs>
    > : neq_<
        rational<Nlhs,Dlhs>,
        rational<Nrhs,Drhs>
    >{};

      template <
        int64_t Nlhs,int64_t Dlhs,
        int64_t Nrhs, int64_t Drhs
    > struct binary_op_impl<
        rational<Nlhs,Dlhs>,
        greater_equal,
        rational<Nrhs,Drhs>
    >  : gte_<
         rational<Nlhs,Dlhs>,
         rational<Nrhs,Drhs>
     >{};

     template <
        int64_t Nlhs,int64_t Dlhs,
        int64_t Nrhs, int64_t Drhs
    > struct binary_op_impl<
        rational<Nlhs,Dlhs>,
        greater,
        rational<Nrhs,Drhs>
    >  : gt_<
         rational<Nlhs,Dlhs>,
         rational<Nrhs,Drhs>
     >{};

   } // impl

}}//quan::meta


#endif //PQS_META_RATIONAL_C_HPP_INCLUDED
