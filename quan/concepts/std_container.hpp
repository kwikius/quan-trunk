#ifndef QUAN_CONCEPTS_STD_CONTAINER_HPP_INCLUDED
#define QUAN_CONCEPTS_STD_CONTAINER_HPP_INCLUDED

 /// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/where.hpp>
#include <list>
#include <quan/meta/bool.hpp>

namespace quan{

   struct StdContainer_;

   template <typename T>
   struct is_model_of<StdContainer_, std::list<T> > : quan::meta::true_{};


}//quan

#endif

