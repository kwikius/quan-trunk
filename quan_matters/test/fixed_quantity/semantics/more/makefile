
# quan fixed_quantity test makefile
# builds the.o and .exe in the makefile dir
# should depend also on quan headers to trigger build? 

TARGET      ?= test.exe
CXX         ?= /usr/local/bin/g++
CXXFLAGS    ?= -std=c++11 -I${QUAN_ROOT}

TESTS = test \
 converting_assignment converting_constructor default_assignment minus_assignment \
 not numeric_value_access plus_assignment value_initialiser

SRCS =    $(patsubst %,%.cpp,$(TESTS))

OBJECTS = $(patsubst %,%.o,$(TESTS))

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(CXXFLAGS) $(OBJECTS)

#want rebuild of main function on header change 
test.o : test.hpp

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY : clean
.PHONY : test

test : $(TARGET)
	./$(TARGET)

clean :
	rm -f *.o
	rm -f $(TARGET)

