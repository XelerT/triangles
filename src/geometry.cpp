#include <iostream>

#include "geometry/geometry.hpp"

using namespace geometry;

bool triangles_intersect (triangle_t &triangle1, triangle_t &triangle2)
{
        plane_t plane2 = triangle2.get_plane();
        plane_t plane1 = triangle1.get_plane();

        if (plane2.is_parallel2(plane1))
                return false;

        if (triangle2.intersects(triangle1))
                return true;

        if (triangle1.intersects(triangle2))
                return true;
        
        return false;
}
