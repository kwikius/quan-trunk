

#include <quan/vector_view.hpp>
#include <iostream>

/*
vector_view test
*/

void vector_view_test()
{
  // view of a std::vector

  std::vector<int> ivect{0,1,2,3,4,5,6,7};
  auto result0 = quan::make_vector_view(ivect,1,7);

  for (auto i = 0U; i < result0.size() ; ++i){
     std::cout << result0[i] << '\n';
  }

  // view of c style array
  int ar [] = {0,1,2,3,4,5,6,7};
  auto result1 = quan::make_vector_view(ar,1,7);

  for (auto i = 0U; i < result1.size() ; ++i){
     std::cout << result1[i] << '\n';
  }

  // nested view of a view of an array
  auto result2 = quan::make_vector_view(result1,1,6);

  for (auto i = 0U; i < result2.size() ; ++i){
     std::cout << result2[i] << '\n';
  }

  
}