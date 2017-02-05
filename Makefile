#

ifeq ($(QUAN_ROOT),)
export QUAN_ROOT = $(CURDIR)
endif

FixedQuantitySemanticsTestDir = quan_matters/test/fixed_quantity/semantics/
AngleTestDir                  = quan_matters/test/angle/
ThreedVectTestDir             = quan_matters/test/three_d/
TwodVectTestDir               = quan_matters/test/two_d/
ExamplesDir                   = quan_matters/examples

.PHONY: fixed_quantity_semantics_test angle_test three_d_test two_d_test examples 

all: fixed_quantity_semantics_test angle_test three_d_test two_d_test examples

fixed_quantity_semantics_test: 
	make -C $(FixedQuantitySemanticsTestDir) test

angle_test:
	make -C $(AngleTestDir) test

three_d_test:
	make -C $(ThreedVectTestDir) test

two_d_test:
	make -C $(TwodVectTestDir) test	

examples:
	make -C $(ExamplesDir) test

clean: 
	make -C $(FixedQuantitySemanticsTestDir) clean
	make -C $(AngleTestDir) clean
	make -C $(ThreedVectTestDir) clean
	make -C $(TwodVectTestDir) clean
	make -C $(ExamplesDir) clean
