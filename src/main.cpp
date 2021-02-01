#include <exception>
#include <iostream>

#include "qtm-json.hpp"

int main(int argc, const char *argv[]) {
  try {
    if (argc != 3) {
      throw std::runtime_error(
          "Too few arguments!\n Usage: qtm-calc <json input> <json output>");
    }

    qtm::qtm_json qtm_json;
    qtm_json.run(argv[1], argv[2]);

  } catch (std::exception const &ex) {
    std::cout << ex.what() << std::endl;
  } catch (...) {
    std::cout << "Oops... Something went wrong!" << std::endl;
  }

  return 0;
};