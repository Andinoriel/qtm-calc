#include "qtm-json.hpp"

#include <iostream>

namespace qtm {

void qtm_json::read(std::string path) {
  boost::property_tree::read_json(path, this->root_in);
};

void qtm_json::process(void) {
  std::size_t channel_count =
      this->root_in.get<std::size_t>("channel_count", 1);
  std::size_t queue_size = this->root_in.get<std::size_t>("queue_size", 0);
  double la = this->root_in.get<double>("la", 1);
  double mu = this->root_in.get<double>("mu", 1);
  double nu = this->root_in.get<double>("nu", 0);
  std::ptrdiff_t n = this->root_in.get<std::size_t>("n", -1);

  qtm qtm(channel_count, queue_size, la, mu, nu, n);

  for (auto &&state : qtm.calc_final_states()) {
    static std::size_t iter = 0;
    this->root_out.put("final_states." + std::to_string(++iter), state);
  }

  this->root_out.put("avg_queue", qtm_data::calc_avg_queue(qtm));
  this->root_out.put("ete", qtm_data::calc_ete(qtm));
  this->root_out.put("avg_time_queue", qtm_data::calc_avg_time_queue(qtm));
  this->root_out.put("perc_server_req", qtm_data::calc_perc_served_req(qtm));
  this->root_out.put("count_server_req",
                     qtm_data::calc_avg_count_served_req(qtm));
  this->root_out.put("avg_count_req", qtm_data::calc_avg_count_req(qtm));
};

void qtm_json::write(std::string path) {
  boost::property_tree::write_json(path, this->root_out);
};

void qtm_json::run(std::string in, std::string out) {
  this->read(in);
  this->process();
  this->write(out);
};

}; // namespace qtm
