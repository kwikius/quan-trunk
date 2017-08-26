



ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../../
endif

ifeq ($(USE_CONCEPTS),True)
CXX         = g++-6
CXXFLAGS    = -std=c++14 -fconcepts -I${QUAN_ROOT}
else
CXX         ?= g++
CXXFLAGS    ?= -std=c++11 -I${QUAN_ROOT}
endif

objs = aerofoil_example.o main.o test_main.o

.PHONY : all test clean

all : dom.exe

dom.exe : ${objs}
	$(CXX) $(CXXFLAGS) -o $@  ${objs}

${objs} : %.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o
	rm -rf *.exe



 

