#pragma once

#include "point.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "plane.hpp"
#include "triangle.hpp"
#include "triangle_point_distance.hpp"

double find_line_plane_intersection_param       (const geometry::line_t &line, const geometry::plane_t &plane);
geometry::point_t* find_line_plane_intersection (const geometry::line_t &line, const geometry::plane_t &plane);

bool point_is_inside_triangle (const geometry::triangle_t &triangle, const geometry::point_t &point);
