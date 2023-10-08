#include <algorithm>

#include "utils.hpp"
#include "triangles.hpp"
#include "std_vector.hpp"

using namespace std;
using namespace geometry;
using namespace octree;

vector<triangle_t> 
get_triangles (pair<size_t, vector<double>> &input)
{
        vector<triangle_t> triangles;

        point_t A_vertex {};
        point_t B_vertex {};
        point_t C_vertex {};

        auto coord_iter = input.second.begin();

        for (size_t i = 0; i < input.first; i++) {
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

vector<pair<int, int>> 
find_triangles_intersections (vector<triangle_t> &triangles)
{
        vector<pair<int, int>> intersected_triangles_indexes {};

        int i = 0;
        
        for (auto it = triangles.cbegin(); it != triangles.cend() - 1; it++, i++) {
                int j = i + 1;
                for (auto jt = it + 1; jt != triangles.cend(); jt++, j++) {
                        if (triangles_intersect(*it, *jt)) {
                                // it->get_vertex_a().print();
                                // jt->get_vertex_a().print();

                                intersected_triangles_indexes.push_back(pair<int, int>(i, j));
                        }
                }
        }
        return intersected_triangles_indexes;
}

vector<pair<int, int>> 
find_triangles_intersections (vector<pair<triangle_t, size_t>> &triangles_indexes)
{
        vector<pair<int, int>> intersected_triangles_indexes {};
        
        for (auto it = triangles_indexes.cbegin(); it != triangles_indexes.cend() - 1; it++) {
                for (auto jt = it + 1; jt != triangles_indexes.cend(); jt++) {
                        if (triangles_intersect(it->first, jt->first)) {
                                intersected_triangles_indexes.push_back(pair<int, int>(it->second, jt->second));
                        }
                }
        }
        return intersected_triangles_indexes;
}


vector<pair<int, int>> 
find_triangles_intersections (octree::tree_t<std::pair<geometry::triangle_t, size_t>> &tree)
{
        vector<pair<int, int>> intersected_triangles_indexes {};
        
        // auto divided_triangles = tree.get_elements_by_node();
        // // cout << "size = " << divided_triangles.size() << "\n";
        // for (auto triangles : divided_triangles) {
        //         // cout << "triangles_size = " << triangles.size() << "\n";
                
        //         auto intersections = find_triangles_intersections(triangles);
        //         // for (auto el : intersections)
        //         //         cout << el.first << " " << el.second << "\n";
        //         intersected_triangles_indexes.insert(intersected_triangles_indexes.end(), intersections.begin(), intersections.end());
        // }
        
        tree.find_elems_intersections_indexes(intersected_triangles_indexes, triangles_intersect);

        return intersected_triangles_indexes;
}

vector<int>
get_intersected_triangles_indexes (const vector<pair<int, int>> &paired_indexes)
{
        vector<int> indexes = {};

        for (auto it = paired_indexes.begin(); it != paired_indexes.end(); it++) {
                if (find(indexes, it->first) == indexes.end())
                        indexes.push_back(it->first);
                if (find(indexes, it->second) == indexes.end())
                        indexes.push_back(it->second);
        }

        return indexes;
}

void sort_triangle_indexes (vector<int> &indexes)
{
        sort(indexes.begin(), indexes.end());
}

pair<point_t, point_t> find_extreme_points (const vector<double> &coordinates)
{

        auto coord_iter = coordinates.begin();
        double min_coord = coord_iter[0];
        double max_coord = coord_iter[0];

        point_t max {coord_iter[0], coord_iter[1], coord_iter[2]};
        point_t min {coord_iter[0], coord_iter[1], coord_iter[2]};

        do {
                // coord_iter += 3;

                // if (is_equal_greater(coord_iter[0], max.x) &&
                //     is_equal_greater(coord_iter[1], max.y) &&
                //     is_equal_greater(coord_iter[2], max.z)) {
                //         max.set(coord_iter[0], coord_iter[1], coord_iter[2]);
                // } else if (is_equal_lower(coord_iter[0], min.x) &&
                //            is_equal_lower(coord_iter[1], min.y) &&
                //            is_equal_lower(coord_iter[2], min.z)) {
                //         min.set(coord_iter[0], coord_iter[1], coord_iter[2]);
                // }

                if (is_equal_greater(coord_iter[0], max.x)) {
                        max.x = coord_iter[0];
                }
                if (is_equal_greater(coord_iter[1], max.y)) {
                        max.y = coord_iter[1];
                }
                if (is_equal_greater(coord_iter[2], max.z)) {
                        max.z = coord_iter[2];
                }
                
                if (is_equal_lower(coord_iter[0], min.x)) {
                        min.x = coord_iter[0];
                }
                if (is_equal_lower(coord_iter[1], min.y)) {
                        min.y = coord_iter[1];
                }
                if (is_equal_lower(coord_iter[2], min.z)) {
                        min.z = coord_iter[2];
                }

                coord_iter++;
                if (max_coord < *coord_iter) {
                        max_coord = *coord_iter;
                } else if (min_coord > *coord_iter) {
                        min_coord = *coord_iter;
                }
        } while (coord_iter != coordinates.end());
        
        min.set(min_coord, min_coord, min_coord);
        max.set(max_coord, max_coord, max_coord);

        return pair {min, max};
}

void insert_triangles (tree_t<pair<triangle_t, size_t>> &tree, vector<triangle_t> &triangles)
{
        // min_max.first.print();
        // min_max.second.print();

        size_t i = 0;
        for (auto triangle : triangles) {
                tree.insert(pair{triangle, i}, select_octangle4triangle_index);
                i++;
        }
        
        // tree.dump();
}