#include <random>
#include <memory>
#include <iostream>
#include <algorithm>

#include "circle.h"
#include "helix.h"

using curve_ptr = std::shared_ptr<curve>;

int main() {

    const double pi = acos(-1);

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> params(1.0, 10.0);
    std::uniform_int_distribution<int> figures(0, 2);

    size_t count = 10;
    std::vector<curve_ptr> curves;
    curves.reserve(count);

    for (size_t i = 0; i < count; i++) {

        // тип фигуры
        auto figure_type = figures(generator);

        switch (figure_type)
        {
        case 0:
            curves.push_back(
                std::make_shared<ellipse>(params(generator), params(generator))
            );
            break;
        case 1:
            curves.push_back(
                std::make_shared<circle>(params(generator))
            );
            break;
        case 2:
            curves.push_back(
                std::make_shared<helix>(params(generator), params(generator), params(generator))
            );
            break;
        default:
            break;
        }

        // координаты
        auto time = pi / 4.;
        auto coords = curves.back()->get_point(time);
        std::cout << "x: " << coords[0] <<
            ", y: " << coords[1] <<
            ", z: " << coords[2] << std::endl;

        // производная
        auto derivative = curves.back()->get_derivative(time);
        std::cout << "x_d: " << derivative[0] <<
            ", y_d: " << derivative[1] <<
            ", z_d: " << derivative[2] << std::endl;
        std::cout << std::endl;
    }

    // выделяем круги
    std::vector<std::shared_ptr<circle>> circles;
    for (const auto& elem : curves) {
        auto circle_elem = std::dynamic_pointer_cast<circle>(elem);
        if (circle_elem != nullptr)
            circles.push_back(circle_elem);
    }

    std::sort(
        circles.begin(),
        circles.end(),
        [](const auto& lhs, const auto& rhs) {
            return lhs->get_radius() < rhs->get_radius();
        }
    );

    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < circles.size(); i++)
        sum += circles[i]->get_radius();

    return 0;
}