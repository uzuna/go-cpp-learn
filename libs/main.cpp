
#include <iostream> // std::cout
#include <vector>
#include "arymod.hpp"

int main(void){
  Arymod am(2.0);

  std::vector<float> v{1.0, 2.0, 3.0, 4.0};
  auto v2 = am.Add(v);
  auto s = static_cast<int>(v.size());
  for (auto i=0;i<s;i++){
    std::cout << v2[i] << std::endl;
  }

  auto v3 = am.Multi(v);
  for (auto i=0;i<s;i++){
    std::cout << v3[i] << std::endl;
  }
}