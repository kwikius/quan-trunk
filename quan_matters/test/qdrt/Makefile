#  env  QUAN_ROOT is the parent of the quan directory
ifeq ($(QUAN_ROOT),)
$(error ****************QUAN_ROOT not defined.QUAN_ROOT must be defined to path to your quan library installation ********)
endif

TARGET      ?= test.exe
CXX         = g++-7
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

MEMBER_FILES = qdrt

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
