#pragma once

#include "octree/tree.hpp"

octree::octosector_t
select_octangle4triangle_index
(const std::pair<geometry::triangle_t, size_t> &triangle_index, const geometry::point_t &middle);
