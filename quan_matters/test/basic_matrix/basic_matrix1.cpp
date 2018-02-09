
#include <quan_matters/test/test.hpp>
#include <quan/basic_matrix/basic_matrix.hpp>

int errors =0;
int main()
{
   auto constexpr m1 = quan::basic_matrix<2,3>
   {
     2, 5, 4,
     6, 7, 7
   };

   display(m1, "m1");
   

   auto s1 = quan::make_sub_matrix_view(m1,0,0);

   display(s1, "\nsubmatrix 0,0 ");

   auto constexpr m2 = quan::basic_matrix<3,2>
   {
      2, 2,
      3, 3,
      1, 1
   };

   display(m2,"\nm2");

   display(make_transpose_view(m2),"\ntranspose of m2");

   auto const m3 = m1 * m2;

   display(m3, "\nm1 * m2");

   auto const m4 = m1 + m1;

   display (m4, "\nm1 + m1");
   
   display( m4 - m4, "\nm4 - m4");

   auto constexpr m5 = quan::basic_matrix<2,2>
   {
      1,2,
      3,4
   };
   display (m5, "\nm5");

   auto det = matrix_determinant(m5);

   std::cout << "\ndet of m5 =" << det <<'\n';

   auto m6 = make_adjoint_matrix_view(m5);

   display(m6,"\nm6 adjunct of m5");

   auto m7 = make_inverse_matrix_view(m5);

   display(m7, "\nm 7 - inverse of m5");

   display ( m5 * m7, "\nshould be identity");

   auto m8 = make_basic_matrix(m7);

   display(m8, "\nm8 - basic matrix from m7(view)");

   auto m9 = m8;
    display(m9, "\ncopy of m8");

   m8 = m5;
   display(m8, "m8 should now equal m5");

   QUAN_CHECK((std::is_same<decltype(m8), quan::basic_matrix<2,2,double> >::value))
  
   QUAN_CHECK( (m8.at(0,0) == m5.at(0,0)))

   QUAN_EPILOGUE

}
