
#include <quan_matters/test/test.hpp>

#include <quan/length.hpp>


namespace {

   void length_dimension_test()
   {
       typedef quan::of_length::mm::abstract_quantity::dimension dimension;
/*
  // attempt to not require this
       QUAN_CHECK((quan::is_model_of<quan::meta::TypeSequence_,dimension>::value))
*/
       QUAN_CHECK((dimension::num_elements == 1))

       typedef quan::meta::front<dimension>::type base_dimension1;

       QUAN_CHECK((std::is_same<base_dimension1,quan::meta::dim_length<1> >::value))
       
       typedef quan::meta::back<dimension>::type base_dimension2;

       QUAN_CHECK((std::is_same<base_dimension2,quan::meta::dim_length<1> >::value)) 

       typedef quan::meta::pop_front<dimension>::type empty_dimension;

       QUAN_CHECK((std::is_same<empty_dimension,quan::meta::dimension<> >::value))
       QUAN_CHECK((empty_dimension::num_elements == 0))
   }

   void get_base_dimension_from_length_dim_test()
   {
      //typedef quan::meta::length_unit::mm::dimension dimension;
      typedef quan::of_length::mm::abstract_quantity::dimension dimension;
      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::length
      >::type length_dim;

      QUAN_CHECK((std::is_same<length_dim,quan::meta::dim_length<1> >::value))
   }

   void get_base_dimension_from_synth_dim_test()
   {
      typedef quan::meta::dimension<
         quan::meta::dim_length<1>,
         quan::meta::dim_time<-1>, 
         quan::meta::dim_mass<2>, 
         quan::meta::dim_temperature<3>,
         quan::meta::dim_current_ratio<1,3>
      > dimension;

      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::length
      >::type length_dim;
      QUAN_CHECK((std::is_same<length_dim,quan::meta::dim_length<1> >::value))

      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::time
      >::type time_dim;
      QUAN_CHECK((std::is_same<time_dim,quan::meta::dim_time<-1> >::value))

      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::mass
      >::type mass_dim;
      QUAN_CHECK((std::is_same<mass_dim,quan::meta::dim_mass<2> >::value))

      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::temperature
      >::type temperature_dim;
      QUAN_CHECK((std::is_same<temperature_dim,quan::meta::dim_temperature<3> >::value))

      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::current
      >::type current_dim;
      QUAN_CHECK((std::is_same<current_dim,quan::meta::dim_current_ratio<1,3> >::value))

      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::substance
      >::type substance_dim;
      QUAN_CHECK((std::is_same<substance_dim,quan::meta::dim_substance<0> >::value))

      typedef quan::meta::detail::get_base_dimension<
         dimension,quan::meta::detail::base_dimension_id_t::intensity
      >::type intensity_dim;
      QUAN_CHECK((std::is_same<intensity_dim,quan::meta::dim_intensity<0> >::value))
   }

   void add_base_dim_test()
   {
      typedef quan::meta::dimension<
         quan::meta::dim_length<1>,
         quan::meta::dim_time<-1>, 
         quan::meta::dim_mass<2>, 
         quan::meta::dim_temperature<3>,
         quan::meta::dim_current_ratio<1,3>
      > lhs_dimension;

      typedef quan::meta::dimension< quan::meta::dim_mass<2>, quan::meta::dim_time<1> > rhs_dimension;

      typedef quan::meta::dimension<> empty_dimension;

      typedef quan::meta::detail::result_push_back_add_dims_base_dims<
         lhs_dimension,rhs_dimension, quan::meta::detail::base_dimension_id_t::mass,
         empty_dimension
      >::type result_dimension1;

      QUAN_CHECK((std::is_same<result_dimension1, quan::meta::dimension<quan::meta::dim_mass<4> > >::value))

      typedef quan::meta::detail::result_push_back_add_dims_base_dims<
         lhs_dimension,rhs_dimension,quan::meta::detail::base_dimension_id_t::time,
         result_dimension1
      >::type result_dimension2;

      // mass shouldnt have been added as result has zero extent
      // so no change
      QUAN_CHECK((std::is_same<result_dimension2, result_dimension1 >::value))

      typedef quan::meta::detail::result_push_back_subtract_dims_base_dims<
         lhs_dimension,rhs_dimension, 
         quan::meta::detail::base_dimension_id_t::time,
         result_dimension1
      >::type result_dimension3;

      QUAN_CHECK((std::is_same<result_dimension3, quan::meta::dimension<quan::meta::dim_mass<4>, quan::meta::dim_time<-2> > >::value))
   }
}

