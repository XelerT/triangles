#include <iostream>

#include "geometry/geometry.hpp"
#include "utils.hpp"
#include "ui.hpp"
#include "triangles.hpp"
#include "std_vector.hpp"
#include "octree.hpp"

using namespace geometry;
using namespace std;
using namespace octree;

int main ()
{
        auto input = get_user_input();

        vector<triangle_t> triangles = get_triangles(input);

        auto min_max_points = find_extreme_points(input.second);
        tree_t<pair<triangle_t, size_t>> tree {min_max_points.first, min_max_points.second};
        insert_triangles(tree, triangles);

        // auto triangles_indexes = get_intersected_triangles_indexes(find_triangles_intersections(triangles));
        auto triangles_indexes = get_intersected_triangles_indexes(find_triangles_intersections(tree));
        
        sort_triangle_indexes(triangles_indexes);

        print<int>(triangles_indexes);
}