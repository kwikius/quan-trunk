
CXXFLAGS = -I$(QUAN_ROOT) -O3 -std=c++11

CXX = /usr/local/bin/g++

all : box_example.exe  capacitor_time_curve.exe conversion_factor.exe \
	electronics_example.exe gravity.exe house_plan.exe ideal_gas_law.exe \
 	input.exe intdiv.exe johnson_noise.exe lab_example.exe \
	orig-demo.exe range_test.exe clcpp_response.exe

.PHONY : all

%.exe : %.o
	$(CXX) $(CXXFLAGS) -o $@  $<
	@echo .......................
	./$@
	@echo ....... OK ............

%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean :
	rm -rf *.o
	rm -rf *.exe








