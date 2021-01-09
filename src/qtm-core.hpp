#pragma once
#ifndef __QTM_CORE_HPP__
#define __QTM_CORE_HPP__

#include <algorithm>
#include <cmath>
#include <vector>

#include <iostream>

class Qtm final {
private:
  std::size_t _channel_count, _queue_size, _n;
  double _la, _mu, _nu;
  std::vector<double> _final_states;

  // std::vector<std::vector<(...)Type(s)>> __matrix_init(...Args) const;

public:
  explicit Qtm(std::size_t channel_count, std::size_t queue_size, double la, double mu,
      double nu, std::size_t n = -1);
  ~Qtm(void) = default;

  std::size_t const &channel_count(void) const;
  std::size_t const &queue_size(void) const;
  std::size_t const &n(void) const;

  double const &la(void) const;
  double const &mu(void) const;
  double const &nu(void) const;

  std::vector<double> const final_states(void) const;

  void calc_final_states(void);
};

#endif // __QTM_CORE_HPP__
