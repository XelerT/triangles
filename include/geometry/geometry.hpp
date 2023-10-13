#pragma once

#include "point.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "plane.hpp"
#include "triangle.hpp"

bool triangles_intersect (geometry::triangle_t &triangle_one,
                          geometry::triangle_t &triangle_two
                         );

geometry::point_t find_line_triangle_lines_intersection (const geometry::line_t     &line,
                                                         const geometry::triangle_t &triangle);      
bool line_triangle_in_plane_intersect_in_triangles      (const geometry::line_t &line, 
                                                               geometry::triangle_t &triangle_owning_line,
                                                               geometry::triangle_t &triangle1,
                                                               geometry::triangle_t &triangle2);
