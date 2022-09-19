#pragma once

#include "ellipse.h"

class CURVE_API circle : public ellipse {

public:
    circle(double radius);
    double get_radius() const;
};
