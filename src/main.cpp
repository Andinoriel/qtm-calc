#include <iostream>

#include "qtm-core.hpp"

int main(void) {
  Qtm _qtm_i(3, 2, 1, 1, 1, 1);
  _qtm_i.calc_final_states();
  return 0;
}