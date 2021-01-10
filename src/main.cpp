#include <iostream>

#include "qtm-core.hpp"

int main(void) {
  Qtm _qtm_i(3, 2, 1, 1, 1, 1);
  auto x = _qtm_i.calc_final_states();
  for (auto &elem : x) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  return 0;
}