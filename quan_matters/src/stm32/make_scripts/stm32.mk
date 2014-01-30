# requires QUAN_INCLUDE_PATH - path to quan lib
# requires TARGET_PROCESSOR either STM32F4 or STM32F0
# OPTIMISATION_LEVEL defaults to Os

ifeq ($(QUAN_INCLUDE_PATH), )
$(error "QUAN_INCLUDE_PATH must be defined to the path to the quan library")
endif

ifeq ($(OPTIMISATION_LEVEL), )
OPTIMISATION_LEVEL = Os
endif

ifeq ( $(CFLAG_EXTRAS), )
CFLAG_EXTRAS = -fno-math-errno
endif

#required for Ubuntu 12.x placid as system headers have been put in strange places
# these have beeen defined to thos in my bash .profile

CPLUS_INCLUDE_PATH=
C_INCLUDE_PATH=
LIBRARY_PATH=
TOOLCHAIN_PREFIX =/opt/gcc-arm-none-eabi-4_7-2013q2/
TOOLCHAIN_GCC_VERSION = 4.7.4

CC      = $(TOOLCHAIN_PREFIX)bin/arm-none-eabi-g++
CC1     = $(TOOLCHAIN_PREFIX)bin/arm-none-eabi-gcc
LD      = $(TOOLCHAIN_PREFIX)bin/arm-none-eabi-g++
CP      = $(TOOLCHAIN_PREFIX)bin/arm-none-eabi-objcopy
OD      = $(TOOLCHAIN_PREFIX)bin/arm-none-eabi-objdump
  
MAKE_SCRIPTS_PATH = $(QUAN_INCLUDE_PATH)/quan_matters/src/stm32/make_scripts

ifeq ($(TARGET_PROCESSOR), STM32F4)
include  $(MAKE_SCRIPTS_PATH)/stm32f4.mk
else
ifeq ($(TARGET_PROCESSOR), STM32F0)
include $(MAKE_SCRIPTS_PATH)/stm32f0.mk
else
$(error no target processor defined)
endif
endif

INIT_LIBS = $(INIT_LIB_PREFIX)crti.o $(INIT_LIB_PREFIX)crtn.o

INCLUDES += $(QUAN_INCLUDE_PATH)

INCLUDE_ARGS = $(patsubst %,-I%,$(INCLUDES))

DEFINES += HSE_VALUE=8000000

DEFINE_ARGS = $(patsubst %,-D%,$(DEFINES))

# for float printf format etc
# CFLAG_EXTRAS += -Wl,-u,vsprintf -lm

CFLAGS  = -std=c++11 -fno-rtti -fno-exceptions -c -g -$(OPTIMISATION_LEVEL) $(DEFINE_ARGS) $(INCLUDE_ARGS) \
  $(PROCESSOR_FLAGS) $(CFLAG_EXTRAS)

LFLAGS  = -T$(MAKE_SCRIPTS_PATH)/$(LINKER_SCRIPT) -$(OPTIMISATION_LEVEL) -nostartfiles -nodefaultlibs \
 $(PROCESSOR_FLAGS) $(INIT_LIBS) --specs=nano.specs $(CFLAG_EXTRAS)

CPFLAGS = -Obinary
ODFLAGS = -d

all: test

objects = $(local_objects) startup.o system_init.o

clean:
	-rm -rf *.o *.elf *.bin *.lst

test: main.elf
	@ echo "...copying"
	$(CP) $(CPFLAGS) main.elf main.bin
	$(OD) $(ODFLAGS) main.elf > main.lst

main.elf: $(objects) 
	@ echo "..linking"
	$(LD) $(LFLAGS) -o main.elf $(objects)

$(local_objects): %.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@

system_init.o : $(MAKE_SCRIPTS_PATH)/$(SYSTEM_INIT)
	$(CC) $(CFLAGS) -o system_init.o $(MAKE_SCRIPTS_PATH)/$(SYSTEM_INIT)

startup.o: $(MAKE_SCRIPTS_PATH)/$(STARTUP)
	$(CC) $(CFLAGS) -o startup.o $(MAKE_SCRIPTS_PATH)/$(STARTUP) 

upload : test
	st-flash write main.bin 0x8000000
