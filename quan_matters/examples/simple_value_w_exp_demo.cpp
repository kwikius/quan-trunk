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

#include <iostream>
#include <limits>
#include <cmath>
/*
   type representing a numeric value bundled with an exponent to base10 
   where parts of the calculations are done with TMP
*/
template <int Exp>
struct value_with_exp{

   const static int exp = Exp;
   explicit value_with_exp( double in): numeric_value(in){}
   // copy 
   value_with_exp( value_with_exp const & in) : numeric_value(in.numeric_value){}
   // other powers
   template <int ExpRhs>
   value_with_exp( value_with_exp<ExpRhs> in) :
   numeric_value(in.numeric_value * std::pow(10., ExpRhs - Exp)) {}
   double numeric_value;
};


// The fun part is the math ops:
// multiplication and division are very efficient:
template <int ExpLhs, int ExpRhs>
value_with_exp<ExpLhs + ExpRhs>
operator * (value_with_exp<ExpLhs> lhs, value_with_exp<ExpRhs> rhs)
{
   return value_with_exp<ExpLhs + ExpRhs>(lhs.numeric_value * rhs.numeric_value) ; 
}
// division impl should be easy to deduce..

// for addition and subtraction of value_with_exp with different exp params there is an obvious problem...
//What should be the type of the result?
// My solution in PQS and Quan was to select the finest grained exp for the type of the result:
// using a traits class 
// Lhs and Rhs are models of value_with_exp
template <typename Lhs,typename Rhs>
struct result_of_plus{
   static const int result_exp = 
   ( Lhs::exp < Rhs::exp)? Lhs::exp : Rhs::exp;
   typedef value_with_exp<result_exp> type;
};
template <int ExpLhs, int ExpRhs>
typename result_of_plus< value_with_exp<ExpLhs>,value_with_exp<ExpRhs> > ::type
operator  +(value_with_exp<ExpLhs> const & lhs, value_with_exp<ExpRhs> rhs)
{
   // deduce finest grained...
   typedef typename result_of_plus<
      value_with_exp<ExpLhs>,value_with_exp<ExpRhs> 
   > ::type result_type;
  
   // now need to adjust values, done here by utilising conversion ctor:
   // (On paper this looks poor for performance but in practise
   // if you deal with real calcs in real situations as I have
   // for several years and are aware of the capabilities of the type
   // there is simply no performance issue. I don't plan to expound on this
   //... but if you want to make academic arguments... F off 
   result_type left = lhs;
   result_type right = rhs;
   return result_type(left.numeric_value + right.numeric_value) ; 

}

// simple output
template <int Exp>
std::ostream & operator << (std::ostream & os,value_with_exp<Exp> rhs)
{
   std:: cout <<  rhs.numeric_value << " to power " << Exp ;
   return os;
}

//( some SI quantities Ignoring dimensional analysis:)

typedef value_with_exp<0> meters;
typedef value_with_exp<-3> millimeters;
typedef value_with_exp<3> kilometers;
// areas.. again ignoring dimensional analysis
typedef value_with_exp<0> square_meters;
typedef value_with_exp<-6> square_millimeters;

int main()
{
   meters x(1);
   kilometers y(1);
   
   std::cout << "x = " << x << '\n';
   std::cout << "y = " << y <<'\n';

   // do some math:

   std::cout << " x + y = " << x + y <<'\n';
   std::cout << " x * y = " << x * y <<'\n';
   // math and conversion..
   square_millimeters z = x * y;

   std::cout << "z  <-- (x * y)  = " << z <<'\n';

}



