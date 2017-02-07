

include_directories = /home/andy/cpp/projects/quan-trunk

INCLUDES = $(patsubst %,-I%,$(include_directories))

.PHONY: all test clean

all : test.exe

test.exe : main.o
	g++ -o $@  $<

main.o : qdrt.cpp
	g++ -std=c++11 $(INCLUDES) -c $< -o $@

clean :
	rm -f *.o *.exe

test : test.exe
	./test.exe
