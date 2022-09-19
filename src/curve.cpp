#include "curve.h"

curve::point curve::get_point(double t) const {
    return curve::point{
        get_x_coord(t),
        get_y_coord(t),
        get_z_coord(t)
    };
}

curve::point curve::get_derivative(double t) const {
    return curve::point{
       get_x_derivative(t),
       get_y_derivative(t),
       get_z_derivative(t)
    };
}
