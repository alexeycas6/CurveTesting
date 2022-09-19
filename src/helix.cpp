#include "helix.h"

double helix::get_z_coord(double t) const {
    return m_step * t;
}

double helix::get_z_derivative(double t) const {
    return m_step;
}

helix::helix(double x_semiaxis, double y_semiaxis, double step):
    m_step{step}, ellipse(x_semiaxis, y_semiaxis) {  
    if (step < 0)
        throw std::logic_error("invaild step");
}
