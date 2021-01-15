#pragma once
#ifndef __QTM_DATA_HPP__
#define __QTM_DATA_HPP__

#include "qtm-core.hpp"

namespace qtm {
class qtm_data final {
private:
  static void __check_final(qtm &qtm);

public:
  [[nodiscard]] static double calc_avg_queue(qtm const &qtm);
  [[nodiscard]] static double calc_ete(qtm const &qtm);
  [[nodiscard]] static double calc_avg_time_queue(qtm const &qtm);
  [[nodiscard]] static double calc_perc_served_req(qtm const &qtm);
  [[nodiscard]] static double calc_avg_count_served_req(qtm const &qtm);
  [[nodiscard]] static double calc_avg_count_req(qtm const &qtm);
};

}; // namespace qtm

#endif // !__QTM_DATA_HPP__
