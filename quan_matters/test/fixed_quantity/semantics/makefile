
# quan fixed_quantity test makefile
# builds the.o and .exe in the makefile dir
# should depend also on quan headers to trigger build?

#  env  QUAN_ROOT is the parent of the quan directory
ifeq ($(QUAN_ROOT),)
#$(error ****************QUAN_ROOT not defined.QUAN_ROOT must be defined to path to your quan library installation ********)
  export QUAN_ROOT = ../../../../
endif

TARGET      ?= test.exe
CXX         = g++
CXXFLAGS    = -std=c++14 -I${QUAN_ROOT} -fmax-errors=1

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

ifneq ($(USE_EXCEPTIONS),True)
CXXFLAGS    += -fno-exceptions -DQUAN_NO_EXCEPTIONS
endif

ifneq ($(USE_RTTI),True)
CXXFLAGS    += -fno-rtti -DQUAN_NO_RTTI
endif

MEMBER_FILES = abs anonymous_cast compare construction assignment conversion \
 converting_assignment converting_constructor default_assignment \
 dim_checks dimless_divide dimless_multiply divide divide_assignment fixed_quantity_concepts incoh_corner_case \
 io_test minus minus_assignment multiply multiply_assignment not numeric_value_access plus plus_assignment \
 post_decrement post_increment pow pre_decrement pre_increment scalar_divide \
 scalar_multiply test_units_data test_units_data1 unary_minus unary_plus value_initialiser \

SRCS =    $(patsubst %,%.cpp,$(MEMBER_FILES)) test.cpp

OBJECTS = $(patsubst %,%.o,$(MEMBER_FILES)) test.o

PHONY : all

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(CXXFLAGS) $(OBJECTS)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY : clean
.PHONY : test

test : $(TARGET)
	./$(TARGET)

clean :
	rm -f *.o
	rm -f $(TARGET)

