#pragma once
#ifndef __QTM_CORE_HPP__
#define __QTM_CORE_HPP__

#include <algorithm>
#include <cmath>
#include <vector>

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace qtm {

template <typename type>
double clamp(type num, type min_value, type max_value) {
  return std::max(std::min(num, max_value), min_value);
}

class qtm final {
private:
  size_t channel_count_, queue_size_;
  double la_, mu_, nu_;
  ptrdiff_t n_;
  boost::numeric::ublas::vector<double> final_states_;

  bool is_fs_outdated_;

  static boost::numeric::ublas::matrix<double>
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

  void channel_count(size_t channel_count_);
  void queue_size(size_t queue_size_);
  void n(ptrdiff_t n_);
  void la(double la_);
  void mu(double mu_);
  void nu(double nu_);

  std::vector<double> const final_states(void) const;
  bool is_fs_outdated(void) const;
  std::vector<double> calc_final_states(void);
};

}; // namespace qtm

#endif // !__QTM_CORE_HPP__
