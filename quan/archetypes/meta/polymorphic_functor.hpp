#ifndef QUAN_ARCHETYPES_META_POLYMORPHICFUNCTOR_HPP_INCLUDED
#define QUAN_ARCHETYPES_META_POLYMORPHICFUNCTOR_HPP_INCLUDED
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

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>

namespace quan{ namespace meta{

  /*
       meta::PolyMorphic functor<TemplateArgs, RuntimeArgs>

   especially meta PolyMorphic functors can have many different calling arrangements
   In quan the rule is to get the result_type
    of a function using a member class named apply
   with various template arguments
   if there is a operator() the functor must be instantiable
   as the operator must apply to an object.
    (Otherwise its seen as a purely a compiletime functor)
   This may be a burden but currently plan to live with it. 

   If NumRuntimeArgs  == -1 then there is no runtime operator function. It cant be called at runtime
   but will have an apply
   
   Instantiable functors may have less runtime arguments than their
   template parameters. In this case the operator function is
    called with the N left hand template parameters ,
     where N = NumTemplateArgs - NumRuntimeArgs
    The other parameters being deduced e.g PolymorphicFunctor<2,0> ->

       fun().template operator()<T1,T2>();

    This allows use of the operator() convention even though syntax may be slightly messy

    If RuntimeArgs == -2 then RuntimeArgs is variadic
    if TemplateArgs == -2 then TemplateArgs is variadic 
    
  */

   template <int TemplateArgs, int RuntimeArgs>
   struct PolymorphicFunctor;

}}

#endif // QUAN_ARCHETYPES_META_POLYMORPHICFUNCTOR_HPP_INCLUDED
