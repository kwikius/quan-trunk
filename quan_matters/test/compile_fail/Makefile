
all : main.exe

test : main.exe

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

ifneq ($(USE_EXCEPTIONS),True)
CXXFLAGS    += -fno-exceptions -DQUAN_NO_EXCEPTIONS
endif

ifneq ($(USE_RTTI),True)
CXXFLAGS    += -fno-rtti -DQUAN_NO_RTTI
endif

main.exe : compile_fail_test.o
	g++-7 -o main.exe  compile_fail_test.o
	echo ............................
	./main.exe
	echo ............................

compile_fail_test.o : compile_fail_test.cpp
	g++-7 -c  $(CXXFLAGS) compile_fail_test.cpp -I../../../ -o compile_fail_test.o

clean:
	-rm -rf *.o *.exe compile_fail_log.txt
