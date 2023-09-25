
#include "../include/utils.hpp"
#include "../include/triangles.hpp"

using namespace std;
using namespace geometry;
using ui::input_t;

vector<triangle_t> get_triangles (input_t &input)
{
        vector<triangle_t> triangles;

        point_t A_vertex {};
        point_t B_vertex {};
        point_t C_vertex {};

        auto coord_iter = input.coordinates.begin();

        for (size_t i = 0; i < input.n_triangles; i++) {
                A_vertex.set(coord_iter[0], coord_iter[1], coord_iter[2]);
                coord_iter += 3;
                B_vertex.set(coord_iter[0], coord_iter[1], coord_iter[2]);
                coord_iter += 3;
                C_vertex.set(coord_iter[0], coord_iter[1], coord_iter[2]);
                coord_iter += 3;
                
                triangles.push_back(triangle_t(A_vertex, B_vertex, C_vertex));
        }

        return triangles;
}
#include "../debug/debug.hpp"
vector<pair<int, int>> find_triangles_intersections (vector<triangle_t> &triangles)
{
        vector<pair<int, int>> intersected_triangles_indexes {};

        int i = 0;
        int j = 0;
        $
        for (auto it = triangles.cbegin(); it != triangles.cend() - 1; it++, i++) {
                $
                for (auto jt = it + 1; jt != triangles.cend(); jt++, j++) {
                        $
                        if (triangles_intersect(*it, *jt)) {
                                $
                                intersected_triangles_indexes.push_back(pair<int, int>(i, j));
                        }
                }
        }
        return intersected_triangles_indexes;
}