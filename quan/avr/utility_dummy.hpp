#ifndef QUAN_AVR_UTLITY_DUMMY_HPP_INCLUDED
#define QUAN_AVR_UTLITY_DUMMY_HPP_INCLUDED


namespace std{

  template<typename T1, typename T2>
  struct pair{
     pair(T1 const& t1, T2 const& t2): first(t1),second(t2){}
     T1 first;
     T2 second;
  };
}


#endif // QUAN_AVR_UTLITY_DUMMY_HPP_INCLUDED
