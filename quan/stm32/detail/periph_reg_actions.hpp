#ifndef QUAN_STM32_DETAIL_PERIPH_REG_ACTIONS_HPP_INCLUDED
#define QUAN_STM32_DETAIL_PERIPH_REG_ACTIONS_HPP_INCLUDED
/*
 Copyright (c) 2012-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <type_traits>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/type_sequence.hpp>
// should move to concepts..
#include <quan/meta/copy_if.hpp>
#include <quan/meta/fold.hpp>
#include <quan/meta/transform.hpp>
#include <quan/meta/get_num_elements.hpp>
#include <quan/meta/front.hpp>
#include <quan/concepts/meta/type_sequence/for_each.hpp>
#include <quan/stm32/detail/get_reg.hpp>

#include <quan/stm32/detail/periph_reg_action_pack_fwd.hpp>
#include <quan/stm32/detail/add_periph_reg_action.hpp>

namespace quan{ namespace stm32{ namespace detail{

/*
  get the corect function for folding and applying values to a periphreg 
*/
   template < typename PeriphRegActionFnTag >
   struct get_fold_action_functor;

   template < typename PeriphRegActionFnTag >
   struct get_apply_action_functor;

   template <>
   struct get_fold_action_functor<quan::meta::bit_or>{ typedef quan::operator_bit_or type;};

   template <>
   struct get_fold_action_functor<quan::meta::bit_and>{ typedef quan::operator_bit_and type;};

   template <>
   struct get_apply_action_functor<quan::meta::bit_or>{ typedef quan::operator_or_equals type;};

   template <>
   struct get_apply_action_functor<quan::meta::bit_and>{ typedef quan::operator_and_equals type;};

   template <> 
   struct get_apply_action_functor<quan::meta::equals>{ typedef quan::operator_equals type;};
 

//----------------------------------------------------------------------------

   // model of PeriphRegAction Archetype ( model of PolyMorphicFunctor<0,0> ) 
   // PeripReg is a model of quan::stm32:;PeriphReg
   // PeriphRegActionFnTag is a model of quan::meta::OperatorTag

   // is this not rather an atomic periph_reg_action or single periph_reg_action fundamental actio or basic_action
   // basic_periph_reg_action

   template <typename PeriphReg, typename PeriphRegActionFnTag, typename PeriphReg::value_type N >
   struct periph_reg_action{

      typedef PeriphReg                                     periph_reg_type;
      typedef typename   periph_reg_type::module_type       module_type;  
      typedef PeriphRegActionFnTag                          action_tag_type;
      typedef typename periph_reg_type::value_type          value_type;
      static  const value_type                              value = N;
      typedef periph_reg_action                             type;

      void operator()() const
      {
          typedef typename get_apply_action_functor<action_tag_type>::type function;

          typedef quan::stm32::detail::get_reg<module_type, periph_reg_type> get_reg;
          auto ptr = get_reg{}();
          function()(*ptr, value);
      }
   };
 
   // model of PeriphRegAction
   struct periph_reg_null_action{
     void operator()()const{}
     typedef periph_reg_null_action type;
   };

    // model of PeriphRegAction
   // default reduction is identity
   template <typename PeriphRegAction> 
   struct periph_reg_reduce_action { 
      typedef PeriphRegAction type;
   };

   // oring by 0 reduces to null_action as X | 0 = X
   template <typename PeriphReg> 
   struct periph_reg_reduce_action<periph_reg_action<PeriphReg,quan::meta::bit_or,0> >
   {
       typedef periph_reg_null_action type;
   };

  // anding by ~0 reduces to null_action as X & ~0  = X
   template <typename PeriphReg> 
   struct periph_reg_reduce_action<periph_reg_action<PeriphReg,quan::meta::bit_and,~0> >{
       typedef periph_reg_null_action type;
   };

   // the usual case is that an or action is followed by an and action
   // could check that or and and values are compatible . Not necessaryily the case for e.g toggle
  // but that ( e.g in setting and then clearing a flag should prob be disallowed in the apply fn?
   template <typename PeriphReg, typename PeriphReg::value_type OrValue, typename PeriphReg::value_type AndValue >
   struct periph_reg_combined_action{

      typedef PeriphReg                               periph_reg_type;
      typedef typename periph_reg_type::module_type   module_type;  
      typedef typename periph_reg_type::value_type    value_type;
      static const value_type                         or_value = OrValue & AndValue;
      static const value_type                         and_value = AndValue;
      typedef                                         periph_reg_combined_action type;

      struct with_or_fun{
         typedef with_or_fun type;
         static void apply() 
         {
            typedef quan::stm32::detail::get_reg<module_type, periph_reg_type> get_reg;
            auto ptr = get_reg()();
            ptr->set(( ptr->get() | or_value ) & and_value);
         }
      };

      struct without_or_fun{
         typedef without_or_fun type;
         static  void apply() 
          {
            typedef quan::stm32::detail::get_reg<module_type, periph_reg_type> get_reg;
            auto ptr = get_reg()();
            ptr->set( ptr->get() & and_value);
           }
      };

     // when the or_value and and_value are the same
     // use this function . No need to read the register first
      struct assign_fun{
         typedef assign_fun type;
         static void apply() 
         {
            typedef quan::stm32::detail::get_reg<module_type, periph_reg_type> get_reg;
            get_reg{}()->set( or_value );
         }
      };
      // chhose the actual function depending on the values
      void  operator()() const
      {
         typedef typename quan::meta::eval_if_c<
            (or_value == and_value),
            assign_fun,
            quan::meta::eval_if_c<
               (or_value != 0),
               with_or_fun,
               without_or_fun
            >
         >::type fun;
         fun::apply();
      }
   };

}}} // quan::stm32::detail

