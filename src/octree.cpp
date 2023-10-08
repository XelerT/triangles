#include <utility>

#include "octree.hpp"

using namespace geometry;
using namespace octree;
using namespace std;

namespace
{
        octosector_t get_point_sector (const point_t &point, const point_t &middle)
        {
                bool x_greater = point.x > middle.x;
                bool y_greater = point.y > middle.y;
                bool z_greater = point.z > middle.z;

                if (x_greater && y_greater && z_greater)
                        return octosector_t::FIRST;
                else if (x_greater && y_greater && !z_greater)
                        return octosector_t::SECOND;
                else if (!x_greater && y_greater && z_greater)
                        return octosector_t::THIRD;
                else if (!x_greater && y_greater && !z_greater)
                        return octosector_t::FOURTH;
                else if (!x_greater && !y_greater && z_greater)
                        return octosector_t::FIFTH;
                else if (!x_greater && !y_greater && !z_greater)
                        return octosector_t::SIXTH;
                else if (x_greater && !y_greater && z_greater)
                        return octosector_t::SEVENTH;
                else if (x_greater && !y_greater && !z_greater)
                        return octosector_t::EIGHTH;
                
                return octosector_t::INVALID;
        }
} // anonymous namespace

octosector_t select_octangle4triangle_index (const pair<triangle_t, size_t> &triangle_index, const point_t &middle)
{
        auto vertex_a = triangle_index.first.get_vertex_a();
        auto vertex_b = triangle_index.first.get_vertex_b();
        auto vertex_c = triangle_index.first.get_vertex_c();

        octosector_t a_sector = get_point_sector(vertex_a, middle);
        octosector_t b_sector = get_point_sector(vertex_b, middle);
        octosector_t c_sector = get_point_sector(vertex_c, middle);

        if (a_sector == b_sector && a_sector == c_sector) {
                return a_sector;
        }

        return octosector_t::INVALID;
}

