#

FixedQuantitySemanticsTestDir = quan_matters/test/fixed_quantity/semantics/
AngleTestDir = quan_matters/test/angle

all: fixed_quantity_semantics_test \
 angle_test

fixed_quantity_semantics_test: 
	make -C $(FixedQuantitySemanticsTestDir) test


angle_test:
	make -C $(AngleTestDir) test


clean: 
	make -C $(FixedQuantitySemanticsTestDir) clean
	make -C $(AngleTestDir) clean

	

