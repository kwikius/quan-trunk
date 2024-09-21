
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = /home/andy/cpp/projects/quan-trunk
endif


TARGET      = libbigint.a
CXX         = g++
CXXFLAGS    = -std=c++11 -I${QUAN_ROOT}

AR = ar

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
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

OBJECTS  =  $(BIGINT_OBJECTS) $(LL_BIGINT_OBJECTS)

.PHONY : all clean

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(AR) cr $(TARGET) $(OBJECTS)

$(BIGINT_OBJECTS) : %_bigint_src.o : $(QUAN_ROOT)/quan_matters/src/bigint/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(LL_BIGINT_OBJECTS) : %_ll_bigint_src.o : $(QUAN_ROOT)/quan_matters/src/bigint/ll_bigint/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean :
	rm -f *.o ll_bigint/*.o
	rm -f $(TARGET)

