
# quan fixed_quantity test makefile
# builds the.o and .exe in the makefile dir
# should depend also on quan headers to trigger build? 

#  env  QUAN_ROOT is the parent of the quan directory
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../../
endif

TARGET      ?= test.exe
CXX         = g++-7
CXXFLAGS    = -std=c++14 -I${QUAN_ROOT}

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

MEMBER_FILES = vect_test complex_test

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

