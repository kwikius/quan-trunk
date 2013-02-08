#ifndef QUAN_STM32F4_DETAIL_GET_REG_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_GET_REG_HPP_INCLUDED

namespace quan{ namespace stm32f4{ namespace detail{

   template<typename Module,typename Member ,typename Where = void>
   struct get_reg;

}}}

  // works well to get ptr and offset in assembly
#define QUAN_STM32F4_GET_REG(Concept, PeriphReg)  \
   template<typename Module> \
   struct get_reg<   \
      Module,typename Module :: PeriphReg ## _type, \
      typename quan::where_< quan::is_model_of< Concept, Module > >::type \
   >{ \
         typename Module:: PeriphReg ## _type * operator()()const    \
       { return &Module::get() -> PeriphReg ;} \
   };

#endif // QUAN_STM32F4_DETAIL_GET_REG_HPP_INCLUDED
