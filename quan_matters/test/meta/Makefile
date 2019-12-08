

.PHONY : all type_sequence rational_test find_if concepts_for_each fold test clean dimension

all: type_sequence rational_test find_if concepts_for_each fold dimension

test: type_sequence rational_test find_if concepts_for_each fold dimension

USE_CONCEPTS_VALUE ?= True

type_sequence : 
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f type_sequence.mk test

rational_test:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f rational_test.mk test

find_if :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f find_if.mk test

concepts_for_each :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f for_each.mk test

fold :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f fold.mk test

dimension :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -f dimension.mk test

clean:
	make -f type_sequence.mk clean
	make -f rational_test.mk clean
	make -f find_if.mk clean
	make -f for_each.mk clean 
	make -f fold.mk clean 
	make -f dimension.mk clean
