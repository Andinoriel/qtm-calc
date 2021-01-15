#include "qtm-data.hpp"

namespace qtm {

void qtm_data::__check_final(qtm &qtm) {
  if (qtm.final_states().empty()) {
    qtm.calc_final_states();
  }
};

[[nodiscard]] double qtm_data::calc_avg_queue(qtm const &qtm) {
  qtm_data::__check_final(const_cast<class qtm &>(qtm));

  std::size_t i = 1;
  double res = 0.;
  for (auto &state :
       // just slice { final_states[channel_count+1:] }
       ([](std::vector<double> vec, std::size_t f) -> std::vector<double> {
         return std::vector<double>(vec.begin() + f, vec.end());
       })(qtm.final_states(), qtm.channel_count() + 1)) {
    res += i * state;
    i = clamp(i + 1, 1, qtm.queue_size());
  }
  return res;
};

[[nodiscard]] double qtm_data::calc_ete(qtm const &qtm) {
  qtm_data::__check_final(const_cast<class qtm &>(qtm));

  std::size_t i = 0;
  double res = 0.;
  for (auto &state : qtm.final_states()) {
    res += i * state;
    i = clamp(i + 1, 0, qtm.channel_count());
  }
  res /= qtm.channel_count();
  return res;
};

[[nodiscard]] double qtm_data::calc_avg_time_queue(qtm const &qtm) {
  qtm_data::__check_final(const_cast<class qtm &>(qtm));
  return qtm_data::calc_avg_queue(qtm) / qtm.channel_count() * qtm.mu();
};

[[nodiscard]] double qtm_data::calc_perc_served_req(qtm const &qtm) {
  qtm_data::__check_final(const_cast<class qtm &>(qtm));
  return 1. - qtm.final_states().back();
};

[[nodiscard]] double qtm_data::calc_avg_count_served_req(qtm const &qtm) {
  qtm_data::__check_final(const_cast<class qtm &>(qtm));

  std::size_t i = 0;
  double res = 0.;
  for (auto &state : qtm.final_states()) {
    res += state * i;
    if (i < qtm.channel_count() + 1) {
      ++i;
    }
  }
  return res;
};

[[nodiscard]] double qtm_data::calc_avg_count_req(qtm const &qtm) {
  qtm_data::__check_final(const_cast<class qtm &>(qtm));

  std::size_t i = 0;
  double res = 0.;
  for (auto &state : qtm.final_states()) {
    res += state * i;
    ++i;
  }
  return res;
}

}; // namespace qtm
