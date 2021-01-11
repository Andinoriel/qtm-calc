#include <chrono>
#include <future>
#include <iostream>
#include <thread>

#include "qtm-core.hpp"

int main(void) {
  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();

  std::vector<std::thread> threads;

  for (std::size_t i = 1; i < 500; ++i) {
    Qtm* x = new Qtm(i, 20, 1.5, 1.1);
    threads.push_back(std::thread(&Qtm::calc_final_states, x));
  }

  for (auto &&i : threads) {
    i.join();
  }

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Time difference = "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "[ms]" << std::endl;
  return 0;
}