#ifndef QUAN_CONCEPT_CHECK_META_BOOLEAN_CONSTANT_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_META_BOOLEAN_CONSTANT_HPP_INCLUDED
// Copyright Andrew Little 2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/meta/not.hpp>
#include <quan/concept_check/meta/identity_function.hpp>

namespace quan{ namespace concept_check{ namespace meta{

	// assert that T is a metafunction
	template <typename T>
	inline
	void boolean_constant()
	{
	   quan::concept_check::meta::identity_function<T>();
	   const static bool b = T::value;
	}

	template <typename T>
	inline
	void true_constant()
	{
	   quan::concept_check::meta::boolean_constant<T>();
	   static_assert(T::value == true, "T is not a model of true constant");
	}

	template <typename T>
	inline
	void false_constant()
	{
	   quan::concept_check::meta::boolean_constant<T>();
	   static_assert( T::value ==false , "T is not a model of false constant");
	}

}}}//quan::concept_check::meta


#endif
 
