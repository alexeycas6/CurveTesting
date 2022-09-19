#include "circle.h"

circle::circle(double radius):
   ellipse(radius, radius) {  // задаем просто радиус и все будет работать корректно
}

double circle::get_radius() const {
    return m_x_semiaxis;
}
