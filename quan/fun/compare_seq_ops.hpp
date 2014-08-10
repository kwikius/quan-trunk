#ifndef QUAN_FUN_COMPARE_SEQ_OPS_HPP_INCLUDED
#define QUAN_FUN_COMPARE_SEQ_OPS_HPP_INCLUDED

#include <quan/fun/make_fun_seq2.hpp>
#include <quan/fun/fun_seq2.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/fold_seq.hpp>
#include <quan/static.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/are_fun_sequences.hpp>
#include <quan/fun/same_size_seq.hpp>
#include <quan/fusion/static_value/static_bool.hpp>
#include <quan/fun/inner_product_seq.hpp>

namespace quan{ namespace fun{namespace detail{

   /*struct compare_seq{

      template <typename SeqL, typename SeqR>
      struct result{
         
         typedef typename quan::fun::make_fun_seq2<quan::operator_equal_to,SeqL,SeqR>::type
         and_type;

         typedef quan::fusion::static_bool<true> true_;
         
         typedef typename quan::fun::fold_seq::template result<
               and_type,true_,quan::operator_logical_and
         >::type type;
      };


      template <typename SeqL,typename SeqR>
      typename result<const SeqL,const SeqR>::type
      operator()(SeqL const &seqL, SeqR  const & seqR)const
      {
         typedef quan::fun::fun_seq2<
            quan::operator_equal_to,SeqL,SeqR
         > and_seq_type;

         quan::fun::fold_seq folder;
         typedef typename quan::fusion::static_bool<true> true_;
         
         return folder(and_seq_type(seqL,seqR),true_(),quan::operator_logical_and()) ;
      }
      
   };*/
}}}//quan::fun::detail

namespace quan{namespace fun{
   template <typename SeqL,typename SeqR>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_sequences<SeqL,SeqR>,
         quan::fun::same_size_seq<SeqL,SeqR>
      >,
      typename inner_product_seq::template result<
         const SeqL, const SeqR,quan::operator_logical_and, quan::operator_equal_to
      >::type
   >::type
   operator == (SeqL const & lhs, SeqR const & rhs)
   {
      return inner_product_seq()(
         lhs,rhs,quan::operator_logical_and(), quan::operator_equal_to()
      );
   }

   template <typename SeqL,typename SeqR>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_sequences<SeqL,SeqR>,
         quan::fun::same_size_seq<SeqL,SeqR>
      >,
      typename inner_product_seq::template result<
         SeqL,SeqR,quan::operator_logical_and, quan::operator_equal_to
      >::type
   >::type
   operator == (SeqL  & lhs, SeqR  & rhs)
   {
      return inner_product_seq()(
         lhs,rhs,quan::operator_logical_and(), quan::operator_equal_to()
      );
   }
   
   template <typename SeqL,typename SeqR>
   inline 
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_sequences<SeqL,SeqR>,
         quan::fun::same_size_seq<SeqL,SeqR>
      >,
      bool
   >::type
   operator != (SeqL const & lhs, SeqR const & rhs)
   {
     // return  ! (lhs == rhs);
      return inner_product_seq()(
         lhs,rhs,quan::operator_logical_or(), quan::operator_not_equal_to()
      );
   }
 
}}//quan::fun

#endif
