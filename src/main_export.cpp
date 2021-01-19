#pragma region __PYBIND11_MODULE_EXPORT__

#include <pybind11/pybind11.h>

void init_module_qtm_core(pybind11::module_ &m);
void init_module_qtm_data(pybind11::module_ &m);

PYBIND11_MODULE(libqtmcalc, m) {
    init_module_qtm_core(m);
    init_module_qtm_data(m);
};

#pragma endregion // __PYBIND11_MODULE_EXPORT__
