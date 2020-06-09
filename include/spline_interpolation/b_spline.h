/**
 * @file b_spline.h
 * @author amsl
 */

#ifndef __B_SPLINE_H
#define __B_SPLINE_H

#include <iostream>
#include <vector>
#include <Eigen/Dense>

namespace spline_interpolation
{

class BSpline
{
public:
    BSpline(void);

    enum KnotType{
        UNIFORM,
        OPEN_UNIFORM
    };


    void set_control_points(const std::vector<Eigen::VectorXd>& p, KnotType kt=KnotType::OPEN_UNIFORM);
    void set_degree(unsigned int n);
    Eigen::VectorXd get_vector(double t);

protected:
    double basis_function(unsigned int j, unsigned int k, double t);
    void set_uniform_knot_vector(unsigned int m);
    void set_open_uniform_knot_vector(unsigned int m);

    // knot vector
    std::vector<double> t_;
    // control vector
    std::vector<Eigen::VectorXd> p_;
    // degree of control vector
    unsigned int d_;
    // degree of interpolation curve
    unsigned int n_;
    // number of knot
    unsigned int m_;
};

}// namespace spline_interpolation

#endif // __B_SPLINE_H
