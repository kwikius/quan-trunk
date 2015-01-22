# specific flags for stm32f4

DEFINES += QUAN_STM32F4 
STM32F4_STARTUP = startupf4.s
STM32F4_LINKER_SCRIPT = stm32f4.ld
STM32F4_SYSTEM_INIT = system_initf4.cpp
PROCESSOR_FLAGS = -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -mfloat-abi=hard

INCLUDES = /opt/stm32f4/STM32F4xx_DSP_StdPeriph_Lib_V1.0.0/Libraries/CMSIS/Include \
/opt/stm32f4/STM32F4xx_DSP_StdPeriph_Lib_V1.0.0/Libraries/CMSIS/Device/ST/STM32F4xx/Include \
/opt/stm32f4/STM32F4xx_DSP_StdPeriph_Lib_V1.0.0/Libraries/STM32F4xx_StdPeriph_Driver/inc

INIT_LIB_PREFIX = $(TOOLCHAIN_PREFIX)/lib/gcc/arm-none-eabi/$(TOOLCHAIN_GCC_VERSION)/armv7e-m/fpu/


