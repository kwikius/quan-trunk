#ifndef QUAN_FUN_INTEGER_RANGE_HPP_INCLUDED
#define QUAN_FUN_INTEGER_RANGE_HPP_INCLUDED

#include <quan/concepts/fusion/sequence.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/asm/abs.hpp>
#include <type_traits>

namespace quan { namespace fun{

   template <int64_t First, int64_t Last, int64_t Stride = 1>
   struct integer_range{static_assert(Stride > 0,"invalid stride");};

   template <int64_t First, int64_t Last,int64_t Stride>
   struct is_fun_sequence_impl<integer_range<First,Last,Stride> > : std::true_type{};
      
    template<int I,int64_t First, int64_t Last,int64_t Stride,  typename Access>
    struct at_seq_impl<I,integer_range<First,Last,Stride> ,Access> {
        static constexpr int64_t istride = I * Stride;
        static constexpr int64_t value = ((First < Last) ? (First + istride) : (First - istride)) ;
        typedef std::integral_constant<int64_t,value> type;

        constexpr type operator() ( integer_range<First,Last,Stride> const & in)const
        { 
           static_assert(Stride > 0,"invalid stride");
           return type{};
        }
    };

    template <int64_t First, int64_t Last, int64_t Stride>
    struct size_seq_impl<integer_range<First,Last,Stride> > : std::integral_constant<std::size_t, (quan::meta::asm_::abs<int64_t,(Last - First)/Stride>::value) +1 >{
        static_assert(Stride > 0,"invalid stride");
    };

}} // quan::fun

#endif // QUAN_FUN_INTEGER_RANGE_HPP_INCLUDED
