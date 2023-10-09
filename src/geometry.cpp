#include <iostream>

#include "geometry/geometry.hpp"

using namespace geometry;

double find_line_plane_intersection_param (const line_t &line, const plane_t &plane)
{
        double numerator   = - (plane.get_A() * line.get_x0() + 
                                plane.get_B() * line.get_y0() + 
                                plane.get_C() * line.get_z0() + 
                                plane.get_D()); 

        double denominator = plane.get_A() * line.get_x_coeff() + 
                             plane.get_B() * line.get_y_coeff() + 
                             plane.get_C() * line.get_z_coeff();

        return numerator / denominator;
}

point_t find_line_plane_intersection (const line_t &line, const plane_t &plane)
{
        double param = find_line_plane_intersection_param(line, plane);

        return line.get_point_on_line(param);
}

bool line_is_in_plane (const line_t &line, const plane_t &plane)
{
        point_t point1 = line.get_point_on_line(0);
        point_t point2 = line.get_point_on_line(1);

        if (plane.plane_equation_value(point1.x, point1.y, point1.z) == 0 &&
            plane.plane_equation_value(point2.x, point2.y, point2.z) == 0) {
                return true;
        }

        return false;
}

bool point_is_inside_triangle (const triangle_t &triangle, const point_t &point)
{
        triangle_point_distance_t distance {triangle, point};
        double s0_t0_sum = distance.s0 + distance.t0;
        
        if (is_equal_lower(s0_t0_sum, 1))
                if (is_equal_greater(distance.s0, 0))
                        if (is_equal_greater(distance.t0, 0))
                                return true;
        
        return false;
}

bool line_intersect_triangles (const line_t     &line,
                               const triangle_t &triangle1,
                               const triangle_t &triangle2)
{
        bool intersect = false;

        point_t point = line.intersects_line_at(triangle2.get_line_a_b());
        if (point.is_valid())
                intersect = point_is_inside_triangle(triangle1, point) &&
                            point_is_inside_triangle(triangle2, point);
        if (!intersect) {
                point = line.intersects_line_at(triangle2.get_line_b_c());
                if (point.is_valid())
                        intersect = point_is_inside_triangle(triangle1, point) &&
                                    point_is_inside_triangle(triangle2, point);
        }
        if (!intersect) {
                point = line.intersects_line_at(triangle2.get_line_c_a());
                if (point.is_valid())
                        intersect = point_is_inside_triangle(triangle1, point) &&
                                    point_is_inside_triangle(triangle2, point);
        }

        return intersect;
}

bool line_intersect_plane_in_triangles (const line_t &line, const plane_t &plane, 
                                        const triangle_t &triangle1, 
                                        const triangle_t &triangle2)
{
        bool intersect = false;

        point_t point = find_line_plane_intersection(line, plane);
        if (point.is_valid())
                intersect = point_is_inside_triangle(triangle1, point) &&
                            point_is_inside_triangle(triangle2, point);

        else if (line_is_in_plane(line, plane)) {
                intersect = line_intersect_triangles(line, triangle1, triangle2);
        }

        return intersect;
}

bool triangles_intersect (const triangle_t &triangle1, const triangle_t &triangle2)
{
        bool intersect = false;
        plane_t plane = triangle2.get_plane();

        if (plane.is_parallel2(triangle1.get_plane()))
                return false;

        intersect = line_intersect_plane_in_triangles(triangle1.get_line_a_b(), plane,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle1.get_line_b_c(), plane,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle1.get_line_c_a(), plane,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        plane = triangle1.get_plane();
        intersect = line_intersect_plane_in_triangles(triangle2.get_line_a_b(), plane, 
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle2.get_line_b_c(), plane,
                                                      triangle1, triangle2);
        if (intersect)
                return intersect;

        intersect = line_intersect_plane_in_triangles(triangle2.get_line_c_a(), plane, 
                                                      triangle1, triangle2);

        return intersect;
}
