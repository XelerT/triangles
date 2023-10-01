#include <iostream>

#include "include/geometry/geometry.hpp"
#include "include/utils.hpp"
#include "include/ui.hpp"
#include "include/triangles.hpp"
#include "include/std_vector.hpp"

using namespace geometry;
using namespace ui;
using namespace std;

int main ()
{
        input_t input {};
        vector<triangle_t> triangles = get_triangles(input);

        auto triangles_indexes = get_intersected_triangles_indexes(find_triangles_intersections(triangles));
        sort_triangle_indexes(triangles_indexes);

        println<int>(triangles_indexes);
}