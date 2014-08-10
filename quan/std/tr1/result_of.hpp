#ifndef QUAN_STD_TR1_RESULT_OF_HPP_INCLUDED
#define QUAN_STD_TR1_RESULT_OF_HPP_INCLUDED


/*
 Copyright (c) 2005 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/config.hpp>
#ifdef QUAN_USE_QUAN_STD_TR1

namespace std{ namespace tr1{

   template <typename Function>
   struct result_of;

   template <typename F, typename T>
   struct result_of<F(T)>{
      typedef typename F::template result<F(T)>::type type;
   };

   template <typename F, typename T1, typename T2>
   struct result_of<F(T1,T2)>{
      typedef typename F::template result<F(T1,T2)>::type type;
   };

   template <typename F, typename T1, typename T2,typename T3>
   struct result_of<F(T1,T2,T3)>{
      typedef typename F::template result<F(T1,T2,T3)>::type type;
   };

   template <typename F, typename T1, typename T2,typename T3,typename T4>
   struct result_of<F(T1,T2,T3,T4)>{
      typedef typename F::template result<F(T1,T2,T3,T4)>::type type;
   };
}}
#else
#include <functional>
#endif

#endif

