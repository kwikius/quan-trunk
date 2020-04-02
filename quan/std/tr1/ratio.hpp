#ifndef QUAN_STD_TR1_RATIO_HPP_INCLUDED
#define QUAN_STD_TR1_RATIO_HPP_INCLUDED

#include <quan/config.hpp>

#if ! defined QUAN_USE_QUAN_STD_TR1
#include <ratio>
#else

#include <quan/meta/rational.hpp>

namespace std{

   template <intmax_t N, intmax_t D = 1>
   struct ratio {
      typedef typename quan::meta::rational<N,D>::type base_rational_type;
      static constexpr intmax_t num = base_rational_type::numerator;
      static constexpr intmax_t den = base_rational_type::denominator;
      typedef std::ratio<num,den> type;
   };

  namespace quan_detail{
        // for tr1 std ratio
        template <typename LhsRatio,typename Op,typename RhsRatio>
        struct binary_op  {
            typedef typename quan::meta::binary_op<
                quan::meta::rational<LhsRatio::num, LhsRatio::den>,
                Op,
                quan::meta::rational<RhsRatio::num, RhsRatio::den>
            >::type base_rational_type;
            typedef std::ratio<
               base_rational_type::numerator, base_rational_type::denominator
            > type;
        };

       template <typename LhsRatio,typename CompOp,typename RhsRatio>
        struct comp_op {
            typedef typename quan::meta::binary_op<
                quan::meta::rational<LhsRatio::num, LhsRatio::den>,
                CompOp,
                quan::meta::rational<RhsRatio::num, RhsRatio::den>
            >::type type;
           static constexpr bool value = type::value;
       };
   }

   template <typename Lhs, typename Rhs>
   struct ratio_add : std::quan_detail::binary_op<Lhs, quan::meta::plus,Rhs>{};

   template <typename Lhs, typename Rhs>
   struct ratio_subtract : std::quan_detail::binary_op<Lhs, quan::meta::minus,Rhs>{};

   template <typename Lhs, typename Rhs>
   struct ratio_multiply : std::quan_detail::binary_op<Lhs, quan::meta::times,Rhs>{};

   template <typename Lhs, typename Rhs>
   struct ratio_divide : std::quan_detail::binary_op<Lhs, quan::meta::divides,Rhs>{};

   // bool ops
    template <class Lhs, class Rhs> 
    struct ratio_equal : std::quan_detail::comp_op<Lhs, quan::meta::equal_to,Rhs>{}; 
        
    template <class Lhs, class Rhs> struct 
    ratio_not_equal  : std::quan_detail::comp_op<Lhs, quan::meta::not_equal_to,Rhs>{};
         
    template <class Lhs, class Rhs> 
    struct ratio_less  : std::quan_detail::comp_op<Lhs, quan::meta::less,Rhs>{}; 
    
    template <class Lhs, class Rhs> 
    struct ratio_less_equal : std::quan_detail::comp_op<Lhs, quan::meta::less_equal,Rhs>{};  
        
    template <class Lhs, class Rhs> 
    struct ratio_greater : std::quan_detail::comp_op<Lhs, quan::meta::greater,Rhs>{}; 
        
    template <class Lhs, class Rhs> 
    struct ratio_greater_equal : std::quan_detail::comp_op<Lhs, quan::meta::greater_equal,Rhs>{};

} // std
#endif


#endif // QUAN_STD_TR1_RATIO_HPP_INCLUDED
