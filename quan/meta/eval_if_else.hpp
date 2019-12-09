#ifndef QUAN_META_EVAL_IF_ELSE_HPP_INCLUDED
#define QUAN_META_EVAL_IF_ELSE_HPP_INCLUDED

/*
   simple version of eval_if
*/
namespace quan{ namespace meta{
   
   template <bool B, typename TrueFunction, typename FalseFunction>
   struct eval_if_else_c{
      typedef typename TrueFunction::type type;
   };

   template <typename TrueFunction,typename FalseFunction>
   struct eval_if_else_c<false,TrueFunction,FalseFunction> {
      typedef typename FalseFunction::type type;
   };

   template<typename C, typename TrueFunction, typename FalseFunction>
   struct eval_if_else : eval_if_else_c<((C::type::value)!=0),TrueFunction,FalseFunction>{};
   
}}//quan::meta

#endif // QUAN_META_EVAL_IF_ELSE_HPP_INCLUDED
