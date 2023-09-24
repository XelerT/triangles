#include <iostream>

#include "include/geometry/geometry.hpp"
#include "include/utils.hpp"
#include "include/ui.hpp"
#include "include/triangles.hpp"

using namespace geometry;
using namespace ui;
using namespace std;

int main ()
{
        input_t input {};
        vector<triangle_t> triangles = get_triangles(input);
        // point_t A1{2.7, 9.88, 0};
        // point_t B1{0, 0, 0};
        // point_t C1{-8, 8, 0};

        // point_t A2{-0.8, 2.46, 0};
        // point_t B2{0, 0, 2};
        // point_t C2{0, 0, 4};
        // triangle_t triangle1{A1, B1, C1};
        // triangle_t triangle2{A2, B2, C2};
        std::cout << triangles_intersect(triangles[0], triangles[1]) << "\n";
}