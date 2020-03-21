/*
Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses.
*/
#include "big_rational_test1.hpp"

namespace {

   void gcd_test()
   {
    std::cout << "big rat gcd test\n";
    typedef quan::big_rational rat;
    typedef quan::bigint bint;
    QUAN_CHECK(( bint::gcd(bint(1),bint(-1)).to_string()  == "1"))
    QUAN_CHECK(( bint::gcd(1,-1).to_string()  == "1"))
    QUAN_CHECK(( bint::gcd(1,-1)==1))
    QUAN_CHECK(( bint::gcd(bint("1"),bint("1")).to_string()  == "1"))
    QUAN_CHECK(( bint::gcd(bint("-1"),bint("-1")).to_string()  == "1"))
    QUAN_CHECK(( bint::gcd(bint("0"),bint("0")).to_string()  == "0"))
    QUAN_CHECK(( bint::gcd(bint("7"),bint("0")).to_string()  == "7"))
    QUAN_CHECK(( bint::gcd(bint("-7"),bint("0")).to_string()  == "7"))
    QUAN_CHECK(( bint::gcd(bint("0"),bint("9")).to_string()  == "9"))
    QUAN_CHECK(( bint::gcd(bint("0"),bint("-9")).to_string()  == "9"))
      
    QUAN_CHECK(( bint::gcd(bint("42"),bint("30")).to_string()  == "6"))
    QUAN_CHECK(( bint::gcd(bint("6"),bint("-9")).to_string()  == "3"))
    QUAN_CHECK(( bint::gcd(bint("-10"),bint("-10")).to_string()  == "10"))
    QUAN_CHECK(( bint::gcd(bint("-100000000"),bint("-10000")).to_string()  == "10000"))

    QUAN_CHECK(( bint::gcd(bint("-250"),bint("-100")).to_string()  == "50"))

   }

   void init_test()
   {
      std::cout << "big rat init test\n";
      typedef quan::big_rational rat;
      typedef quan::bigint bint;
      rat v1("2","-10");
      QUAN_CHECK(( v1.nume().to_string() == "-1"))
      QUAN_CHECK(( v1.denom().to_string() == "5"))

      rat v2("120000000000000000000000000000","500");

      QUAN_CHECK(( v2.nume().to_string()== "240000000000000000000000000" ))
      QUAN_CHECK(( v2.denom().to_string()== "1" ))
      QUAN_CHECK(( v2.denom().eq_one()))


      rat v3("120000000000000000000000000000","501");
      QUAN_CHECK(( bint::gcd(bint("120000000000000000000000000000"),bint("501")).to_string() == "3" ))

      QUAN_CHECK(( v3.nume().to_string()== "40000000000000000000000000000" ))
      QUAN_CHECK(( v3.denom().to_string()== "167" ))
      
   }
   void add_test()
   {
      std::cout << "big rat add test\n"; 
      
      typedef quan::big_rational rat;
      typedef quan::bigint bint;

      rat v1("1","99");
      v1 += v1;
      QUAN_CHECK(( v1.nume().to_string() == "2"))
      QUAN_CHECK(( v1.denom().to_string() == "99"))

      rat v2("1","1");
      v1 += v2;

    // // std::cout << v2.nume().to_string() <<'\n';
    ////  std::cout << v2.denom().to_string() <<'\n';

      QUAN_CHECK(( v1.nume().to_string() == "101"))
      QUAN_CHECK(( v1.denom().to_string() == "99"))

      rat test(v1);
      QUAN_CHECK(test==v1)

      rat v3("1","-1");
      v1 += v3;
      QUAN_CHECK(( v1.nume().to_string() == "2"))
      QUAN_CHECK(( v1.denom().to_string() == "99"))

      QUAN_CHECK(( !v1.is_integral() ));

      rat v4("-2","99");
      v1 += v4;
      QUAN_CHECK(( v1.nume().to_string() == "0"))
      QUAN_CHECK(( v1.denom().to_string() == "1"))
      QUAN_CHECK(( v1.is_integral() ));
      QUAN_CHECK(( v1.eq_zero() ));  
      
      rat v5 =  rat("1","2") + rat(3,4);
      QUAN_CHECK(( v5.nume().to_string() == "5"))
      QUAN_CHECK(( v5.denom().to_string() == "4"))
      QUAN_CHECK(( v5.is_integral() == false));
      QUAN_CHECK(( v5.eq_zero() == false ));  
       
   }
   void minus_test()
   {
      std::cout << "big rat minus test\n"; 
      
      typedef quan::big_rational rat;
      typedef quan::bigint bint;

      rat v1(1,2);
      rat v2(2,3);
      rat r = v1 - v2;

      QUAN_CHECK(r == rat(-1,6))

      v1 -= v2;
      QUAN_CHECK( v1 == r)

      v1 -= v1;
      QUAN_CHECK( v1 == bint(0))
      QUAN_CHECK(v2 - v2 == bint(0))
      
   }


