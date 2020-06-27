
# quan bigint test makefile
# builds the.o and .exe in the makefile dir
# should depend also on quan headers to trigger build? 

#  env  QUAN_ROOT is the parent of the quan directory
#ifeq ($(QUAN_ROOT),)
#$(error ****************QUAN_ROOT not defined.QUAN_ROOT must be defined to path to your quan library installation ********)
#endif

QUAN_ROOT ?= ../../../../quan-trunk

TARGET      = test.exe
CXX         = g++-7
CXXFLAGS    = -std=c++14 -fmax-errors=1 -I${QUAN_ROOT} 

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

ifneq ($(USE_EXCEPTIONS),True)
CXXFLAGS    += -fno-exceptions -DQUAN_NO_EXCEPTIONS
endif

ifneq ($(USE_RTTI),True)
CXXFLAGS    += -fno-rtti -DQUAN_NO_RTTI
endif

TEST_FILES = main power_root vector_view_test gcd_test

TEST_SRCS =  $(patsubst %,%.cpp,$(TEST_FILES)) 
TEST_OBJECTS = $(patsubst %,%.o,$(TEST_FILES))

OBJECTS  = $(TEST_OBJECTS)

PHONY : all test concept_test 

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(CXXFLAGS) $(OBJECTS)

$(TEST_OBJECTS) : %.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

test : $(TARGET)
	./$(TARGET)

concept_test : CXXFLAGS += -fconcepts
concept_test : $(TARGET)
	./$(TARGET)

clean :
	rm -f *.o
	rm -f $(TARGET)

