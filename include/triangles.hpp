#pragma once

#include <vector>
#include <utility>
#include <utility>

#include "ui.hpp"
#include "geometry/geometry.hpp"

std::vector<geometry::triangle_t> 
get_triangles (ui::input_t &input);

std::vector<std::pair<int, int>> 
find_triangles_intersections (std::vector<geometry::triangle_t> &triangles);

std::vector<int> 
get_intersected_triangles_indexes (const std::vector<std::pair<int, int>> &paired_indexes);

void sort_triangle_indexes (std::vector<int> &indexes);