namespace quan{ namespace meta{

/*
   compile time and and or binary ops for periph_reg_action
*/
   namespace impl {
      template  <
         typename PeriphReg ,
         typename PeriphReg::value_type LhsValue, 
         typename PeriphReg::value_type RhsValue
      >
      struct binary_op_impl<
            quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_or,LhsValue>,
            quan::meta::bit_or,
             quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_or,RhsValue>
      >{
          typedef quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_or,LhsValue | RhsValue> type;
      };

      template  <
         typename PeriphReg ,
         typename PeriphReg::value_type LhsValue, 
         typename PeriphReg::value_type RhsValue
      >
      struct binary_op_impl<
            quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_and,LhsValue>,
            quan::meta::bit_and,
            quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_and,RhsValue>
      >{
          typedef quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_and,LhsValue & RhsValue> type;
      };
   } // impl 
}}//quan::meta

namespace quan{ namespace stm32{ namespace detail{

/*
   Inputs : M  a model of Module
    Listof_PeriphRegAction : a model of type_list<
*/
   template <typename Module, typename Listof_PeriphRegAction>
   struct get_periph_reg_actions_for_this_module{

      struct predicate{

         template <typename Lhs>
         struct apply{
             typedef std::is_same<Module,typename Lhs::module_type> type;
         };
      };

      typedef typename quan::meta::copy_if<
         Listof_PeriphRegAction,
         predicate
      >::type type;
   };

//---------

    // get actions that apply to PeriphReg
   // model of meta::PolyMorphicFunctor<1>
    //PeripReg is a model of PeripReg
    // actions is a modl of type_sequence<Action...>
    template <typename PeriphReg, typename Listof_PeriphRegAction>
    struct get_actions_that_apply_to_this_periph_reg{

      struct predicate{

         template <typename Lhs>
         struct apply{
             typedef std::is_same<PeriphReg,typename Lhs::periph_reg_type> type;
         };

      };

      typedef typename quan::meta::copy_if<
         Listof_PeriphRegAction,
         predicate
      >::type type;
    };

    template <typename Listof_PeriphRegAction>
    struct get_assign_periph_reg_actions{

      struct predicate{
         template <typename Lhs>
         struct apply{
             typedef std::is_same<typename Lhs::action_tag_type,quan::meta::equals> type;
         };
      };

      typedef typename quan::meta::copy_if<
         Listof_PeriphRegAction,
         predicate
      >::type type;
    };

//---------------

    template <typename Listof_PeriphRegAction>
    struct get_or_periph_reg_actions{

      struct predicate{
         template <typename Lhs>
         struct apply{
             typedef std::is_same<typename Lhs::action_tag_type,quan::meta::bit_or> type;
         };
      };

      typedef typename quan::meta::copy_if<
         Listof_PeriphRegAction,
         predicate
      >::type type;
    };

//---------------

    template <typename Listof_PeriphRegAction>
    struct get_and_periph_reg_actions{

      struct predicate{
         template <typename Lhs>
         struct apply{
             typedef std::is_same<typename Lhs::action_tag_type,quan::meta::bit_and> type;
         };
      };

      typedef typename quan::meta::copy_if<
         Listof_PeriphRegAction,
         predicate
      >::type type;
    };

//------------------

    template < typename Listof_PeriphRegAction>
    struct fold_periph_reg_actions_impl{

      struct function{
         template <typename Lhs, typename Rhs>
         struct apply{
             // check same tag???
             typedef typename Lhs::action_tag_type action_tag_type;
             typedef typename get_fold_action_functor<action_tag_type>::type function_type;
             typedef typename function_type:: template apply< Lhs, Rhs>::type type;
         };
      };

      typedef typename quan::meta::fold<
         typename quan::meta::pop_front<Listof_PeriphRegAction>::type,
         typename quan::meta::front<Listof_PeriphRegAction>::type, 
         function
      >::type type;

    };

//---------

    template < typename Listof_PeriphRegAction>
    struct fold_periph_reg_actions{

      typedef typename quan::meta::eval_if_c<
       (quan::meta::get_num_elements<Listof_PeriphRegAction>::value > 0),
        quan::stm32::detail::fold_periph_reg_actions_impl<Listof_PeriphRegAction>,
        quan::stm32::detail::periph_reg_null_action
     >::type  type;

    };

   template <typename OrAction, typename AndAction>
   struct make_combined_periph_reg_action{
 
