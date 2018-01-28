
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../../
endif

CXX         = g++-7
CXXFLAGS    = -std=c++14 -I${QUAN_ROOT}

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
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



 