namespace {

   void add_dimensions_test()
   {
      typedef quan::meta::dimension<quan::meta::dim_length<1>, quan::meta::dim_time<-1>, quan::meta::dim_mass<2> > lhs_dimension;
      typedef quan::meta::dimension< quan::meta::dim_mass<2>, quan::meta::dim_time<1> > rhs_dimension;

      typedef quan::meta::detail::add_dimensions<lhs_dimension,rhs_dimension>::type result;

      typedef quan::meta::dimension<quan::meta::dim_length<1>,  quan::meta::dim_mass<4> > expected_result;

      QUAN_CHECK( (std::is_same<result,expected_result>::value ))

      typedef quan::meta::dimension<quan::meta::dim_length<-1>, quan::meta::dim_time<1>, quan::meta::dim_mass<-2> > inv_dimension;

      typedef quan::meta::detail::add_dimensions<lhs_dimension,inv_dimension>::type empty_result;
      QUAN_CHECK((std::is_same<empty_result, quan::meta::dimension<> >::value))

   }

   void subtract_dimensions_test()
   {
      typedef quan::meta::dimension<quan::meta::dim_length<1>, quan::meta::dim_time<-1>, quan::meta::dim_mass<2> ,quan::meta::dim_current<2> > lhs_dimension;
      typedef quan::meta::dimension< quan::meta::dim_mass<2>, quan::meta::dim_time<1>, quan::meta::dim_length<3>, quan::meta::dim_current<1> > rhs_dimension;

      typedef quan::meta::detail::subtract_dimensions<lhs_dimension,rhs_dimension>::type result;

      typedef quan::meta::dimension<quan::meta::dim_length<-2>, quan::meta::dim_time<-2>, quan::meta::dim_current<1> > expected_result;

      QUAN_CHECK( (std::is_same<result,expected_result>::value ))

      typedef quan::meta::detail::subtract_dimensions<lhs_dimension,lhs_dimension>::type empty_result;

      QUAN_CHECK( (std::is_same<empty_result,quan::meta::dimension<> >::value ))
   }

// TODO: dimension_multiply (etc) in user space ?
// mpusz_units uses Q*Q -> multiply(q::d,Q::d) which is add on exps

  void multiply_dimension_test()
  {
     typedef quan::meta::dimension<quan::meta::dim_length<1>, quan::meta::dim_time<-1>, quan::meta::dim_mass<2> ,quan::meta::dim_current<2> > dimension;
     typedef std::ratio<2> multiplier;

     typedef quan::meta::detail::multiply_dimension<dimension,multiplier>::type result;

     typedef quan::meta::dimension<quan::meta::dim_length<2>, quan::meta::dim_time<-2>, quan::meta::dim_mass<4> ,quan::meta::dim_current<4> > expected_result;

     QUAN_CHECK( (std::is_same<result,expected_result>::value ))

     typedef quan::meta::detail::multiply_dimension<dimension,std::ratio<0> >::type empty_result;
     QUAN_CHECK( (std::is_same<empty_result,quan::meta::dimension<> >::value ))
  }

