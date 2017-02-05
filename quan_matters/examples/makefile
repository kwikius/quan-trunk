
ifeq ($(QUAN_ROOT),)
$(error ****************QUAN_ROOT not defined.QUAN_ROOT must be defined to path to your quan library installation ********)
endif

CXXFLAGS = -I$(QUAN_ROOT) -O3 -std=c++11

CXX = g++

.PHONY : all test clean

all : test

test : angles1.exe c_test.exe feet_and_inches.exe  input.exe noise_voltage_density.exe  range_test.exe \
angles2.exe custom_def_unit.exe flexible_two_arg_cmath_functions1.exe  intdiv.exe  orig-demo.exe simple_value_w_exp_demo.exe \
box_example.exe  johnson_noise.exe  SI_units_syntax.exe \
capacitor_time_curve.exe  defining_own_unit.exe lab_example.exe synthetic_dims.exe \
gravity.exe  particle.exe windturbine.exe clcpp_response.exe doc_output_demo.exe house_plan.exe  \
conversion_factor.exe electronics_example.exe ideal_gas_law.exe rad_per_s.exe

%.exe : %.o
	$(CXX) $(CXXFLAGS) -o $@  $<
	@echo .......................
	./$@
	@echo ....... OK ............

%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o
	rm -rf *.exe