       typedef quan::stm32::detail::periph_reg_combined_action<
         typename OrAction::periph_reg_type, OrAction::value, AndAction::value
       > type; 
   };

   template <> 
   struct make_combined_periph_reg_action<quan::stm32::detail::periph_reg_null_action, quan::stm32::detail::periph_reg_null_action>
   {    
        typedef quan::stm32::detail::periph_reg_null_action type;
   };

   template <typename AndAction> 
   struct make_combined_periph_reg_action<quan::stm32::detail::periph_reg_null_action, AndAction>
   {
        typedef AndAction type;
   };

   template <typename OrAction> 
   struct make_combined_periph_reg_action< OrAction, quan::stm32::detail::periph_reg_null_action>
   {
        typedef OrAction type;
   };

//called from user
   template <typename Module, typename Listof_PeriphRegAction>
   struct apply_periph_reg_actions
   {
      typedef apply_periph_reg_actions type; 

//########################################################################################################
      typedef typename quan::stm32::detail::get_periph_reg_actions_for_this_module<Module,Listof_PeriphRegAction>::type module_actions;
      static_assert(quan::meta::get_num_elements<
         module_actions
      >::value == quan::meta::get_num_elements<
         Listof_PeriphRegAction
      >::value,"some elements in the Listof_PeriphRegAction dont apply to this Module");
//####################################################################################

      // The Regactions have been filtered. All actions apply to this module
      // only and or or actions
      template <typename RegActions>
      struct reduce_and_or_actions_to_single_action{
         
         typedef typename quan::stm32::detail::get_or_periph_reg_actions<RegActions>::type or_reg_actions;
         // fold all or_actions into one
         typedef typename quan::stm32::detail::fold_periph_reg_actions<or_reg_actions>::type  or_action;

         typedef typename quan::stm32::detail::get_and_periph_reg_actions<RegActions>::type and_reg_actions;
         // fold all and_actions into one
         typedef typename quan::stm32::detail::fold_periph_reg_actions<and_reg_actions>::type and_action;

         typedef typename quan::stm32::detail::periph_reg_reduce_action<or_action>::type or_action1;
         typedef typename quan::stm32::detail::periph_reg_reduce_action<and_action>::type and_action1;

         typedef typename make_combined_periph_reg_action<or_action1,and_action1>::type type;
         
      };
      // list of assignment functions . Must only be 1
      template <typename AssignList>
      struct reduce_assign_action_to_single_action{
         static_assert(quan::meta::get_num_elements<AssignList>::value == 1, "too many assign actions on periph_reg");
         typedef typename quan::meta::front<AssignList>::type type;
      };

      template <typename RegActions>
      struct reduce_to_single_action{
         // look for assign actions first
         // if none then do and or actions
         typedef typename quan::stm32::detail::get_assign_periph_reg_actions<RegActions>::type assign_reg_actions;
         // n.b means that combo of assign and and or and or ignored
         typedef typename quan::meta::eval_if_c<
            (quan::meta::get_num_elements<assign_reg_actions>::value > 0),
             reduce_assign_action_to_single_action<assign_reg_actions>,
             reduce_and_or_actions_to_single_action<RegActions>
         >::type type;
            
      };

      // this is called for all the periph_regs in the Module
      template <typename PeriphReg>
      void operator()() const
      {

         typedef typename quan::stm32::detail::get_actions_that_apply_to_this_periph_reg<PeriphReg,Listof_PeriphRegAction>::type list_of_reg_actions;
         typedef typename reduce_to_single_action<list_of_reg_actions>::type emit_action;

         emit_action{}();

      }
   };

   // by default does nothing
   template <typename E,typename Where = void> 
   struct periph_reg_action_list_check{

      template <typename ... List>
      struct apply{
         typedef quan::meta::type_sequence<List...> type;
      };
   };
   
}}}// quan::stm32::detail


namespace quan{ namespace impl{
   
   // check Moule and Listof_PeriphRegAction are models?
   // must be declared as a model for quan::meta::for_each
   template <typename Module, typename Listof_PeriphRegAction>
   struct is_model_of_impl<
      quan::meta::PolymorphicFunctor<1,0>,
      quan::stm32::detail::apply_periph_reg_actions<Module,Listof_PeriphRegAction>
   > : quan::meta::true_{};

}} // quan::impl
//----------------------------------------------------------------------

namespace quan{ namespace stm32{  namespace detail{

   // nested PolymorphicFunctor<2,-1>
   struct unpack_actions{

      template <typename Listof_PeriphRegAction,typename Elem>
      struct apply{
         typedef typename Elem::template apply<Listof_PeriphRegAction>::type type;
      };
   };

   template <typename Pin>
   struct make_periph_reg_action_pack{

     template <typename PeriphRegSetting>
     struct apply{
        typedef  quan::stm32::detail::periph_reg_action_pack<Pin,PeriphRegSetting> type;
     };
   };

}}}//quan:stm32::detail

#endif // QUAN_STM32_DETAIL_PERIPH_REG_ACTIONS_HPP_INCLUDED
