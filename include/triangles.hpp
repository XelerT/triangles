#pragma once

#include <vector>
#include <utility>

#include "ui.hpp"
#include "geometry/geometry.hpp"
#include "octree.hpp"

std::vector<geometry::triangle_t> 
get_triangles (std::pair<size_t, std::vector<double>> &input);

std::vector<std::pair<int, int>> 
find_triangles_intersections (std::vector<geometry::triangle_t> &triangles);

std::vector<int> 
get_intersected_triangles_indexes (const std::vector<std::pair<int, int>> &paired_indexes);

void sort_triangle_indexes (std::vector<int> &indexes);

std::pair<geometry::point_t, geometry::point_t> 
find_extreme_points (const std::vector<double> &coordinates);

void insert_triangles (octree::tree_t<std::pair<geometry::triangle_t, size_t>> &tree,
                       std::vector<geometry::triangle_t> &triangles);

std::vector<std::pair<int, int>> 
find_triangles_intersections (octree::tree_t<std::pair<geometry::triangle_t, size_t>> &tree);