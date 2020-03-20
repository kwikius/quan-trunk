

.PHONY : all type_sequence rational_test find_if concepts_for_each fold test clean dimension

all: type_sequence rational_test find_if concepts_for_each fold dimension

test: type_sequence rational_test find_if concepts_for_each fold dimension


ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

ifneq ($(USE_EXCEPTIONS),True)
CXXFLAGS    += -fno-exceptions -DQUAN_NO_EXCEPTIONS
endif

ifneq ($(USE_RTTI),True)
CXXFLAGS    += -fno-rtti -DQUAN_NO_RTTI
endif

type_sequence : 
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) USE_EXCEPTIONS=$(USE_EXCEPTIONS_VALUE) USE_RTTI=$(USE_RTTI_VALUE) -f type_sequence.mk test

rational_test:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) USE_EXCEPTIONS=$(USE_EXCEPTIONS_VALUE) USE_RTTI=$(USE_RTTI_VALUE) -f rational_test.mk test

find_if :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) USE_EXCEPTIONS=$(USE_EXCEPTIONS_VALUE) USE_RTTI=$(USE_RTTI_VALUE) -f find_if.mk test

concepts_for_each :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) USE_EXCEPTIONS=$(USE_EXCEPTIONS_VALUE) USE_RTTI=$(USE_RTTI_VALUE) -f for_each.mk test

fold :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) USE_EXCEPTIONS=$(USE_EXCEPTIONS_VALUE) USE_RTTI=$(USE_RTTI_VALUE) -f fold.mk test

dimension :
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) USE_EXCEPTIONS=$(USE_EXCEPTIONS_VALUE) USE_RTTI=$(USE_RTTI_VALUE) -f dimension.mk test

clean:
	make -f type_sequence.mk clean
	make -f rational_test.mk clean
	make -f find_if.mk clean
	make -f for_each.mk clean 
	make -f fold.mk clean 
	make -f dimension.mk clean
