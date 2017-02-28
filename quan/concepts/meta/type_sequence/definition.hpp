#ifndef QUAN_CONCEPTS_META_TYPE_SEQUENCE_DEFINITION_HPP_INCLUDED
#define QUAN_CONCEPTS_META_TYPE_SEQUENCE_DEFINITION_HPP_INCLUDED

namespace quan{ namespace meta{

#if defined __cpp_concepts

   template <typename T> struct is_type_sequence : std::false_type{};

   template <typename T>
   concept bool TypeSequence = is_type_sequence<T>::value;

#else
   struct TypeSequence;
#endif

}}//quan::meta

#endif // QUAN_CONCEPTS_META_TYPE_SEQUENCE_DEFINITION_HPP_INCLUDED
