---------------------------------------
quan::stm32::freertos::usart_tx_rx_task
---------------------------------------

namespace quan{ namespace stm32{ namespace freertos{

   template <
      typename Usart
      ,uint32_t TX_q_size
      ,uint32_t RX_q_size
      ,typename TxPin
      ,typename RxPin
      ,typename CharType = char
   >
   struct usart_tx_rx_task{

       // enable the task after  setup
       static void enable(); 
  
       // call from global setup to setup ports peripherals etc
       template <uint32_t Baudrate>
       static void setup(uint32_t priority);

       // Return a character from the port
       // Blocks the task until a character is received
       static CharType get();

       // Put a character
       // will block if the tx fifo is full
       static void put (CharType ch);
  
       // put an array length n
       // will block if the tx fifo is full
       static void write(CharType const * str, size_t n);
       
       // write a null terminated character string
       // N.B only available if the Chartype is char
       if (is_same<CharType, char> ) 
       static void write ( char const * str);
       endif

   };

}}}