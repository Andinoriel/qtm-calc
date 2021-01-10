#include "qtm-core.hpp"

double clamp(double num, double min_value, double max_value) {
  return max(min(num, max_value), min_value);
}

mat &Qtm::__matrix_init(size_t channel_count, size_t queue_size,
                              double la, double mu, double nu,
                              ptrdiff_t n) const {
  size_t total_count = channel_count + queue_size;
  mat &matrix = *new mat();
  size_t mu_index = 0;
  ptrdiff_t max_n = n;

  // formation of mu and la
  for (size_t i = 0; i < total_count + 1; ++i) {
    rowvec row(total_count + 1, arma::fill::zeros);
    for (size_t j = 0; j < total_count + 1; ++j) {
      if (i == j + 1) {
        if (n != -1) {
          row(j) = clamp(n * 1. / max_n, 0, max_n) * la;
          n -= 1;
        } else {
          row(j) = la;
        }
      } else if (i == j - 1) {
        mu_index = clamp(mu_index + 1, 0, channel_count);
        row(j) = mu_index * mu;
      }
    }
    matrix.insert_rows(i, row);
  }

  // formation of nu
  ptrdiff_t nu_index = queue_size;
  for (ptrdiff_t i = total_count - 1; i > 0 - 1; --i) {
    for (ptrdiff_t j = total_count; j > 0; --j) {
      if (i == j - 1) {
        matrix(i, j) += nu_index * nu;
        nu_index = clamp(nu_index - 1, 0, queue_size - 1);
      }
    }
  }

  // diagonal
  for (size_t i = 0; i < total_count + 1; ++i) {
    for (size_t j = 0; j < total_count + 1; ++j) {
      if (j != i) {
        matrix(i, i) += matrix(j, i);
      }
    }
    matrix(i, i) *= -1;
  }

  return matrix;
};

Qtm::Qtm(size_t channel_count, size_t queue_size, double la,
         double mu, double nu, ptrdiff_t n)
    : __channel_count(channel_count), __queue_size(queue_size), __la(la),
      __mu(mu), __nu(nu), __n(n) {
  this->__final_states.resize(this->__channel_count);
  fill_n(this->__final_states.begin(), this->__final_states.capacity(),
              0.);
};

size_t const &Qtm::channel_count(void) const {
  return this->__channel_count;
};
size_t const &Qtm::queue_size(void) const { return this->__queue_size; };
ptrdiff_t const &Qtm::n(void) const { return this->__n; };

double const &Qtm::la(void) const { return this->__la; };
double const &Qtm::mu(void) const { return this->__mu; };
double const &Qtm::nu(void) const { return this->__nu; };

vector<double> const Qtm::final_states(void) const {
  return this->__final_states;
};

void Qtm::calc_final_states(void) {
  auto x = this->__matrix_init(this->__channel_count, this->__queue_size,
                               this->__la, this->__mu, this->__nu, this->__n);
  x.print(cout);
  // ...
};
