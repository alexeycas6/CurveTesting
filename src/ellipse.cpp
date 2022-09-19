#include "ellipse.h"

double ellipse::get_x_coord(double t) const {
    return m_x_semiaxis * std::cos(t);
}

double ellipse::get_y_coord(double t) const {
    return m_y_semiaxis * std::sin(t);
}

double ellipse::get_z_coord(double t) const {
    return 0.0;
}

double ellipse::get_x_derivative(double t) const{
    return -m_x_semiaxis * std::sin(t);
}

double ellipse::get_y_derivative(double t) const{
    return m_y_semiaxis * std::cos(t);
}

double ellipse::get_z_derivative(double t) const{
    return 0.0;
}

ellipse::ellipse(double x_semiaxis, double y_semiaxis):
    m_x_semiaxis{ x_semiaxis }, m_y_semiaxis{y_semiaxis} {
    if (m_x_semiaxis < 0.0)
        throw std::logic_error("invalid major semiaxis");
    if (m_y_semiaxis < 0.0)
        throw std::logic_error("invalid minor semiaxis");
}
