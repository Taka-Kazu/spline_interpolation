cmake_minimum_required(VERSION 3.0)

project(spline_interpolation)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")
set(PYBIND11_CPP_STANDARD -std=c++11)

find_package(Eigen3 REQUIRED)

include_directories(
    include
    ${EIGEN3_INCLUDE_DIRS}
)

add_library(spline_interpolation SHARED
    src/b_spline.cpp
)

add_executable(test src/test.cpp)
target_link_libraries(test spline_interpolation)

if(EXISTS ${PROJECT_SOURCE_DIR}/pybind11)
    message("pybind11 exists")
    add_subdirectory(pybind11)
    pybind11_add_module(b_spline_py SHARED src/b_spline_py.cpp src/b_spline.cpp)
else()
    message("pybind11 does not exists")
endif()

install(TARGETS spline_interpolation DESTINATION lib)
install(FILES include/${PROJECT_NAME}/* DESTINATION include/${PROJECT_NAME}/)
