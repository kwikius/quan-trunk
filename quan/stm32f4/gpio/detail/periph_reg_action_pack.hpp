#ifndef QUAN_STM32F4_GPIO_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED

#include <type_traits>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/push_back.hpp>
#include <quan/concepts/meta/type_sequence/for_each.hpp>
#include <quan/stm32f4/gpio/detail/get_periph_reg.hpp>
#include <quan/stm32f4/gpio/settings.hpp>
#include <quan/stm32f4/detail/periph_reg_action_fwd.hpp>
#include <quan/stm32f4/detail/periph_reg_action_pack_fwd.hpp>
#include <quan/stm32f4/gpio/settings.hpp>
#include <quan/meta/low_bits_mask.hpp>

#include <quan/stm32f4/detail/make_boolean_action.hpp>

namespace quan{ namespace stm32f4{ namespace detail{

/*
  OState setting is a special case because its a boolean value
*/
 template< typename Pin, typename Setting>
   struct periph_reg_action_pack<Pin,Setting,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32f4::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32f4::gpio::OState,Setting>
        >
      >::type
   >{
//      typedef typename Pin::port_type port_type;
//
//      typedef typename quan::stm32f4::gpio::detail::get_periph_reg<Pin,Setting>::type reg_type;
//
//      typedef typename reg_type::value_type value_type;
//      static constexpr bool value = Setting::value;
//      static constexpr value_type port_value = 1 << ( Pin::pin_value);
//      static constexpr value_type mask = (value) ? port_value : ~port_value;
//      typedef typename quan::meta::if_c<(value),quan::meta::bit_or, quan::meta::bit_and>::type tag_type;
//      typedef quan::stm32f4::detail::periph_reg_action< reg_type,tag_type,mask > action_type;
      typedef typename quan::stm32f4::detail::make_boolean_action<
         (Setting::value),
         typename quan::stm32f4::gpio::detail::get_periph_reg<Pin,Setting>::type ,
         (Pin::pin_value)
      >::type action_type;
      template <typename Listof_PeriphRegAction>
      struct apply{
          typedef typename quan::meta::push_back<Listof_PeriphRegAction,action_type >::type type;
      };
   };

/*
  a functor to transform input States to output periph_reg_action
  and add actions to the list
  These are all 2 bit fields so use both  & and | action
*/
   template< typename Pin, typename Setting>
   struct periph_reg_action_pack<Pin,Setting,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32f4::gpio::Pin,Pin>,
            quan::meta::or_<
               quan::is_model_of<quan::stm32f4::gpio::Mode,Setting>
              , quan::is_model_of<quan::stm32f4::gpio::OType,Setting>
              , quan::is_model_of<quan::stm32f4::gpio::Pupd,Setting>
              , quan::is_model_of<quan::stm32f4::gpio::OSpeed,Setting>
             // , quan::is_model_of<quan::stm32f4::gpio::AlternateFunction,Setting>
            >
         >
      >::type
   >{
      typedef typename Pin::port_type port_type;
      typedef typename quan::stm32f4::gpio::detail::get_periph_reg<Pin,Setting>::type reg_type;
      typedef typename reg_type::value_type value_type;

      static constexpr value_type numbits = Setting::numbits;
      static constexpr value_type pin_value = Pin::pin_value;
      static constexpr value_type shift = pin_value * numbits;
      static constexpr value_type or_mask = Setting::value << shift;
      static constexpr value_type and_mask = ~( quan::meta::low_bits_mask<numbits>::value << shift) | or_mask;
  
//      static constexpr value_type xor_mask = quan::meta::low_bits_mask<numbits>::value;
//      static constexpr value_type notvalue = value ^ xor_mask;
//
//      static constexpr value_type pin_value = Pin::pin_value;
//
//      static constexpr value_type or_mask = value << ( pin_value * numbits) ;
//      static constexpr value_type and_mask = ~ (notvalue << ( pin_value * numbits) );

      typedef quan::stm32f4::detail::periph_reg_action< reg_type,quan::meta::bit_or,or_mask > or_type;
      typedef quan::stm32f4::detail::periph_reg_action< reg_type,quan::meta::bit_and,and_mask > and_type;

      template <typename Listof_PeriphRegAction>
      struct apply{
          typedef typename quan::stm32f4::detail::add_periph_reg_action<
               Listof_PeriphRegAction,or_type, and_type,Pin,Setting
          >::type type;
      };
   };

   template< typename Pin, typename Setting>
   struct periph_reg_action_pack<Pin,Setting,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32f4::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32f4::gpio::AlternateFunction,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type port_type;
      typedef typename quan::stm32f4::gpio::detail::get_periph_reg<Pin,Setting>::type reg_type;
      typedef typename reg_type::value_type value_type;

//      static constexpr value_type numbits = Setting::numbits;
//      static constexpr value_type value = Setting::value;
//      static constexpr value_type xor_mask = quan::meta::low_bits_mask<numbits>::value;
//      static constexpr value_type notvalue = value ^ xor_mask;
      // The AlternateFunction is a special case. The actual register depends on the
      // pin value
     // The bit position in the register is the on the number of bits in the field of the setting
//      static constexpr value_type pin_value =
//           ( quan::meta::and_<
//                quan::is_model_of< quan::stm32f4::gpio::AlternateFunction,Setting >,
//                quan::meta::bool_<(Pin::pin_value >=8)>
//            >::value )? Pin::pin_value - 8 : Pin::pin_value;

      static constexpr value_type numbits = Setting::numbits;
      static constexpr value_type pin_value =
           ( quan::meta::and_<
                quan::is_model_of< quan::stm32f4::gpio::AlternateFunction,Setting >,
                quan::meta::bool_<(Pin::pin_value >=8)>
            >::value )? Pin::pin_value - 8 : Pin::pin_value;
      static constexpr value_type shift = pin_value * numbits;
      static constexpr value_type or_mask = Setting::value << shift;
      static constexpr value_type and_mask = ~( quan::meta::low_bits_mask<numbits>::value << shift) | or_mask;

//      static constexpr value_type or_mask = value << ( pin_value * numbits) ;
//      static constexpr value_type and_mask = ~ (notvalue << ( pin_value * numbits) );

      typedef quan::stm32f4::detail::periph_reg_action< reg_type,quan::meta::bit_or,or_mask > or_type;
      typedef quan::stm32f4::detail::periph_reg_action< reg_type,quan::meta::bit_and,and_mask > and_type;

      template <typename Listof_PeriphRegAction>
      struct apply{
          // apply the alternate function mode as well as the actual alternate function
          typedef typename periph_reg_action_pack<
               Pin,quan::stm32f4::gpio::mode::alternate_function
          >:: template apply<Listof_PeriphRegAction>::type first_list_type;
          typedef typename quan::stm32f4::detail::add_periph_reg_action<
               first_list_type,or_type, and_type,Pin,Setting
          >::type type;
      };
   };

}}}//quan::stm32f4::detail

#endif // QUAN_STM32F4_GPIO_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
