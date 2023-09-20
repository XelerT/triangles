#include <iostream>

#include "geometry/geometry.hpp"
#include "include/utils.hpp"

int main ()
{
        double x1, y1, z1, x2, y2, z2, x3, y3, z3;

        std::cin >> x1 >> y1 >> z1;
        std::cin >> x2 >> y2 >> z2;
        std::cin >> x3 >> y3 >> z3;
        geometry::point_t A1{x1, y1, z1};
        A1.print_point();
        geometry::point_t B1{x2, y2, z2};
        B1.print_point();
        geometry::point_t C1{x3, y3, z3};
        C1.print_point();

        std::cin >> x1 >> y1 >> z1;
        std::cin >> x2 >> y2 >> z2;
        std::cin >> x3 >> y3 >> z3;
        geometry::point_t A2{x1, y1, z1};
        A2.print_point();
        geometry::point_t B2{x2, y2, z2};
        B2.print_point();
        geometry::point_t C2{x3, y3, z3};
        C2.print_point();

        geometry::triangle_t triangle1{A1, B1, C1};
        geometry::triangle_t triangle2{A2, B2, C2};

        triangle1.print_sides();
        triangle2.print_sides();
}