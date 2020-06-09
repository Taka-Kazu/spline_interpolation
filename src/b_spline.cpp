/**
 * @file b_spline.cpp
 * @author amsl
 */

#include "spline_interpolation/b_spline.h"

namespace spline_interpolation
{
BSpline::BSpline(void)
:n_(2)
{

}

void BSpline::set_control_points(const std::vector<Eigen::VectorXd>& p, KnotType kt)
{
    p_ = p;
    d_ = p_[0].size();
    m_ = p.size() + n_ + 1;
    if(kt==KnotType::OPEN_UNIFORM){
        set_open_uniform_knot_vector(m_);
    }else{
        set_uniform_knot_vector(m_);
    }
}

void BSpline::set_degree(unsigned int n)
{
    n_ = n;
}

double BSpline::basis_function(unsigned int j, unsigned int k, double t)
{
    if(k == 0){
        if(t_[j] <= t && t < t_[j+1]){
            return 1;
        }else{
            return 0;
        }
    }
    const double v0 = (t_[j+k] - t_[j]) > 0 ? (double)(t - t_[j]) / (t_[j+k] - t_[j]) * basis_function(j, k-1, t) : 0.0;
    const double v1 = (t_[j+k+1] - t_[j+1]) > 0 ? (double)(t_[j+k+1] - t) / (t_[j+k+1] - t_[j+1]) * basis_function(j+1, k-1, t) : 0.0;
    return v0+v1;
}

void BSpline::set_uniform_knot_vector(unsigned int m)
{
    t_.clear();
    for(unsigned int i=0;i<m;i++){
        t_.push_back((double)i / (m - 1));
    }
}

void BSpline::set_open_uniform_knot_vector(unsigned int m)
{
    t_.clear();
    for(unsigned int i=0;i<m;i++){
        if(i<n_+1){
            t_.push_back(0.0);
        }else if(i>=n_+1 && i<m-n_-1){
            t_.push_back((double)(i-n_) / (m-(2*n_+1)));
        }else{
            t_.push_back(1.0);
        }
    }
}

Eigen::VectorXd BSpline::get_vector(double t)
{
    Eigen::VectorXd result = Eigen::VectorXd::Zero(d_);
    unsigned int end = m_ - n_ - 1;
    for(unsigned int i=0;i<end;i++){
        // std::cout << i << ": " << result.transpose() << std::endl;
        result += p_[i] * basis_function(i, n_, t);
        // std::cout << i << ": " << result.transpose() << std::endl;
    }
    return result;
}

}// namespace spline_interpolation
