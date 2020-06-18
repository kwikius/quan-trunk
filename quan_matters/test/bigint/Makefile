
# quan bigint test makefile
# builds the.o and .exe in the makefile dir
# should depend also on quan headers to trigger build? 

#  env  QUAN_ROOT is the parent of the quan directory
ifeq ($(QUAN_ROOT),)
#$(error ****************QUAN_ROOT not defined.QUAN_ROOT must be defined to path to your quan library installation ********)
QUAN_ROOT = ../../../
endif

TARGET      ?= test.exe
CXX         = g++-7
CXXFLAGS    = -std=c++14 -I${QUAN_ROOT}

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

ifneq ($(USE_EXCEPTIONS),True)
CXXFLAGS    += -fno-exceptions -DQUAN_NO_EXCEPTIONS
endif

ifneq ($(USE_RTTI),True)
CXXFLAGS    += -fno-rtti -DQUAN_NO_RTTI
endif

BIGINT_FILES  = assign assign_from_string bigint comp ctor ll_bigint 

LL_BIGINT_FILES = bitand_eq bitor_eq bitxor_eq compact compare div_eq div_mod dump_rep extend \
from_string_base gcd get_num_elements int_ctor invert is_negative ll_ctor minus_eq mod_eq \
move mul_eq negate plus_eq shl_eq shr_eq to_double to_string_base

TEST_FILES = and_test assignment compare ctor main div_eq_test minus_eq_test mul_eq_test \
or_test plus_eq_test plus_test shl_test shr_test string_input xor_test bigint_test1

# udt_value_type 

BIGINT_SRCS = $(patsubst %,$(QUAN_ROOT)/quan_matters/src/bigint/%.cpp,$(BIGINT_FILES))
BIGINT_OBJECTS = $(patsubst %,%_bigint_src.o,$(BIGINT_FILES))

LL_BIGINT_SRCS = $(patsubst %,$(QUAN_ROOT)/quan_matters/src/bigint/ll_bigint/%.cpp,$(LL_BIGINT_FILES))
LL_BIGINT_OBJECTS = $(patsubst %,%_ll_bigint_src.o,$(LL_BIGINT_FILES))

TEST_SRCS =  $(patsubst %,%.cpp,$(TEST_FILES)) 
TEST_OBJECTS = $(patsubst %,%.o,$(TEST_FILES))

OBJECTS  = $(TEST_OBJECTS) $(BIGINT_OBJECTS) $(LL_BIGINT_OBJECTS)

PHONY : all test clean

all : $(TARGET) 

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(CXXFLAGS) $(OBJECTS)

$(BIGINT_OBJECTS) : %_bigint_src.o : $(QUAN_ROOT)/quan_matters/src/bigint/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(LL_BIGINT_OBJECTS) : %_ll_bigint_src.o : $(QUAN_ROOT)/quan_matters/src/bigint/ll_bigint/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(TEST_OBJECTS) : %.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

test : $(TARGET)
	./$(TARGET)

clean :
	rm -f *.o ll_bigint/*.o
	rm -f $(TARGET)

