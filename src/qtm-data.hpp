#pragma once
#ifndef __QTM_DATA_HPP__
#define __QTM_DATA_HPP__

#include "qtm-core.hpp"

namespace qtm {
class qtm_data final {
private:
  static void calc_fs_if_outdated(qtm const&qtm);

public:
  qtm_data(void) = delete;
  ~qtm_data(void) = delete;

  static double calc_avg_queue(qtm const &qtm);
  static double calc_ete(qtm const &qtm);
  static double calc_avg_time_queue(qtm const &qtm);
  static double calc_perc_served_req(qtm const &qtm);
  static double calc_avg_count_served_req(qtm const &qtm);
  static double calc_avg_count_req(qtm const &qtm);
};

}; // namespace qtm

#endif // !__QTM_DATA_HPP__
