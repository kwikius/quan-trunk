
namespace quan { namespace stm32 {

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::on_addr_tx()
   {
      i2c_port::clear_addr();
      i2c_type::get()->dr = *data_address;
      ++i2c_port::data_address;
      --i2c_port::numbytes_left;
      i2c_port::pfn_irq = i2c_port::on_btf;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::is_transmit_address()
   {
     return (i2c_port::slave_address & 1) == 0;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::enable_event_interrupts()
   {
      constexpr uint8_t i2c_cr2_itevten_bit = 9;
      i2c_type::get()->cr2.template bb_setbit<i2c_cr2_itevten_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::disable_event_interrupts()
   {
      constexpr uint8_t i2c_cr2_itevten_bit = 9;
      i2c_type::get()->cr2.template bb_clearbit<i2c_cr2_itevten_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::enable_buffer_interrupts()
   {
      constexpr uint8_t i2c_cr2_itbufen_bit = 10;
      i2c_type::get()->cr2.template bb_setbit<i2c_cr2_itbufen_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::disable_buffer_interrupts()
   {
      constexpr uint8_t i2c_cr2_itbufen_bit = 10;
      i2c_type::get()->cr2.template bb_clearbit<i2c_cr2_itbufen_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::enable_error_interrupts()
   {
      constexpr uint8_t i2c_cr2_iterren_bit = 8;
      i2c_type::get()->cr2.template bb_setbit<i2c_cr2_iterren_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::disable_error_interrupts()
   {
      constexpr uint8_t i2c_cr2_iterren_bit = 8;
      i2c_type::get()->cr2.template bb_clearbit<i2c_cr2_iterren_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::set_start_bit()
   {
      constexpr uint32_t i2c_cr1_start_bit = 8;
      i2c_type::get()->cr1.template bb_setbit<i2c_cr1_start_bit>(); 
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::set_stop_bit()
   {
      constexpr uint8_t i2c_cr1_stop_bit = 9;
      i2c_type::get()->cr1.template bb_setbit<i2c_cr1_stop_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::set_ack_bit()
   {
      constexpr uint8_t i2c_cr1_ack_bit = 10;
      i2c_type::get()->cr1.template bb_setbit<i2c_cr1_ack_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::clear_ack_bit()
   {
      constexpr uint8_t i2c_cr1_ack_bit = 10;
      i2c_type::get()->cr1.template bb_clearbit<i2c_cr1_ack_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::clear_addr()
   {
      i2c_type::get()->sr2.get();
      i2c_port::in_addr_mode = false;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::set_pos_bit()
   {
      constexpr uint8_t i2c_cr1_pos_bit = 11;
      i2c_type::get()->cr1.template bb_setbit<i2c_cr1_pos_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::clear_pos_bit()
   {
      constexpr uint8_t i2c_cr1_pos_bit = 11;
      i2c_type::get()->cr1.template bb_clearbit<i2c_cr1_pos_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > volatile bool 
   i2c_port<I2CP,SclPin,SdaPin>::transferring_data_flag = false;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > bool 
   i2c_port<I2CP,SclPin,SdaPin>::want_fast_mode = true;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > bool 
   i2c_port<I2CP,SclPin,SdaPin>::want_16_9_duty = false;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > quan::time_<int64_t>::ms 
   i2c_port<I2CP,SclPin,SdaPin>::start_time{0};

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > constexpr quan::time_<int64_t>::ms 
   i2c_port<I2CP,SclPin,SdaPin>::max_addr_wait_time;
      //only write these values when ! transferring_data
   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > uint8_t 
   i2c_port<I2CP,SclPin,SdaPin>::slave_address = 0;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > volatile uint8_t * 
   i2c_port<I2CP,SclPin,SdaPin>::data_address = 0;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > volatile int32_t 
   i2c_port<I2CP,SclPin,SdaPin>::numbytes_left = 0;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > int32_t 
   i2c_port<I2CP,SclPin,SdaPin>::total_bytes = 0;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   >  volatile typename i2c_port<I2CP,SclPin,SdaPin>::errno_t 
   i2c_port<I2CP,SclPin,SdaPin>::i2c_errno = i2c_port<I2CP,SclPin,SdaPin>::errno_t::no_error;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::transferring_data() 
   { return i2c_port::transferring_data_flag;}

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::addr_timeout()
   {
     return i2c_port::transferring_data()
      && (i2c_port::pfn_irq == i2c_port::on_addr)
      && ((quan::stm32::millis() - i2c_port::start_time) > i2c_port::max_addr_wait_time);
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::busy()
   {
      if (i2c_port::in_addr_mode || i2c_port::transferring_data() ){
         return true;
      }
      constexpr uint8_t i2c_cr1_stop_bit = 9;
      if(i2c_type::get()->cr1.template bb_getbit<i2c_cr1_stop_bit>()){
         return true;
      }
      constexpr uint8_t i2c_sr2_busy_bit = 1;
      return i2c_type::get()->sr2.template bb_getbit<i2c_sr2_busy_bit>();
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::is_valid_address(uint8_t address_in)
   {
      uint8_t address = address_in >> 1;
      if ((address == 0) || (address == 1)){
         return false;
      }
      return true;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   >  void 
   i2c_port<I2CP,SclPin,SdaPin>::init(bool fastmode_in, bool duty_type_in)
   {
      i2c_port::want_fast_mode = fastmode_in;
      i2c_port::want_16_9_duty = duty_type_in;
      quan::stm32::module_enable<i2c_type>();
      quan::stm32::module_enable<typename scl_pin_type::port_type>();
      quan::stm32::module_enable<typename sda_pin_type::port_type>();
   // TODO add check they are valid pins
      quan::stm32::apply<
         scl_pin_type
         ,quan::stm32::gpio::mode::af4 // all i2c pins are this af mode on F4
         ,quan::stm32::gpio::otype::open_drain
         ,quan::stm32::gpio::pupd::none         //  Use external pullup 5V tolerant pins
         ,quan::stm32::gpio::ospeed::slow 
      >();

      quan::stm32::apply<
         sda_pin_type
         ,quan::stm32::gpio::mode::af4 // all i2c pins are this af mode on F4
         ,quan::stm32::gpio::otype::open_drain
         ,quan::stm32::gpio::pupd::none          //  Use external pullup 5V tolerant pins
         ,quan::stm32::gpio::ospeed::slow 
      >();
   /*
    Program the peripheral input clock in I2C_CR2 Register in order to generate correct
   timings
   */
      uint32_t constexpr apb1_freq = quan::stm32::get_bus_frequency<quan::stm32::detail::apb1>();
      static_assert(apb1_freq == 42000000,"unexpected freq");
      // set clock speed for 42 MHz APB1 bus
      uint32_t constexpr freq = apb1_freq / 1000000;
      static_assert(apb1_freq % 1000000 == 0, "invalid freq");
      uint32_t const temp_cr2 = i2c_type::get()->cr2.get() & ~0b111111;
      i2c_type::get()->cr2.set( temp_cr2 | freq);

   /*
    Configure the clock control registers pClk1 = 42 MHz if main clk == 168 MHz
      NB not same as in  datasheet ?? 
   */
      uint32_t ccr_reg_val = 0;
      if( i2c_port::want_fast_mode){
         quan::frequency_<int32_t>::Hz constexpr i2c_freq_fast{400000};
         if(i2c_port::want_16_9_duty ){
            ccr_reg_val =  apb1_freq / (i2c_freq_fast.numeric_value() * 25);
         } else{
            ccr_reg_val =  apb1_freq / (i2c_freq_fast.numeric_value() * 3);
         }
         if (ccr_reg_val == 0){
            ccr_reg_val =1;
         }
         uint8_t constexpr  fs_bit = 15;
         ccr_reg_val |= quan::bit<uint32_t>(fs_bit);
         if(i2c_port::want_16_9_duty){
            uint8_t constexpr duty_bit = 14;
            ccr_reg_val |= quan::bit<uint32_t>(duty_bit);
         }
      }  
      else{
         quan::frequency_<int32_t>::Hz constexpr i2c_freq_slow{100000};
         ccr_reg_val = apb1_freq / (i2c_freq_slow.numeric_value() * 2);
      }
      uint32_t const temp_ccr = i2c_type::get()->ccr.get() & ~0xFFF;
      i2c_type::get()->ccr.set(temp_ccr | ccr_reg_val);
       
   /*
    Configure the rise time register
   */
      quan::time::ns const max_scl_risetime 
         = (i2c_port::want_fast_mode)? quan::time::ns{300} : quan::time::ns{1000};
      uint32_t const trise_reg_val 
         = static_cast<uint32_t>(max_scl_risetime * quan::frequency::Hz{apb1_freq} + 1.f);
      uint32_t const temp_trise = i2c_type::get()->trise.get() & ~0b111111;
      i2c_type::get()->trise.set(temp_trise | trise_reg_val);

      NVIC_EnableIRQ(quan::stm32::i2c::detail::get_event_irq_number<i2c_type>::value);
      NVIC_EnableIRQ(quan::stm32::i2c::detail::get_error_irq_number<i2c_type>::value);
   /*
    Program the I2C_CR1 register to enable the peripheral
   */
      uint8_t constexpr i2c_cr1_pe_bit = 0;
      i2c_type::get()->cr1. template bb_setbit<i2c_cr1_pe_bit>();
      // set to 7 bit addresses. 
   //######################################
   // NB not same as system headers or other examples which set bit 14 
   // but says this bit reserved in my version of ref man
      //Think therefore its just keep OAR1 bit 15 cleared
   // try setting bit 14 if this dont work!
     //  constexpr uint8_t i2c_oar1_add_mode_bit = 15;
     //  i2c_type::get()->oar1.bb_clearbit<i2c_oar1_add_mode_bit>();
       
     // i2c_type::get()->oar1.set(0x4000);
     // i2c_type::get()->oar2.set(0x0000);
   //###########################################################
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   >  void 
   i2c_port<I2CP,SclPin,SdaPin>::reset()
   {
      i2c_port::disable_event_interrupts();
      i2c_port::disable_buffer_interrupts();
      i2c_port::disable_error_interrupts();
      constexpr uint8_t i2c_cr1_swrst_bit = 15;
      i2c_type::get()->cr1. template bb_setbit<i2c_cr1_swrst_bit>();
      quan::stm32::module_reset<i2c_type>();
      i2c_type::get()->cr1.template bb_clearbit<i2c_cr1_swrst_bit>();
      //clear error bits
      i2c_type::get()->sr1 &= 0xFF; 
      i2c_port::pfn_irq = on_sb;
      i2c_port::transferring_data_flag = false;
      i2c_port::in_addr_mode = false;

      i2c_port::slave_address = 0;
      i2c_port::data_address = 0;
      i2c_port::numbytes_left = 0;
      i2c_port::i2c_errno = i2c_port::errno_t::no_error;
      i2c_port::init(i2c_port::want_fast_mode,i2c_port::want_16_9_duty);
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::on_sb(uint32_t sr1)
   {
      constexpr uint32_t i2c_sr1_sb = quan::bit<uint32_t>(0);
      if(!( sr1 & i2c_sr1_sb) ){return false;}
      i2c_type::get()->dr = slave_address;
      i2c_port::pfn_irq = on_addr;
      return true;
   }

   
   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::on_addr(uint32_t sr1)
   {
      constexpr uint32_t i2c_sr1_addr = quan::bit<uint32_t>(1);
      if(!( sr1 & i2c_sr1_addr) ){return false;}
      if ( i2c_port::is_transmit_address() ){
         i2c_port::on_addr_tx();
      }else{
         switch(i2c_port::total_bytes){
         case 1:
            i2c_port::clear_ack_bit();
            i2c_port::disable_event_interrupts();
            i2c_port::clear_addr();
            i2c_port::set_stop_bit();
            i2c_port::enable_event_interrupts();
            i2c_port::enable_buffer_interrupts(); // want rxne
            i2c_port::pfn_irq = i2c_port::on_rxne;
            break;
         case 2:
            i2c_port::set_pos_bit();
            i2c_port::disable_event_interrupts();
            i2c_port::clear_addr();
            i2c_port::clear_ack_bit();
            i2c_port::pfn_irq = on_btf;
            i2c_port::enable_event_interrupts(); 
            break;
         default:
            i2c_port::clear_addr();
            i2c_port::pfn_irq = i2c_port::on_btf;
            break;
         }
      }
      return true;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::on_btf(uint32_t sr1)
   {
      constexpr uint32_t i2c_sr1_btf = quan::bit<uint32_t>(2);
      if(!( sr1 & i2c_sr1_btf) ){return false;}
      if ( i2c_port::is_transmit_address()){ // tx
         if(i2c_port::numbytes_left != 0){
            i2c_type::get()->dr = *data_address++;
            --i2c_port::numbytes_left;
         }else{
            i2c_port::set_stop_bit();
            i2c_port::pfn_irq = on_sb;
            i2c_port::disable_event_interrupts();
            i2c_port::transferring_data_flag = false;
         }
      }else{  // rx
         switch(i2c_port::total_bytes){
         case 1:
            i2c_port::i2c_errno = i2c_port::errno_t::unexpected_single_total_bytes_in_rx_btf;
            i2c_port::disable_event_interrupts();
         break;
         case 2:
            i2c_port::pfn_irq = on_sb;
            i2c_port::disable_event_interrupts();
            i2c_port::set_stop_bit();
            i2c_port::data_address[0] = i2c_type::get()->dr;
            i2c_port::enable_event_interrupts();
            i2c_port::data_address[1] = i2c_type::get()->dr;
            i2c_port::numbytes_left = 0;
            i2c_port::transferring_data_flag = false;
         break;
         default:
            if(i2c_port::numbytes_left > 3){
               *i2c_port::data_address = i2c_type::get()->dr;
               ++i2c_port::data_address; 
               -- i2c_port::numbytes_left; 
            }else{
               if (i2c_port::numbytes_left == 3){
                  i2c_port::clear_ack_bit();
                  *i2c_port::data_address = i2c_type::get()->dr;
                  ++i2c_port::data_address; 
                  --i2c_port::numbytes_left;
                  i2c_port::disable_event_interrupts();
                  i2c_port::set_stop_bit();
                  *i2c_port::data_address = i2c_type::get()->dr;
                  ++i2c_port::data_address; 
                  --i2c_port::numbytes_left;
                  i2c_port::enable_event_interrupts();
                  i2c_port::enable_buffer_interrupts(); // want rxne for last byte
                  i2c_port::pfn_irq = on_rxne;
               }else{
                  i2c_port::i2c_errno = i2c_port::errno_t::invalid_num_bytes_in_rx_multibyte_btf;
                  i2c_port::disable_event_interrupts();
               }
            }
         }
      }
      return true;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline bool i2c_port<I2CP,SclPin,SdaPin>::on_rxne(uint32_t sr1)
   {
      constexpr uint32_t i2c_sr1_rxne = quan::bit<uint32_t>(6);  
      if(!( sr1 & i2c_sr1_rxne) ){return false;}
      *i2c_port::data_address = i2c_type::get()->dr;
      if( --i2c_port::numbytes_left != 0 ){  
         i2c_port::i2c_errno = i2c_port::errno_t::unexpected_not_last_byte_in_rxne;
      }
      i2c_port::pfn_irq = i2c_port::on_sb;
      i2c_port::disable_event_interrupts();
      i2c_port::disable_buffer_interrupts();
      i2c_port::transferring_data_flag = false;
      return true;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > bool (* i2c_port<I2CP,SclPin,SdaPin>::pfn_irq)(uint32_t) 
      = i2c_port<I2CP,SclPin,SdaPin>::on_sb;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > volatile bool i2c_port<I2CP,SclPin,SdaPin>::in_addr_mode = false;

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   >  bool i2c_port<I2CP,SclPin,SdaPin>::transfer_request(
            uint8_t slave_address_in, uint8_t * data_address_in, 
            int32_t numbytes_in)
   {
      if (i2c_port::busy() ){
         i2c_port::i2c_errno = i2c_port::errno_t::cant_start_new_transfer_when_i2c_busy;
         return false;
      }
      if( !i2c_port::is_valid_address(slave_address_in) ){
         i2c_port::i2c_errno = i2c_port::errno_t::invalid_address;
         return false;
      }
      if( numbytes_in == 0 ){
         i2c_port::i2c_errno = i2c_port::errno_t::zero_data;
         return false;
      }
      if(data_address_in == nullptr){
         i2c_port::i2c_errno = i2c_port::errno_t::data_pointer_is_null;
         return false;
      }
      i2c_port::disable_error_interrupts();
      i2c_port::disable_event_interrupts();
      i2c_port::slave_address = slave_address_in;
      i2c_port::data_address = data_address_in;
      i2c_port::numbytes_left = numbytes_in;
      i2c_port::total_bytes = numbytes_in;
      i2c_port::start_time = quan::stm32::millis();
      i2c_port::transferring_data_flag = true;
      i2c_port::pfn_irq = on_sb;
      i2c_port::in_addr_mode = true;
      i2c_port::clear_pos_bit();
      i2c_port::set_ack_bit();
      i2c_port::set_start_bit();
      i2c_port::enable_error_interrupts();
      i2c_port::enable_event_interrupts();
      return true;
   }

   template <
      typename I2CP,
      typename SclPin, 
      typename SdaPin
   > inline void i2c_port<I2CP,SclPin,SdaPin>::handle_irq( )
   {
      uint32_t const regval = i2c_port::i2c_type::get()->sr1.get();
      if (! i2c_port::pfn_irq(regval)){
         i2c_port::i2c_errno = i2c_port::errno_t::unexpected_flags_in_irq;
      }
   }

}}//quan::stm32
