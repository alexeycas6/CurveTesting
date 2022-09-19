#pragma once

#include "ellipse.h"

class CURVE_API helix : public ellipse {
    double m_step;

    // достаточно только переопределить методы для z
    double get_z_coord(double t) const override;
    double get_z_derivative(double t) const override;
public:
    helix(double x_semiaxis, double y_semiaxis, double step);
};
