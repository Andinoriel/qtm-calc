#ifdef _LIBQTMCALC_ENABLE_PYBIND11_EXPORT

#include <pybind11/pybind11.h>

void init_module_qtm_core(pybind11::module_ &m);
void init_module_qtm_data(pybind11::module_ &m);

PYBIND11_MODULE(libqtmcalc, m) {
    init_module_qtm_core(m);
    init_module_qtm_data(m);
};

#endif // _LIBQTMCALC_ENABLE_PYBIND11_EXPORT