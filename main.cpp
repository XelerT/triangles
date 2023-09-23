#include <iostream>

#include "geometry/geometry.hpp"
#include "include/utils.hpp"

int main ()
{
        geometry::point_t A1{2.7, 9.88, 0};
        geometry::point_t B1{0, 0, 0};
        geometry::point_t C1{-8, 8, 0};

        geometry::point_t A2{-0.8, 2.46, 0};
        geometry::point_t B2{0, 0, 2};
        geometry::point_t C2{0, 0, 4};

        geometry::triangle_t triangle1{A1, B1, C1};
        geometry::triangle_t triangle2{A2, B2, C2};

        std::cout << triangles_intersect(triangle1, triangle2) << "\n";
}