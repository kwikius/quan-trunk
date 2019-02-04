
#include <iostream>
#include <utility>

#include <quan_matters/test/test.hpp>
#include <quan/string.hpp>

void default_constructor()
{
   std::cout << "default ctor test\n";
   quan::string str;
   QUAN_CHECK(strlen(str.get()) == 0);
   std::cout << "~default ctor test\n";
   QUAN_CHECK(strcmp(str.get(), "")== 0);
}

void const_char_constructor()
{
   std::cout << "const char ctor test\n";
   quan::string str = "Hello World\n";

   QUAN_CHECK(strcmp(str.get(),"Hello World\n") == 0)
   std::cout << "~const char ctor test\n";
}

void r_value_constructor()
{
   std::cout << "r value ctor test\n";
   quan::string x { std::move(quan::string{"Hello again\n"}) };
   QUAN_CHECK(strcmp(x.get(),"Hello again\n") ==0)
   std::cout << "~r value ctor test\n";
}

void string_assignment()
{
   std::cout << "string assignment\n";
   quan::string a = "Hello";
   quan::string b = "Goodbye";
   quan::string c;
   c = b;
   QUAN_CHECK(strcmp(c.get(),"Goodbye") == 0);
   b = a;
   QUAN_CHECK(strcmp(b.get(),"Hello") == 0);
   a = c;
   QUAN_CHECK(strcmp(a.get(),"Goodbye") == 0);
   std::cout << "~string assignment\n";
}

void string_move_assignment()
{
   std::cout << "string move assignment\n";
   quan::string a = "Hello";
   quan::string b;
   b = std::move(quan::string{"What?"});
   QUAN_CHECK(strcmp(b.get(),"What?") == 0);
   a = std::move(quan::string{});
   QUAN_CHECK(strcmp(a.get(),"") == 0);
   std::cout << "~string move assignment\n";
}

void char_ptr_assignment()
{
   std::cout << "chr* assignment\n";
   quan::string a = "Hello";
   a = "Goodbye";
   QUAN_CHECK(strcmp(a.get(),"Goodbye") == 0);
   a = "";
   QUAN_CHECK(strcmp(a.get(),"") == 0);
}

void char_ptr_plus_assignment()
{
   quan::string a = "Hello";
   a += " and Goodbye";
   QUAN_CHECK(strcmp(a.get(),"Hello and Goodbye")==0);

   a += "";
   QUAN_CHECK(strcmp(a.get(),"Hello and Goodbye")==0);

   a = "";
   a += "";
   QUAN_CHECK(strcmp(a.get(),"")==0);
}



void char_plus_assignment()
{
   quan::string a = "abc";
   a += 'd';
   QUAN_CHECK(strcmp(a.get(),"abcd")==0);

   a += "";
   QUAN_CHECK(strcmp(a.get(),"abcd")==0);

   quan::string b ;
   b+= '+';
   QUAN_CHECK(strcmp(b.get(),"+")==0);
}

void string_plus_assignment()
{
   quan::string a = "Hello";
   quan::string const b = " and Goodbye";
   quan::string c;

   a += b;
   QUAN_CHECK(strcmp(a.get(),"Hello and Goodbye")==0);

   a += c;
   QUAN_CHECK(strcmp(a.get(),"Hello and Goodbye")==0);

   c += b;
   QUAN_CHECK(strcmp(c.get()," and Goodbye")==0);
}

void string_compare_test()
{
   quan::string a ="1234";
   QUAN_CHECK(a == a);
   quan::string b = "1234";
   quan::string const c = "";
   quan::string const d = "12345";
   QUAN_CHECK(a == b);
   QUAN_CHECK(c == c );
   QUAN_CHECK(!(a == d));
   QUAN_CHECK(a == "1234");
   QUAN_CHECK( "1234" == a);
   QUAN_CHECK(a != "");
   QUAN_CHECK(a != c);
   QUAN_CHECK(c != a);
   QUAN_CHECK("" != a);
   QUAN_CHECK(a != d);
   QUAN_CHECK(a != "another string");
   QUAN_CHECK("another string" != a);
   QUAN_CHECK(c != "Hello");
   QUAN_CHECK("hello" != c);
}

void concat()
{
   quan::string a = "Hello";
   quan::string b = " and Goodbye";

   auto c = a + b;
   QUAN_CHECK(strcmp(c.get(),"Hello and Goodbye")==0);

   quan::string d = a + quan::string{};
   QUAN_CHECK(strcmp(d.get(),"Hello")==0);
   quan::string e = quan::string{} + b;
   QUAN_CHECK(strcmp(e.get()," and Goodbye")==0);

   QUAN_CHECK((quan::string{"x,"} + 'y' ) == "x,y");
   QUAN_CHECK(('x' + quan::string{",y"} ) == "x,y");

   QUAN_CHECK(a +'o' == "Helloo");
   QUAN_CHECK('S' + a == "SHello");
}

int errors = 0;
int main()
{
   default_constructor();
   const_char_constructor();
   r_value_constructor();
   string_assignment();
   string_move_assignment();
   char_ptr_assignment();
   char_ptr_plus_assignment();
   string_plus_assignment();
   string_compare_test();
   char_plus_assignment();
   concat();

   EPILOGUE
}
