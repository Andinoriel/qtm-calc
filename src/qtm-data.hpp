#pragma once
#ifndef __QTM_DATA_HPP__
#define __QTM_DATA_HPP__

#include "qtm-core.hpp"

namespace qtm {
class qtm_data final {
public:
  qtm_data(void) = delete;
  ~qtm_data(void) = delete;

  [[nodiscard]] static double calc_avg_queue(qtm &qtm);
  [[nodiscard]] static double calc_ete(qtm &qtm);
  [[nodiscard]] static double calc_avg_time_queue(qtm &qtm);
  [[nodiscard]] static double calc_perc_served_req(qtm &qtm);
  [[nodiscard]] static double calc_avg_count_served_req(qtm &qtm);
  [[nodiscard]] static double calc_avg_count_req(qtm &qtm);
};

}; // namespace qtm

#endif // !__QTM_DATA_HPP__
