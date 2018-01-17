#  env  QUAN_ROOT is the parent of the quan directory
ifeq ($(QUAN_ROOT),)
$(error ****************QUAN_ROOT not defined.QUAN_ROOT must be defined to path to your quan library installation ********)
endif

TARGET      ?= test.exe

ifeq ($(USE_CONCEPTS),True)
CXX         = g++-7
CXXFLAGS    = -std=c++14 -fconcepts -I${QUAN_ROOT}
else
CXX         ?= /usr/local/bin/g++
CXXFLAGS    ?= -std=c++11 -I${QUAN_ROOT}
endif

MEMBER_FILES = float_to_ascii

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
