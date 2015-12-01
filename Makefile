#

TestDir = quan_matters/test/fixed_quantity/semantics/

test: 
	make -C $(TestDir) test

clean: 
	make -C  $(TestDir) clean

