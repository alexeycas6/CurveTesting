#pragma once

#include "ellipse.h"

class circle : public ellipse {

public:
    circle(double radius);
    double get_radius() const;
};
