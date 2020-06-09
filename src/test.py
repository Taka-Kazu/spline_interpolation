#!/usr/bin/env python3

from b_spline_py import BSpline
import matplotlib.pyplot as plt
import numpy as np

if __name__=='__main__':
    p = np.array([[5, 0],
                  [3, 0],
                  [2, 0.5],
                  [1, 0.5],
                  [1, 1],
                  [2, 1.5],
                  [2, 2],
                  [4, 2]])

    bs = BSpline()
    bs.set_control_points(p, BSpline.KnotType.OPEN_UNIFORM)

    t = np.arange(0, 1, 0.001)
    p_ = list()
    for t_ in t:
        p_.append(bs.get_vector(t_))
    p_ = np.array(p_)

    plt.plot(p[:, 0], p[:, 1], "ro")
    plt.plot(p_[:, 0], p_[:, 1])
    plt.show()
