
ifeq ($(QUAN_ROOT),)
QUAN_ROOT = ../../
endif

CXX         = g++-7
CXXFLAGS    = -std=c++14 -I${QUAN_ROOT}

ifeq ($(USE_CONCEPTS),True)
CXXFLAGS    += -fconcepts
endif

DomDir = dom/
FusionDir = fusion/

.PHONY : all test clean dom fusion

all : test

test : angles1.exe c_test.exe feet_and_inches.exe  input.exe noise_voltage_density.exe  range_test.exe \
angles2.exe custom_def_unit.exe flexible_two_arg_cmath_functions1.exe  intdiv.exe  orig-demo.exe simple_value_w_exp_demo.exe \
box_example.exe  johnson_noise.exe  SI_units_syntax.exe \
capacitor_time_curve.exe  defining_own_unit.exe lab_example.exe synthetic_dims.exe \
gravity.exe  particle.exe windturbine.exe clcpp_response.exe doc_output_demo.exe house_plan.exe  \
conversion_factor.exe electronics_example.exe ideal_gas_law.exe rad_per_s.exe dom fusion conversion_factor_working.exe

%.exe : %.o
	$(CXX) $(CXXFLAGS) -O3 -o $@  $<
	@echo .......................
	./$@
	@echo ....... OK ............

%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -O3 -c $<

dom:
	make USE_CONCEPTS=$(USE_CONCEPTS) -C $(DomDir) test

fusion:
	make USE_CONCEPTS=$(USE_CONCEPTS) -C $(FusionDir) test

clean :
	rm -rf *.o
	rm -rf *.exe
	make -C $(DomDir) clean
	make -C $(FusionDir) clean

