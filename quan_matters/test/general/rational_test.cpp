


#include <quan_matters/test/test.hpp>
#include <quan/rational.hpp>

namespace quan{

   template <typename TL,typename TR>
   concept same_as = std::is_same_v<TL,TR>;

   template <typename T>
   concept in_rational = same_as<T,quan::rational<typename T::int_type> >;

   template <typename T>
   std::ostream & operator << (std::ostream & os, quan::asm_::extended_reg<T> const & v)
   {
      return os  << " hi = " << static_cast<int>(v.hi) << ",lo = " << static_cast<int>(v.lo) << " sign = " << v.sign << '\n';
   }

   template <in_rational R>
   std::ostream & operator << (std::ostream & os, R const & v)
   {
      typedef typename std::common_type<typename R::int_type,int>::type int_type;
      return os << static_cast<int_type>(v.nume()) << " / " << static_cast<int_type>(v.denom()) ;
   }
}
// test nttp
template <typename M, typename E>
struct cf{
    constexpr cf( M m, E e ):multiplier{m}, exponent{e} {}
    void show(const char * name )const { std::cout << name << " = " << multiplier << " * 10^" << exponent << '\n';}
    M multiplier;
    E exponent;
};

template <auto... V>
struct M{

};

int main()
{
   
   quan::rational<signed char> constexpr v1(15,11);

   quan::rational<signed char> constexpr v2(3,5);

  // int t = v1;

   auto constexpr r = v1 * v2;

   cf constexpr x = {v1*v2,v1};

   std::cout << "r s = " << r << '\n';
   x.show("r");


//   M<v1,2,1,v2,v1*v2> y;
//
//   int i = y;
}





