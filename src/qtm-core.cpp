#include "qtm-core.hpp"

Qtm::Qtm(std::size_t channel_count, std::size_t queue_size, double la,
         double mu, double nu, std::size_t n)
    : _channel_count(channel_count), _queue_size(queue_size), _la(la), _mu(mu),
      _nu(nu), _n(n) {
  this->_final_states.resize(this->_channel_count);
  std::fill_n(this->_final_states.begin(), this->_final_states.capacity(), 0.);
};

std::size_t const &Qtm::channel_count(void) const {
  return this->_channel_count;
};
std::size_t const &Qtm::queue_size(void) const { return this->_queue_size; };
std::size_t const &Qtm::n(void) const { return this->_n; };

double const &Qtm::la(void) const { return this->_la; };
double const &Qtm::mu(void) const { return this->_mu; };
double const &Qtm::nu(void) const { return this->_nu; };

std::vector<double> const Qtm::final_states(void) const {
  return this->_final_states;
};

void Qtm::calc_final_states(void) {

};
