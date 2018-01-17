
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../../
endif

MEMBER_FILES = find_if

TARGET      = $(patsubst %,%.exe,$(MEMBER_FILES))

ifeq ($(USE_CONCEPTS),True)
CXX         = g++-7
CXXFLAGS    = -std=c++14 -fconcepts -I${QUAN_ROOT}
else
CXX         ?= g++
CXXFLAGS    ?= -std=c++11 -I${QUAN_ROOT}
endif

SRCS =    $(patsubst %,%.cpp,$(MEMBER_FILES)) 

OBJECTS = $(patsubst %,%.o,$(MEMBER_FILES)) 

.PHONY : all clean test

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(CXXFLAGS) $(OBJECTS)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

test : $(TARGET)
	./$(TARGET)

clean :
	rm -f *.o *.exe
	rm -f $(TARGET)

