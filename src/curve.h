#pragma once
#include <array>

class curve {

    using point = std::array<double, 3>;

protected:

    /* Функции для расчёта координат */

    virtual double get_x_coord(double t) const  = 0;
    virtual double get_y_coord(double t) const  = 0;
    virtual double get_z_coord(double t) const  = 0;

    /* Функции для расчёта производных */

    virtual double get_x_derivative(double t) const = 0;
    virtual double get_y_derivative(double t) const = 0;
    virtual double get_z_derivative(double t) const = 0;

public:
    /* получить координату */
    point get_point(double t) const;

    /* получить производную */
    point get_derivative(double t) const;
};
