#pragma once
#ifndef __QTM_JSON_HPP__
#define __QTM_JSON_HPP__

#include <fstream>
#include <iostream>
#include <string>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "qtm-data.hpp"

namespace qtm {

class qtm_json final {
private:
  boost::property_tree::ptree root_in;
  boost::property_tree::ptree root_out;

  void read(std::string path);
  void process(void);
  void write(std::string path);

public:
  qtm_json(void) = default;
  ~qtm_json(void) = default;

  void run(std::string in, std::string out);
};

}; // namespace qtm

#endif // !__QTM_JSON_HPP__