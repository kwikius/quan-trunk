#ifndef QUAN_STM32_FREERTOS_APM_SET_BAUD_HPP_INCLUDED
#define QUAN_STM32_FREERTOS_APM_SET_BAUD_HPP_INCLUDED

#include <quan/stm32/usart.hpp>
#include <quan/stm32/get_module_bus_frequency.hpp>

namespace quan{ 
namespace stm32{ 
namespace freertos{ 
namespace apm{ 
namespace detail{


      inline bool get_all_baudrate_values_ubs(
         uint32_t usart_bus_clk, uint32_t baudrate,bool over8,uint32_t & mantissa, uint32_t & fract, uint32_t & reg_value
      )
      {
          uint32_t const integerdivider = over8
        ? (25 * usart_bus_clk) / (2 * baudrate)
        : (25 * usart_bus_clk) / (4 * baudrate); 
        
         uint32_t const tmpreg = (integerdivider / 100) << 4;
         uint32_t const fractionaldivider = integerdivider - (100 * (tmpreg >> 4));
         uint32_t const value = over8
         ?  tmpreg | ( ((fractionaldivider * 8 + 50) / 100) & static_cast<uint8_t>(0x07) )
         :  tmpreg | ( ((fractionaldivider * 16 + 50) / 100) & static_cast<uint8_t>(0x0F) );
         bool const result = (value != 0)  && ((value & 0xFFFF0000) == 0);
         if (result){
            mantissa = tmpreg  >> 4;
            fract =  over8
            ?  ( ((fractionaldivider * 8 + 50) / 100) & static_cast<uint8_t>(0x07) )
            :  ( ((fractionaldivider * 16 + 50) / 100) & static_cast<uint8_t>(0x0F) );
            reg_value = value;
         }
         return result;

      }
      
      template <typename Usart>
      inline bool get_all_baudrate_values(uint32_t baudrate,bool over8,uint32_t & mantissa, uint32_t & fract, uint32_t & reg_value)
     {
        
        constexpr uint32_t usart_bus_clk = quan::stm32::get_module_bus_frequency<Usart>();

        return  get_all_baudrate_values_ubs(usart_bus_clk,baudrate,over8,mantissa,fract,reg_value);
     
//        uint32_t const integerdivider = over8
//        ? (25 * usart_bus_clk) / (2 * baudrate)
//        : (25 * usart_bus_clk) / (4 * baudrate); 
//        
//         uint32_t const tmpreg = (integerdivider / 100) << 4;
//         uint32_t const fractionaldivider = integerdivider - (100 * (tmpreg >> 4));
//         uint32_t const value = over8
//         ?  tmpreg | ( ((fractionaldivider * 8 + 50) / 100) & static_cast<uint8_t>(0x07) )
//         :  tmpreg | ( ((fractionaldivider * 16 + 50) / 100) & static_cast<uint8_t>(0x0F) );
//         bool const result = (value != 0)  && ((value & 0xFFFF0000) == 0);
//         if (result){
//            mantissa = tmpreg  >> 4;
//            fract =  over8
//            ?  ( ((fractionaldivider * 8 + 50) / 100) & static_cast<uint8_t>(0x07) )
//            :  ( ((fractionaldivider * 16 + 50) / 100) & static_cast<uint8_t>(0x0F) );
//            reg_value = value;
//         }
//         return result;
      }

      template <typename Usart>
      inline bool get_baudrate_reg_values_with_error(int32_t baudrate,bool over8,uint32_t & reg_value, double & error_percent)
      {
         uint32_t mantissa =0;
         uint32_t fract=0;
         bool result = get_all_baudrate_values<Usart>(baudrate,over8,mantissa,fract,reg_value);
         if (result){
            double fraction = 0.0;
            if ( over8){
               fraction = fract / 8.0;
            }else{
               fraction = fract/ 16.f;
            }
            double const real_baudrate = quan::stm32::get_module_bus_frequency<Usart>() / (8.0 * (2.0 - ((over8)? 1.0:0.0)) * (mantissa + fraction) );
            //std::cout << "real baudrate = " << real_baudrate <<'\n';
            error_percent = ((1.0 - std::abs(real_baudrate / baudrate)) * 100);
            return true;
        }else{
            return false;
        }
      }
      
      template <typename Usart>
      inline bool get_best_baudrate_values(uint32_t baudrate, uint32_t & regval, bool & over8)
      {
         uint32_t reg_value_with_over8 = 0;
         double error_with_over8 = 0.0 ;
         bool const with_over8 = get_baudrate_reg_values_with_error<Usart>(baudrate,true,reg_value_with_over8,error_with_over8);
         uint32_t reg_value_without_over8 = 0;
         double error_without_over8 = 0.0 ;
         bool const without_over8 = get_baudrate_reg_values_with_error<Usart>(baudrate,false,reg_value_without_over8,error_without_over8);

         if ( ! ( with_over8 || without_over8) ){
            return false;
         }
         if ( with_over8  && ! without_over8  ){
             over8 = true;
             regval = reg_value_with_over8;
             return true;
         }
         if ( !with_over8  && without_over8 ){
             over8 = false;
             regval = reg_value_without_over8;  
             return true;
         }
         if ( error_without_over8  <=  error_with_over8 ){
             over8 = false;
             regval = reg_value_without_over8;  
         }else{
            over8 = true;
            regval = reg_value_with_over8; 
         }
         return true;
      }


      template <typename Usart>
      bool set_baud( uint32_t baudrate)
      {
         uint32_t regval = 0;
         bool   over8 = false;
         if ( get_best_baudrate_values<Usart>(baudrate,regval,over8)){
            Usart::get()->brr = regval;
            Usart::get()->cr1. template bb_putbit<15>(over8);
            return true;
         }else{
            return false;
         }
      }

}}}}}// quan::stm32::freertos::apm::detail


#endif // QUAN_STM32_FREERTOS_APM_SET_BAUD_HPP_INCLUDED
