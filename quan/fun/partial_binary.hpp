#ifndef QUAN_FUSION_PARTIAL_BINARY_HPP_INCLUDED
#define QUAN_FUSION_PARTIAL_BINARY_HPP_INCLUDED

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

namespace quan{ namespace fun{

    struct _;
   
    template <typename TL, typename Op, typename Rhs>
    struct binary_op;

    template <typename Lhs,typename Function>
    struct binary_op<Lhs,Function,_>{

        binary_op(Lhs const & left,Function const & func = Function())
        :m_left(left),m_function(func){}
        Lhs const &  m_left;
        Function  m_function;
        
        template <typename Rhs>
        struct result {
            typedef typename Function::template result<Lhs,Rhs>::type type;
        };

        template <typename Rhs>
        typename result<Rhs>::type
        operator()(Rhs const & right)const
        {
            return m_function(m_left,right);
        }

        template <typename Rhs>
        typename result<Rhs>::type
        operator()(Rhs & right)const
        {
            return m_function(m_left,right);
        }
    };

    template <typename Function, typename Rhs>
    struct binary_op<_,Function,Rhs>{
        binary_op(Rhs const & right,Function const & f = Function())
        :m_right(right),m_function(f){}
       
        Rhs const &  m_right;
        Function  m_function;

        template <typename Lhs>
        struct result {
            typedef typename Function::template result<Lhs,Rhs>::type type;
        };
        
        template <typename Lhs>
        typename result<Lhs>::type
        operator()(Lhs const & left)const
        {
             return m_function(left,m_right);
        }

        template <typename Lhs>
        typename result<Lhs>::type
        operator()(Lhs  & left )const
        {
             return m_function(left,m_right);
        }
    };

}}//quan::fun

#endif
