#pragma once
#ifndef __QTM_CORE_HPP__
#define __QTM_CORE_HPP__

#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace qtm {

double clamp(double num, double min_value, double max_value);

class qtm final {
private:
  size_t channel_count_, queue_size_;
  ptrdiff_t n_;
  double la_, mu_, nu_;
  boost::numeric::ublas::vector<double> final_states_;

  [[nodiscard]] static boost::numeric::ublas::matrix<double>
  matrix_init(size_t channel_count, size_t queue_size, double la, double mu,
              double nu, ptrdiff_t n);

public:
  explicit qtm(size_t channel_count, size_t queue_size, double la, double mu,
               double nu = 0, ptrdiff_t n = -1);
  ~qtm(void) = default;

  size_t const &channel_count(void) const;
  size_t const &queue_size(void) const;
  ptrdiff_t const &n(void) const;

  double const &la(void) const;
  double const &mu(void) const;
  double const &nu(void) const;

  std::vector<double> const final_states(void) const;

  std::vector<double> calc_final_states(void);
};

}; // namespace qtm

#endif // !__QTM_CORE_HPP__
