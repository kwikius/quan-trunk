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
MetaDir                       = quan_matters/test/meta/
ConversionDir                 = quan_matters/test/conversion/
BigintDir                     = quan_matters/test/bigint/

USE_CONCEPTS_VALUE = True

.PHONY: fixed_quantity_semantics_test angle_test three_d_test two_d_test examples qdrt meta conversion bigint

all: fixed_quantity_semantics_test angle_test three_d_test two_d_test examples qdrt meta conversion bigint

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

meta:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(MetaDir) test   

conversion:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(ConversionDir) test 

bigint:
	make USE_CONCEPTS=$(USE_CONCEPTS_VALUE) -C $(BigintDir) test 

clean: 
	make -C $(FixedQuantitySemanticsTestDir) clean
	make -C $(AngleTestDir) clean
	make -C $(ThreedVectTestDir) clean
	make -C $(TwodVectTestDir) clean
	make -C $(ExamplesDir) clean
	make -C $(QDRTDir) clean
	make -C $(MetaDir) clean
	make -C $(ConversionDir) clean
	make -C $(BigintDir) clean
