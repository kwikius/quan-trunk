
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../../
endif

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

TARGET = dom.exe
objs = aerofoil_example.o main.o test_main.o

.PHONY : all test clean

all : $(TARGET)

$(TARGET) : ${objs}
	$(CXX) $(CXXFLAGS) -o $@  ${objs}

test: $(TARGET)
	./$(TARGET)

${objs} : %.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o
	rm -rf *.exe



 

