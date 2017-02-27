

.PHONY : all type_sequence rational_test find_if test clean

all: type_sequence rational_test find_if

test: type_sequence rational_test find_if

USE_CONCEPTS_VALUE ?= True

type_sequence : 
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f type_sequence.mk test

rational_test:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f rational_test.mk test

find_if :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f find_if.mk test

clean:
	make -f type_sequence.mk clean
	make -f rational_test.mk clean
	make -f find_if.mk clean
   



