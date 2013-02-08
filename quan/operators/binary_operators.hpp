#ifndef QUAN_GENERIC_BINARY_OPERATORS_HPP_INCLUDED
#define QUAN_GENERIC_BINARY_OPERATORS_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Also see preferred functors available for use in Boost.Fusion etc.
    eg quan::operator_<quan::meta::plus>()(a,b)
    quan::operator_plus()(a,b) etc

    useage 
    binary_operator<LHS,quan::meta::plus,RHS>::type t 
    = binary_operator<LHS,quan::meta::plus,RHS>()(lhs,rhs)

    see <quan/meta/binary_operator_extra_keys.hpp>
    for list of all.
    Note incomplete. Add functions aas required
*/

#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>
#include <type_traits>

namespace quan{
       
    template <
        typename A, 
        typename Op,
        typename B
    >
    struct binary_operator;

    namespace meta{
        template <typename T>
        struct as_const_argument{
            typedef  T const & type;  
        };
    }

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a = b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::modulus_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::modulus_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a %= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::shift_left_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::shift_left_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a <<= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::shift_right_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::shift_right_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a >>= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::or_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::or_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a |= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::and_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::and_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a &= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::xor_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::xor_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a ^= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::plus_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::plus_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a += b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::minus_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::minus_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a -= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::times_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::times_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a *= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::divide_equals,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::divide_equals,B
        >::type result_type;
        static_assert(quan::meta::not_<std::is_const<A> >::value,"error");
        typedef typename std::add_lvalue_reference<A>::type first_arg_type;
        result_type operator() (
            first_arg_type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a /= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::logical_or,B> 
    {
        typedef typename meta::binary_op<
            A,quan::meta::logical_or,B
        >::type result_type;
        result_type operator() (
            typename meta::as_const_argument<A>::type a,
            typename meta::as_const_argument<B>::type b
        )const
        {return a || b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::logical_and,B>{
        typedef typename meta::binary_op<
            A,quan::meta::logical_and,B
        >::type result_type;
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a && b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::bit_or,B>{
        typedef typename meta::binary_op<
            A,quan::meta::bit_or,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a | b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::bit_xor,B>{
        typedef typename meta::binary_op<
            A,quan::meta::bit_xor,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a ^ b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::bit_and,B>{
        typedef typename meta::binary_op<
            A,quan::meta::bit_and,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a & b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::equal_to,B>{
        typedef typename meta::binary_op<
            A,quan::meta::equal_to,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a == b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::not_equal_to,B>{
        typedef typename meta::binary_op<
            A,quan::meta::not_equal_to,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a != b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::greater_equal,B>{
        typedef typename meta::binary_op<
            A,quan::meta::greater_equal,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a >= b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::less_equal,B>{
        typedef typename meta::binary_op<
            A,quan::meta::less_equal,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a <= b;}
    };

   template <typename A, typename B>
    struct binary_operator<A,quan::meta::greater,B>{
        typedef typename meta::binary_op<
            A,quan::meta::greater,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a > b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::less,B>{
        typedef typename meta::binary_op<
            A,quan::meta::less,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a < b;}
    };
    
template <typename A, typename B>
    struct binary_operator<A,quan::meta::shift_right,B>{
        typedef typename meta::binary_op<
            A,quan::meta::shift_right,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a >> b;}
    };

  template <typename A, typename B>
    struct binary_operator<A,quan::meta::shift_left,B>{
        typedef typename meta::binary_op<
            A,quan::meta::shift_left,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a << b;}
        
    };

   // add shleq , and shright etc plus eq muleq

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::plus,B>{
        typedef typename meta::binary_op<
            A,quan::meta::plus,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a + b;}
    };

    
   template <typename A, typename B>
    struct binary_operator<A,quan::meta::minus,B>{
        typedef typename meta::binary_op<
            A,quan::meta::minus,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a - b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::times,B>{
        typedef typename meta::binary_op<
            A,quan::meta::times,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a * b;}
    };

    template <typename A, typename B>
    struct binary_operator<A,quan::meta::divides,B>{
        typedef typename meta::binary_op<
            A,quan::meta::divides,B
        >::type result_type;       
        result_type operator() (
                typename meta::as_const_argument<A>::type a,
                typename meta::as_const_argument<B>::type b)const
                {return a / b;}
    };
    
}//pqs

#endif

