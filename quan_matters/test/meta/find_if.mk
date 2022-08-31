
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../../
endif

MEMBER_FILES = find_if

TARGET      = $(patsubst %,%.exe,$(MEMBER_FILES))

CXX         = g++
CXXFLAGS    = -std=c++14 -I${QUAN_ROOT}

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

ifneq ($(USE_EXCEPTIONS),True)
CXXFLAGS    += -fno-exceptions -DQUAN_NO_EXCEPTIONS
endif

ifneq ($(USE_RTTI),True)
CXXFLAGS    += -fno-rtti -DQUAN_NO_RTTI
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

