#pragma once

#include <cmath>
#include <stdexcept>

#include "curve.h"

class ellipse : public curve {
protected:

    /* полуось x */
    double m_x_semiaxis{ 0. };

    /* полуось y */
    double m_y_semiaxis{ 0. };

    double get_x_coord(double t) const;
    double get_y_coord(double t) const;
    double get_z_coord(double t) const;

    double get_x_derivative(double t) const;
    double get_y_derivative(double t) const;
    double get_z_derivative(double t) const;

public:
    ellipse(double x_semiaxis, double y_semiaxis);
};

