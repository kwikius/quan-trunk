#ifndef QUAN_FUN_DETAIL_AT_VECTOR_HPP_INCLUDED
#define QUAN_FUN_DETAIL_AT_VECTOR_HPP_INCLUDED
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

namespace quan{ namespace fun{ namespace detail{

   template <int N, typename Vector, typename F>
   struct at_vector;

    template <typename Vector,typename F>
    struct at_vector<0,Vector,F>{

        typedef typename F::template result<typename Vector::t0>::type type;

        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v0);
        }

        constexpr type operator()(Vector const & vect) const
        {
            //F f;
            return F{}(vect.v0);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<1,Vector,F>{
        
        typedef typename F::template result<typename Vector::t1>::type type;
       
        constexpr type operator()(Vector & vect) const
        {
            //F f;
            return F{}(vect.v1);
        }
        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v1);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<2,Vector,F>{
        
        typedef typename F::template result<typename Vector::t2>::type type;
       
        constexpr type operator()(Vector & vect) const
        {
            //F f;
            return F{}(vect.v2);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v2);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<3,Vector,F>{
        typedef typename F::template result<typename Vector::t3>::type type;

        constexpr type operator()(Vector & vect) const
        {
            //F f;
            return F{}(vect.v3);
        }

        constexpr type operator()(Vector const & vect) const
        {
            //F f;
            return F{}(vect.v3);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<4,Vector, F>{

        typedef typename F::template result<typename Vector::t4>::type type;
        
       constexpr  type operator()(Vector & vect) const{
          //  F f;
            return F{}(vect.v4);
        }
   
        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v4);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<5,Vector,F>{
        
        typedef typename F::template result<typename Vector::t5>::type type;
      
        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v5);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v5);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<6,Vector,F>{
        
        typedef typename F::template result<typename Vector::t6>::type type;

        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v6);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v6);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<7,Vector,F>{
        
        typedef typename F::template result<typename Vector::t7>::type type;
              
        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v7);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v7);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<8,Vector,F>{
        
        typedef typename F::template result<typename Vector::t8>::type type;
       
        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v8);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v8);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<9,Vector,F>{
        
        typedef typename F::template result<typename Vector::t9>::type type;
   
        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v9);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v9);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<10,Vector,F>{
        
        typedef typename F::template result<typename Vector::t10>::type type;

        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v10);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v10);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<11,Vector,F>{
        
        typedef typename F::template result<typename Vector::t11>::type type;
        
        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v11);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v11);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<12,Vector,F>{
        
        typedef typename F::template result<typename Vector::t12>::type type;
                
        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v12);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v12);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<13,Vector,F>{
        
        typedef typename F::template result<typename Vector::t13>::type type;

        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v13);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v13);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<14,Vector,F>{
        
        typedef typename F::template result<typename Vector::t14>::type type;
        
        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v14);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v14);
        }
    };

    template <typename Vector,typename F>
    struct at_vector<15,Vector,F>{
        
        typedef typename F::template result<typename Vector::t15>::type type;

        constexpr type operator()(Vector & vect) const
        {
           // F f;
            return F{}(vect.v15);
        }

        constexpr type operator()(Vector const & vect) const
        {
           // F f;
            return F{}(vect.v15);
        }
    };

}}}//quan::fun::detail

#endif
