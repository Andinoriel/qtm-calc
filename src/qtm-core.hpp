#pragma once
#ifndef __QTM_CORE_HPP__
#define __QTM_CORE_HPP__

#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

#include <iostream>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

// namespace qtm {

double clamp(double num, double min_value, double max_value);

class Qtm final {
private:
  size_t __channel_count, __queue_size;
  ptrdiff_t __n;
  double __la, __mu, __nu;
  std::vector<double> __final_states;

  boost::numeric::ublas::matrix<double> &__matrix_init(size_t channel_count, size_t queue_size, double la,
                double mu, double nu, ptrdiff_t n) const;

public:
  explicit Qtm(size_t channel_count, size_t queue_size, double la,
               double mu, double nu = 0, ptrdiff_t n = -1);
  ~Qtm(void) = default;

  size_t const &channel_count(void) const;
  size_t const &queue_size(void) const;
  ptrdiff_t const &n(void) const;

  double const &la(void) const;
  double const &mu(void) const;
  double const &nu(void) const;

  std::vector<double> const final_states(void) const;

  std::vector<double> calc_final_states(void);
};

// } // namespace qtm

#endif // __QTM_CORE_HPP__
