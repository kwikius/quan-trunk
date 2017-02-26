#

ifeq ($(QUAN_ROOT),)
export QUAN_ROOT = $(CURDIR)
endif

FixedQuantitySemanticsTestDir = quan_matters/test/fixed_quantity/semantics/
AngleTestDir                  = quan_matters/test/angle/
ThreedVectTestDir             = quan_matters/test/three_d/
TwodVectTestDir               = quan_matters/test/two_d/
ExamplesDir                   = quan_matters/examples/
QDRTDir                       = quan_matters/test/qdrt/

USE_CONCEPTS_VALUE = True

.PHONY: fixed_quantity_semantics_test angle_test three_d_test two_d_test examples qdrt

all: fixed_quantity_semantics_test angle_test three_d_test two_d_test examples qdrt

fixed_quantity_semantics_test: 
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(FixedQuantitySemanticsTestDir) test

angle_test:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(AngleTestDir) test

three_d_test:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(ThreedVectTestDir) test

two_d_test:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(TwodVectTestDir) test	

examples:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(ExamplesDir) test

qdrt:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(QDRTDir) test
	
clean: 
	make -C $(FixedQuantitySemanticsTestDir) clean
	make -C $(AngleTestDir) clean
	make -C $(ThreedVectTestDir) clean
	make -C $(TwodVectTestDir) clean
	make -C $(ExamplesDir) clean
	make -C $(QDRTDir) clean