#include <iostream>

#include "geometry/geometry.hpp"

using namespace geometry;

point_t find_line_plane_intersection (const line_t &line, const plane_t &plane)
{
        double param = plane.find_line_plane_intersection_param(line);

        return line.get_point_on_line(param);
}

bool line_is_in_plane (const line_t &line, const plane_t &plane)
{
        point_t point1 = line.get_point_on_line(0);
        point_t point2 = line.get_point_on_line(1);

        if (is_equal(plane.plane_equation_value(point1.x, point1.y, point1.z), 0) &&
            is_equal(plane.plane_equation_value(point2.x, point2.y, point2.z), 0)) {
                return true;
        }

        return false;
}

bool line_intersect_triangles (const line_t &line,
                               triangle_t   &triangle1,
                               triangle_t   &triangle2)
{
        bool intersect = false;

        point_t point = line.intersects_line_at(triangle2.get_line_a_b());
        if (point.is_valid())
                intersect = triangle1.is_inside(point) &&
                            triangle2.is_inside(point);
        if (!intersect) {
                point = line.intersects_line_at(triangle2.get_line_b_c());
                if (point.is_valid())
                        intersect = triangle1.is_inside(point) &&
                                    triangle2.is_inside(point);
        }
        if (!intersect) {
                point = line.intersects_line_at(triangle2.get_line_c_a());
                if (point.is_valid())
                        intersect = triangle1.is_inside(point) &&
                                    triangle2.is_inside(point);
        }

        return intersect;
}

bool line_intersect_plane_in_triangles (const line_t &line, const plane_t &plane, 
                                        triangle_t   &triangle1, 
                                        triangle_t   &triangle2)
{
        bool intersect = false;

        point_t point = find_line_plane_intersection(line, plane);
        if (point.is_valid()) {
                intersect = triangle1.is_inside(point) &&
                            triangle2.is_inside(point);

        } else if (line_is_in_plane(line, plane)) {
                if (triangle1.is_equal(triangle2)) {
                        return true;
                }
                intersect = line_intersect_triangles(line, triangle1, triangle2);
        }

        return intersect;
}

bool triangles_intersect (triangle_t &triangle1, triangle_t &triangle2)
{
        bool intersect = false;
        plane_t plane2 = triangle2.get_plane();
        plane_t plane1 = triangle1.get_plane();

        if (plane2.is_parallel2(plane1))
                return false;

        intersect = line_intersect_plane_in_triangles(triangle1.get_line_a_b(), plane2,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle1.get_line_b_c(), plane2,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle1.get_line_c_a(), plane2,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle2.get_line_a_b(), plane1, 
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle2.get_line_b_c(), plane1,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle2.get_line_c_a(), plane1, 
                                                      triangle1, triangle2);

        return intersect;
}
