#include "spline_interpolation/b_spline.h"

int main(void)
{
    spline_interpolation::BSpline bs;
    std::vector<Eigen::VectorXd> points;
    points.push_back(Eigen::Vector2d(0, 0));
    points.push_back(Eigen::Vector2d(1, 0));
    points.push_back(Eigen::Vector2d(1, 1));
    points.push_back(Eigen::Vector2d(0, 1));
    bs.set_degree(2);
    bs.set_control_points(points, spline_interpolation::BSpline::KnotType::OPEN_UNIFORM);

    for(double t=0.0;t<1.0;t+=0.01){
        const auto v = bs.get_vector(t);
        std::cout << "t=" << t << ": " << v(0) << ", " << v(1) << std::endl;
    }
    return 0;
}
