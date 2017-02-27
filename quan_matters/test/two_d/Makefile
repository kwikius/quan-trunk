
# quan fixed_quantity test makefile
# builds the.o and .exe in the makefile dir
# should depend also on quan headers to trigger build? 

#  env  QUAN_ROOT is the parent of the quan directory
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../../
endif

TARGET      ?= test.exe

ifeq ($(USE_CONCEPTS),True)
CXX         = g++-6
CXXFLAGS    = -std=c++14 -fconcepts -I${QUAN_ROOT}
else
CXX         ?= /usr/local/bin/g++
CXXFLAGS    ?= -std=c++11 -I${QUAN_ROOT}
endif

MEMBER_FILES = vect_test

# udt_value_type 

SRCS =    $(patsubst %,%.cpp,$(MEMBER_FILES)) 

OBJECTS = $(patsubst %,%.o,$(MEMBER_FILES)) 

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

