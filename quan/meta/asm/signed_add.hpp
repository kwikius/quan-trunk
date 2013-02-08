#ifndef QUAN_META_ASM_SIGNED_ADD_HPP_INCLUDED
#define QUAN_META_ASM_SIGNED_ADD_HPP_INCLUDED

#include <quan/meta/asm/unsigned_add.hpp>
#include <quan/meta/asm/unsigned_sub.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/asm/extended_reg.hpp>

namespace quan{ namespace meta{ namespace asm_{

   namespace detail{

      template <typename I, I lhs,I rhs>
      struct signed_add_impl_pp{
         typedef typename quan::meta::signed_to_unsigned<I>::type uint_type;
         typedef typename quan::meta::asm_::unsigned_add<
            uint_type,static_cast<uint_type>(lhs),static_cast<uint_type>(rhs)
         >::type type;
      };

      template <typename I, I lhs,I rhs>
      struct signed_add_impl_nn{
         typedef typename quan::meta::signed_to_unsigned<I>::type uint_type;
         static const I lhs_ = -lhs;
         static const I rhs_ = -rhs;
         typedef typename quan::meta::asm_::unsigned_add<
            uint_type,static_cast<uint_type>(lhs_),static_cast<uint_type>(rhs_)
         >::type unsigned_type;
         typedef quan::meta::asm_::extended_reg<
            uint_type,unsigned_type::lo_reg,unsigned_type::hi_reg,-1
         > type;
      };

      template <typename I, I lhs,I rhs>
      struct signed_add_impl_pn{
         typedef typename quan::meta::signed_to_unsigned<I>::type uint_type;
         static const I lhs_ = lhs;
         static const I rhs_ = -rhs;
         typedef typename quan::meta::asm_::unsigned_sub<
            uint_type,static_cast<uint_type>(lhs_),static_cast<uint_type>(rhs_)
         >::type type;
        
      };

      template <typename I, I lhs,I rhs>
      struct signed_add_impl_np{
         typedef typename quan::meta::signed_to_unsigned<I>::type uint_type;
         static const I lhs_ = -lhs;
         static const I rhs_ = rhs;
         typedef typename quan::meta::asm_::unsigned_sub<
            uint_type,static_cast<uint_type>(lhs_),static_cast<uint_type>(rhs_)
         >::type unsigned_type;

         typedef quan::meta::asm_::extended_reg<
            uint_type,
            unsigned_type::lo_reg,
            unsigned_type::hi_reg,
            (-1 * (unsigned_type::sign))
         > type;
        
      };

   }
   
   template <typename I, I lhs,I rhs>
   struct signed_add : quan::meta::eval_if_c<
      (lhs >=0),
      quan::meta::eval_if_c<
         (rhs >=0),
         detail::signed_add_impl_pp<I,lhs,rhs>,
         detail::signed_add_impl_pn<I,lhs,rhs>
      >,
      quan::meta::eval_if_c<
         (rhs >=0),
         detail::signed_add_impl_np<I,lhs,rhs>,
         detail::signed_add_impl_nn<I,lhs,rhs>
      >
    >::type{
      QUAN_STATIC_ASSERT((std::is_signed<I>::value));
      };
      
}}}//quan::meta::asm_

#endif

