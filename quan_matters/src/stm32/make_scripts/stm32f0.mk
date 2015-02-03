
# specific for stm32f0

INCLUDES = /opt/stm32f0/STM32F0xx_StdPeriph_Lib_V1.1.0/Libraries/CMSIS/Include \
/opt/stm32f0/STM32F0xx_StdPeriph_Lib_V1.1.0/Libraries/CMSIS/Device/ST/STM32F0xx/Include

INIT_LIB_PREFIX = $(TOOLCHAIN_PREFIX)/lib/gcc/arm-none-eabi/$(TOOLCHAIN_GCC_VERSION)/armv6-m/

DEFINES = QUAN_STM32F0 QUAN_STM32_SUBFAMILY_05X
STM32F0_STARTUP = startupf0.s
STM32F0_LINKER_SCRIPT = stm32f0.ld
STM32F0_SYSTEM_INIT = system_initf0.cpp
PROCESSOR_FLAGS = -mcpu=cortex-m0 -mthumb -mfloat-abi=soft
