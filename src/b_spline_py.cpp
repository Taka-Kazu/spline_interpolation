#include "spline_interpolation/b_spline.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>

// template <typename T>
// using RMatrix = Eigen::Matrix<T, -1, -1, Eigen::RowMajor>;

namespace py = pybind11;

using namespace spline_interpolation;

PYBIND11_MODULE(b_spline_py, m)
{
    py::class_<BSpline> bs(m, "BSpline");
    bs.def(py::init<>())
        .def("set_degree", &BSpline::set_degree)
        .def("set_control_points", &BSpline::set_control_points)
        .def("get_vector", &BSpline::get_vector);
    py::enum_<BSpline::KnotType>(bs, "KnotType")
        .value("UNIFORM", BSpline::KnotType::UNIFORM)
        .value("OPEN_UNIFORM", BSpline::KnotType::OPEN_UNIFORM)
        .export_values();
}
