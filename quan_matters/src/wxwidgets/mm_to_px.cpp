namespace {
quan::two_d::vect<int> vect_mm_to_px(quan::two_d::vect<quan::length::mm> const & in)
{
  wxSize dsmm = wxGetDisplaySizeMM();
  wxSize dspx = wxGetDisplaySize();
  quan::two_d::vect<quan::reciprocal_length::per_mm> 
  mm_to_px{dspx.x/quan::length::mm{dsmm.x},dspx.y/quan::length::mm{dsmm.y}};
  quan::two_d::vect<int> result{
     quan::arithmetic_convert<int>(in.x * mm_to_px.x)
   , quan::arithmetic_convert<int>(in.y * mm_to_px.y)
  };
   return result;
}
}