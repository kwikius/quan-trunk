#

TestDir = quan_matters/test/fixed_quantity/semantics/

test: 
	make -C $(TestDir)

clean: 
	make -C  $(TestDir) clean