  void divide_dimension_test()
  {
     typedef quan::meta::dimension<quan::meta::dim_length<2>, quan::meta::dim_time<-2>, quan::meta::dim_mass<4> ,quan::meta::dim_current<4> > dimension;

     typedef std::ratio<2> divisor;

     typedef quan::meta::detail::divide_dimension<dimension,divisor>::type result1;

     typedef quan::meta::dimension<quan::meta::dim_length<1>, quan::meta::dim_time<-1>, quan::meta::dim_mass<2> ,quan::meta::dim_current<2> > expected_result1;

     QUAN_CHECK( (std::is_same<result1,expected_result1>::value ))

     typedef quan::meta::detail::divide_dimension<result1,divisor>::type result2;

     typedef quan::meta::dimension<quan::meta::dim_length_ratio<1,2>, quan::meta::dim_time_ratio<-1,2>, quan::meta::dim_mass<1> ,quan::meta::dim_current<1> > expected_result2;

     QUAN_CHECK( (std::is_same<result2,expected_result2>::value ))
     
  }

  void negate_dimension_test()
  {
     typedef quan::meta::dimension<quan::meta::dim_length<2>, quan::meta::dim_time<-2>, quan::meta::dim_mass<4> ,quan::meta::dim_current<4> > dimension;

     typedef quan::meta::detail::negate_dimension<dimension>::type result1;

     typedef quan::meta::dimension<quan::meta::dim_length<-2>, quan::meta::dim_time<2>, quan::meta::dim_mass<-4> ,quan::meta::dim_current<-4> > expected_result1;
  
     QUAN_CHECK( (std::is_same<result1,expected_result1>::value ))

     typedef quan::meta::dimension<quan::meta::dim_length_ratio<1,2>, quan::meta::dim_time_ratio<-5,2>, quan::meta::dim_mass<1> ,quan::meta::dim_current<10> > dimension2;

     typedef quan::meta::detail::negate_dimension<dimension2>::type result2;

     typedef quan::meta::dimension<quan::meta::dim_length_ratio<-1,2>, quan::meta::dim_time_ratio<5,2>, quan::meta::dim_mass<-1> ,quan::meta::dim_current<-10> > expected_result2;

     QUAN_CHECK( (std::is_same<result2,expected_result2>::value ))

  }

  void compare_dimension_test()
  {
      typedef quan::meta::dimension<quan::meta::dim_length<2>, quan::meta::dim_time<-2>, quan::meta::dim_mass<4> ,quan::meta::dim_current<4> > dimension1;
      typedef quan::meta::dimension<quan::meta::dim_length_ratio<4,2>, quan::meta::dim_time<-2>, quan::meta::dim_mass<4> ,quan::meta::dim_current<4> > dimension2; 
      typedef quan::meta::dimension<quan::meta::dim_length_ratio<-1,2>, quan::meta::dim_time_ratio<5,2>, quan::meta::dim_mass<-1> ,quan::meta::dim_current<-10> > dimension3;

      typedef quan::meta::detail::are_equal_dimensions<dimension1, dimension2> are_equal12;
      QUAN_CHECK(are_equal12::value == true)
      typedef quan::meta::detail::are_not_equal_dimensions<dimension1, dimension2> are_not_equal12;
      QUAN_CHECK(are_not_equal12::value == false)

      typedef quan::meta::detail::are_equal_dimensions<dimension1, dimension3> are_equal13;
      QUAN_CHECK(are_equal13::value == false)
      typedef quan::meta::detail::are_not_equal_dimensions<dimension1, dimension3> are_not_equal13;
      QUAN_CHECK(are_not_equal13::value == true)
  }
}

void dimension_test()
{
   length_dimension_test();
   get_base_dimension_from_length_dim_test();
   get_base_dimension_from_synth_dim_test();
   add_base_dim_test();
   add_dimensions_test();
   subtract_dimensions_test();
   multiply_dimension_test();
   divide_dimension_test();
   negate_dimension_test();
   compare_dimension_test();
}

void base_dimension_ratio_test();

int errors = 0;
int main()
{
   base_dimension_ratio_test();
   dimension_test();

   QUAN_EPILOGUE
}


