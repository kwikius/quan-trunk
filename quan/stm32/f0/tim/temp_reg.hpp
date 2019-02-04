#ifndef QUAN_STM32F0_TIM_TEMP_REG_HPP_INCLUDED
#define QUAN_STM32F0_TIM_TEMP_REG_HPP_INCLUDED

#if ! defined  QUAN_STM32F0
#error dont include directly
#endif

#include <cstdint>

namespace quan{ namespace stm32{ namespace tim {

   union cr1_t{
      struct {
         bool    cen  : 1;
         bool    udis : 1;
         bool    urs  : 1;
         bool    opm  : 1;
         bool    dir  : 1;
         uint8_t cms  : 2;
         bool    arpe : 1;
         uint8_t ckd  : 2;
         uint8_t      : 6;
      } ;
      uint16_t value;
      cr1_t(uint16_t val) :value{val}{}
   };

   union cr2_t{
      struct {
         bool    ccpc  : 1; // only TIM1 and 8
         bool          : 1;
         bool    ccus  : 1;
         bool    ccds  : 1;
         uint8_t mms   : 3;
         bool    ti1s  : 1;
         bool    ois1  : 1;
         bool    ois1n : 1;
         bool    ois2  : 1;
         bool    ois2n : 1;
         bool    ois3  : 1;
         bool    ois3n : 1;
         bool    ois4  : 1;
         bool          : 1;  
      } ;
      uint16_t value;
      cr2_t(uint16_t val) :value{val}{}
   };

   union smcr_t{
      struct {
         uint8_t  sms   : 3;
         bool     occs  : 1;
         uint8_t  ts    : 3;
         bool     msm   : 1;
         uint8_t  etf   : 4;
         uint8_t  etps  : 2; 
         bool     ece   : 1; 
         bool     etp   : 1; 
      } ;
      uint16_t value;
      smcr_t(uint16_t val) :value{val}{}
   };

    union dier_t{
       struct {
         bool uie   : 1;
         bool cc1ie : 1;
         bool cc2ie : 1;
         bool cc3ie : 1;
         bool cc4ie : 1;
         bool comie : 1;
         bool tie   : 1;
         bool bie   : 1;
         bool ude   : 1;
         bool cc1de : 1;
         bool cc2de : 1;
         bool cc3de : 1;
         bool cc4de : 1;
         bool comde : 1;
         bool tde   : 1;
         bool       : 1;
       } ;
      uint16_t value;
      dier_t(uint16_t val) :value{val}{}
   };

   union sr_t{
       struct {
         bool  uif   : 1;
         bool  cc1if : 1;
         bool  cc2if : 1;
         bool  cc3if : 1;
         bool  cc4if : 1;
         bool  comif : 1;
         bool  tif   : 1;
         bool  bif   : 1;
         bool        : 1;
         bool  cc1of : 1;
         bool  cc2of : 1;
         bool  cc3of : 1;
         bool  cc4of : 1;
         bool        : 3;
      } ;
      uint16_t value;
      sr_t(uint16_t val) :value{val}{}
   };

   union egr_t {
      struct {
         bool  ug  : 1;
         bool cc1g : 1;
         bool cc2g : 1;
         bool cc3g : 1;
         bool cc4g : 1;
         bool comg : 1;
         bool tg   : 1;
         bool bg   : 1;
         uint8_t   : 8;
      } ;
      uint16_t value;
      egr_t(uint16_t val) :value{val}{}
   };

   union ccmr1_t {
      struct {
         uint8_t cc1s : 2;
         uint8_t      : 6;
         uint8_t cc2s : 2;
         uint8_t      : 6;
      };
      struct {
         uint8_t        : 2;
         bool    oc1fe  : 1;
         bool    oc1pe  : 1;
         uint8_t oc1m   : 3;
         bool    oc1ce  : 1;
         uint8_t        : 2;
         bool    oc2fe  : 1;
         bool    oc2pe  : 1;
         uint8_t oc2m   : 3;
         bool    oc2ce  : 1;
      };
      struct {
         uint8_t        : 2;
         uint8_t ic1psc : 2;
         uint8_t ic1f   : 4;
         uint8_t        : 2;
         uint8_t ic2psc : 2;
         uint8_t ic2f   : 4;
      };
      uint16_t value;
      ccmr1_t(uint16_t val) :value{val}{}
   };

   union ccmr2_t {
      struct {
         uint8_t cc3s : 2;
         uint8_t      : 6;
         uint8_t cc4s : 2;
         uint8_t      : 6;
      };
      struct {
         uint8_t        : 2;
         bool    oc3fe  : 1;
         bool    oc3pe  : 1;
         uint8_t oc3m   : 3;
         bool    oc3ce  : 1;
         uint8_t        : 2;
         bool    oc4fe  : 1;
         bool    oc4pe  : 1;
         uint8_t oc4m   : 3;
         bool    oc4ce  : 1;
     } ;
     struct {
         uint8_t        : 2;
         uint8_t ic3psc : 2;
         uint8_t ic3f   : 4;
         uint8_t        : 2;
         uint8_t ic4psc : 2;
         uint8_t ic4f   : 4;
    };
      uint16_t value;
      ccmr2_t(uint16_t val) :value{val}{}
   };

   union ccer_t{
      struct {
         bool cc1e  : 1;
         bool cc1p  : 1;
         bool cc1ne : 1;
         bool cc1np : 1;
         bool cc2e  : 1;
         bool cc2p  : 1;
         bool cc2ne : 1;
         bool cc2np : 1;
         bool cc3e  : 1;
         bool cc3p  : 1;
         bool cc3ne : 1;
         bool cc3np : 1;
         bool cc4e  : 1;
         bool cc4p  : 1;
         bool       : 2;
      } ;
      uint16_t value;
      ccer_t(uint16_t val) :value{val}{}
   };

   union bdtr_t {
      struct {
         uint8_t dtg   : 8;
         uint8_t lock  : 2;
         bool ossi     : 1;
         bool ossr     : 1;
         bool bke      : 1;
         bool bkp      : 1;
         bool aoe      : 1;
         bool moe      : 1;
      } ;
      uint16_t value;
      bdtr_t(uint16_t val) :value{val}{}
    };

}}}


#endif // QUAN_STM32F0_TIM_TEMP_REG_HPP_INCLUDED
