#ifndef QUAN_FUSION_PARTIAL_BINARY_HPP_INCLUDED
#define QUAN_FUSION_PARTIAL_BINARY_HPP_INCLUDED

// Copyright Andrew Little 2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)

namespace quan{ namespace fusion{

    // val op ?
    template <typename Function, typename Left>
    struct partial_binary_left{
        partial_binary_left(Left const & left,Function const & func = Function())
        :m_left(left),m_function(func){}
        Left   m_left;
        Function  m_function;
        
        template <typename Right>
        struct result {
            typedef typename Function::template result<Left,Right>::type type;
        };

        template <typename Right>
        typename result<Right>::type
        operator()(Right const & right)const
        {
            return m_function(m_left,right);
        }
    private:
        partial_binary_left & operator = (partial_binary_left const & in);/*
        {
            ~this; this = new(this)(partial_binary_left(in));
        }*/
    };


    template <typename Function, typename Left>
    struct partial_void_binary_left{
        partial_void_binary_left(Left const & left,Function const & f = Function())
        :m_function(f),m_left(left){}
        Function  m_function;
        Left   m_left;

        template <typename Right>
        struct result {
            typedef typename Function::template result<Left,Right>::type type;
        };

        template <typename Right>
        typename result<Right>::type
        operator()(Right const & right)const
        {
            m_function(m_left,right);
        }
    };

      // ? op val
    template <typename Function, typename Right>
    struct partial_void_binary_right{
        partial_void_binary_right(Right const & right,Function const & f = Function())
        :m_function(f),m_right(right){}
        Function  m_function;
        Right  m_right;

        template <typename Left>
        struct result {
            typedef typename Function::template result<Left,Right>::type type;
        };

        template <typename Left>
        typename result<Left>::type
        operator()(Left const & left)const
        {
             m_function(left,m_right);
        }
    };

    template <typename Function, typename Right>
    struct partial_binary_right{
        partial_binary_right(Right const & right,Function const & f = Function())
        :m_right(right),m_function(f){}
       
        Right  m_right;
        Function  m_function;

        template <typename Left>
        struct result {
            typedef typename Function::template result<Left,Right>::type type;
        };

        template <typename Left>
        typename result<Left>::type
        operator()(Left const & left)const
        {
             return m_function(left,m_right);
        }
    };

}}//quan::fusion

#endif
