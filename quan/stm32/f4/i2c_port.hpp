#ifndef QUAN_STM32_F4_I2C_PORT_HPP_INCLUDED
#define QUAN_STM32_F4_I2C_PORT_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <quan/time.hpp>
#include <quan/frequency.hpp>
#include <quan/stm32/gpio.hpp>
#include <quan/stm32/i2c/typedefs.hpp>
#include <quan/stm32/f4/i2c/module_enable_disable.hpp>
#include <quan/stm32/sys_freq.hpp>
#include <quan/stm32/i2c/detail/get_irq_number.hpp>
#include <quan/stm32/millis.hpp>

namespace quan{ namespace stm32{

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   >
   struct i2c_port{

      enum class errno_t{
      no_error, 
      invalid_address,
      cant_start_new_transfer_when_i2c_busy,
      zero_data,
      data_pointer_is_null,
      invalid_num_bytes_in_rx_multibyte_btf,
      unexpected_single_total_bytes_in_rx_btf,
      unexpected_not_last_byte_in_rxne,
      unexpected_flags_in_irq,
      i2c_err_handler,
      unknown_exti_irq
   };
      typedef I2CP i2c_type;
      static_assert(quan::is_model_of<quan::stm32::I2C,i2c_type>::value,"must be a i2c port");
   // check valid pins for port
      typedef SclPin scl_pin_type;
      typedef SdaPin sda_pin_type;
   /*
      fast Duty true for 16/9 false for 1/3
    */
      static void init(bool fastmode_in, bool duty_type_in = false);
      static void reset();
      static inline bool transferring_data();
      static inline bool addr_timeout();
      static inline bool busy();
      static inline bool is_valid_address(uint8_t address_in);

   /*
      data_address_in state must persist while the transfer is in progress!
      eg after this call returns and while busy() is true
   */
      static bool transfer_request(
            uint8_t slave_address_in, 
            uint8_t * data_address_in, 
            int32_t numbytes
      );

      static inline void handle_irq( );
      static volatile errno_t i2c_errno;
   private:
     // friend void i2c::irq_handler<i2c_port>();
      static volatile bool transferring_data_flag;
      static quan::time_<int64_t>::ms start_time;
      static constexpr quan::time_<int64_t>::ms max_addr_wait_time{10};
      static uint8_t slave_address;
      static volatile uint8_t * data_address;
      static volatile int32_t numbytes_left;
      static int32_t total_bytes;
      static inline bool on_sb(uint32_t);
      static inline bool on_addr(uint32_t);
      static inline bool on_btf(uint32_t);
      static inline bool on_rxne(uint32_t);
      static bool (*pfn_irq)(uint32_t);
      static volatile bool in_addr_mode;
      static bool want_fast_mode;
      static bool want_16_9_duty;
      static void on_addr_tx();
      static inline bool is_transmit_address();
      static inline void enable_event_interrupts();
      static inline void disable_event_interrupts();
      static inline void enable_buffer_interrupts();
      static inline void disable_buffer_interrupts();
      static inline void enable_error_interrupts();
      static inline void disable_error_interrupts();
      static inline void set_start_bit();
      static inline void set_stop_bit();
      static inline void set_ack_bit();
      static inline void clear_ack_bit();
      static inline void clear_addr();
      static inline void set_pos_bit();
      static inline void clear_pos_bit();

      i2c_port() = delete;
      i2c_port(const i2c_port &) = delete;
      i2c_port operator = (const i2c_port &) = delete;
   };

}}//quan::stm32

#include <quan/stm32/f4/detail/i2c_port.ipp>

#endif // QUAN_STM32_F4_I2C_PORT_HPP_INCLUDED
