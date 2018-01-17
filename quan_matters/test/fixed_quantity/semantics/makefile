
# quan fixed_quantity test makefile
# builds the.o and .exe in the makefile dir
# should depend also on quan headers to trigger build? 

#  env  QUAN_ROOT is the parent of the quan directory
ifeq ($(QUAN_ROOT),)
$(error ****************QUAN_ROOT not defined.QUAN_ROOT must be defined to path to your quan library installation ********)
endif

TARGET      ?= test.exe
ifeq ($(USE_CONCEPTS),True)
CXX         = g++-7
CXXFLAGS    = -std=c++14 -fconcepts -I${QUAN_ROOT}
else
CXX         = g++
CXXFLAGS    = -std=c++11 -I${QUAN_ROOT}
endif

MEMBER_FILES = abs anonymous_cast compare construction assignment conversion \
 dim_checks dimless_divide dimless_multiply divide divide_assignment incoh_corner_case \
 io_test minus minus_assignment multiply multiply_assignment plus plus_assignment \
 post_decrement post_increment pow pre_decrement pre_increment scalar_divide \
 scalar_multiply test_units_data test_units_data1 unary_minus unary_plus

# udt_value_type 

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

