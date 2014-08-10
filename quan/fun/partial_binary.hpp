#ifndef QUAN_FUSION_PARTIAL_BINARY_HPP_INCLUDED
#define QUAN_FUSION_PARTIAL_BINARY_HPP_INCLUDED

// Copyright Andrew Little 2006
//
 
 
 


namespace quan{ namespace fun{

    struct _;
   
    template <typename TL, typename Op, typename Rhs>
    struct binary_operation;

    template <typename Lhs,typename Function>
    struct binary_op<Lhs,Function,_>{

        binary_operation(Lhs const & left,Function const & func = Function())
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
        binary_operation(Rhs const & right,Function const & f = Function())
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