   void mul_test()
   {
      std::cout << "big rat mul test\n"; 
      
      typedef quan::big_rational rat;
      typedef quan::bigint bint;

      rat v1("1","100");
      v1 *= v1;
      QUAN_CHECK(( v1.nume().to_string() == "1"))
      QUAN_CHECK(( v1.denom().to_string() == "10000"))

      rat v2 = v1 * v1;
      QUAN_CHECK(( v2.nume().to_string() == "1"))
      QUAN_CHECK(( v2.denom().to_string() == "100000000"))

      rat v3("1000000000000","-3");

      v3 *= v2;
     // std::cout << v3.nume().to_string() <<'\n';
      QUAN_CHECK(( v3.nume().to_string() == "-10000"))
      QUAN_CHECK(( v3.denom().to_string() == "3"))

      v3 *= rat("-1","-1");
      QUAN_CHECK(( v3.nume().to_string() == "-10000"))
      QUAN_CHECK(( v3.denom().to_string() == "3"))

      v3 *= rat("-1","2");
      QUAN_CHECK(( v3.nume().to_string() == "5000"))
      QUAN_CHECK(( v3.denom().to_string() == "3"))
   }

   void div_test()
   {
       std::cout << "big rat mul test\n"; 
       typedef quan::big_rational rat;
       typedef quan::bigint bint;
      
      rat v1("1","100");
      v1 /= v1;
      QUAN_CHECK(v1 == rat("1"))

      v1 /= rat("1","300");

      QUAN_CHECK(v1==rat("300"))

      rat v2("-1","300");

      v2 /= v1;

      QUAN_CHECK(v2 == rat("-1","90000"))
   }
   void relational_test()
   {
      
   }
}

namespace quan{ namespace test{

   void big_rational_test1()
   {

#if ! defined QUAN_NO_EXCEPTIONS 
      try{
#endif
         typedef quan::big_rational rat;
         rat v1("2","4");
       //  std::cout << v1.nume().to_string() << "\n";
         quan::bigint b1 = v1.nume();
       //  std::cout << b1.to_string() <<'\n';
       //  std::cout << v1.denom().to_string() << "\n";
         QUAN_CHECK(( v1 == rat("1","2") ))  
         QUAN_CHECK(( v1 != rat("1","1") ))  

         QUAN_CHECK((v1.nume().to_string() == "1"))
         QUAN_CHECK((v1.denom().to_string() == "2"))

         rat v2("2","1");
         QUAN_CHECK((v2.nume().to_string() == "2"))
         QUAN_CHECK((v2.denom().to_string() == "1"))
         
         v1 *= v2;
         QUAN_CHECK(( v1 == rat("1") ))

         std::string ten = "10";
         QUAN_CHECK(( v1 != rat("1",ten) ))
         
         v1 /= rat("2","1");
         QUAN_CHECK(( v1 == rat("1","2") )) 

         gcd_test();
         init_test();
         add_test();
         minus_test();
         mul_test();
         div_test();
#if ! defined QUAN_NO_EXCEPTIONS 
      }
      catch (std::exception & e){
         std::cout << e.what() <<'\n';
      }
#endif
   }

}}
