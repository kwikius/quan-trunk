#ifndef QUAN_CONCEPTS_META_TYPE_SEQUENCE_DEFINITION_HPP_INCLUDED
#define QUAN_CONCEPTS_META_TYPE_SEQUENCE_DEFINITION_HPP_INCLUDED

#include <type_traits>
#include <quan/is_model_of.hpp>

namespace quan{ namespace meta{

   struct TypeSequence_;

#if defined __cpp_concepts

   template <typename T>
   concept bool TypeSequence = quan::is_model_of<quan::meta::TypeSequence_,T>::value;

#endif

}}//quan::meta

#endif // QUAN_CONCEPTS_META_TYPE_SEQUENCE_DEFINITION_HPP_INCLUDED
