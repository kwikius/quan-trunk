
# quan bigint test makefile
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
CXXFLAGS    = -std=c++14 -I${QUAN_ROOT}
endif

TEST_FILES = test static_value static_monoid fold inner_product matrix sequence

TEST_SRCS =  $(patsubst %,%.cpp,$(TEST_FILES)) 
TEST_OBJECTS = $(patsubst %,%.o,$(TEST_FILES))

OBJECTS  = $(TEST_OBJECTS)

PHONY : all test clean

all : $(TARGET) 

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(CXXFLAGS) $(OBJECTS)

$(TEST_OBJECTS) : %.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

test : $(TARGET)
	./$(TARGET)

clean :
	rm -f *.o
	rm -f $(TARGET)

