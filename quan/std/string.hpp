#ifndef QUAN_STD_STRING_HPP_INCLUDED
#define  QUAN_STD_STRING_HPP_INCLUDED

#include <string>
#include <quan/meta/binary_op.hpp>

namespace quan{ namespace meta{ namespace impl{

   template<typename CharType>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      quan::meta::plus,
      std::basic_string<CharType>
   >{
      typedef std::basic_string<CharType> type;
   };

   
   template<typename CharType>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      quan::meta::plus,
      CharType *
   >{
      typedef std::basic_string<CharType> type;
   };

   template<typename CharType>
   struct binary_op_impl<
      CharType *,
      quan::meta::plus,
      std::basic_string<CharType> 
   >{
      typedef std::basic_string<CharType> type;
   };

   template<typename CharType>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      quan::meta::plus,
      CharType const *
   >{
      typedef std::basic_string<CharType> type;
   };

   template<typename CharType>
   struct binary_op_impl<
      CharType const *,
      quan::meta::plus,
      std::basic_string<CharType> 
   >{
      typedef std::basic_string<CharType> type;
   };


   template<typename CharType>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      quan::meta::plus_equals,
      std::basic_string<CharType>
   >{
      typedef std::basic_string<CharType> & type;
   };

   template<typename CharType>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      quan::meta::plus_equals,
      CharType *
   >{
      typedef std::basic_string<CharType> & type;
   };

   template<typename CharType>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      quan::meta::plus_equals,
      CharType const *
   >{
      typedef std::basic_string<CharType> & type;
   };

   template<typename CharType,typename Op>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      Op,
      std::basic_string<CharType>,
      typename quan::where_<
         quan::meta::or_<
            quan::meta::is_relational_operator<Op>,
            quan::meta::is_equality_operator<Op>
         >
      >::type
   >{
      typedef bool type;
   };

   template<typename CharType,typename Op>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      Op,
      CharType const *,
      typename quan::where_<
         quan::meta::or_<
            quan::meta::is_relational_operator<Op>,
            quan::meta::is_equality_operator<Op>
         >
      >::type
   >{
      typedef bool type;
   };

   template<typename CharType,typename Op>
   struct binary_op_impl<
      std::basic_string<CharType>, 
      Op,
      CharType *,
      typename quan::where_<
         quan::meta::or_<
            quan::meta::is_relational_operator<Op>,
            quan::meta::is_equality_operator<Op>
         >
      >::type
   >{
      typedef bool type;
   };

   template<typename CharType,typename Op>
   struct binary_op_impl<
      CharType * , 
      Op,
      std::basic_string<CharType>,
      typename quan::where_<
         quan::meta::or_<
            quan::meta::is_relational_operator<Op>,
            quan::meta::is_equality_operator<Op>
         >
      >::type
   >{
      typedef bool type;
   };

   template<typename CharType,typename Op>
   struct binary_op_impl<
      CharType const * , 
      Op,
      std::basic_string<CharType>,
      typename quan::where_<
         quan::meta::or_<
            quan::meta::is_relational_operator<Op>,
            quan::meta::is_equality_operator<Op>
         >
      >::type
   >{
      typedef bool type;
   };
   
}}}

#endif
