

.PHONY : all type_sequence rational_test test clean

all: type_sequence rational_test

test: type_sequence rational_test

USE_CONCEPTS_VALUE ?= True

type_sequence : 
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f type_sequence.mk test

rational_test:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f rational_test.mk test

clean:
	make -f type_sequence.mk clean
   



