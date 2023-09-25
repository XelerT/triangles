#pragma once

#include "../../include/triangles.hpp"

using namespace geometry;
using namespace std;

class triangles_intersection1 : public testing::Test {
        point_t A{15, 0, 0};
        point_t B{0, 0, 10};
        point_t C{0, 15, 0};

        point_t D{10.29, -17,    0};
        point_t E{6.01,  -8.89,  0};
        point_t F{16.53, -10.02, 0};

        point_t G{10.42, -11.54, 0};
        point_t I{2.06,   8.39,  3.04};
        point_t H{0,      0,     20};

        triangle_t triangle1{A, B, C};
        triangle_t triangle2{D, E, F};
        triangle_t triangle3{G, I, H};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2, triangle3};
                vector<pair<int, int>> intersections {
                                                        pair<int, int>(1, 3),
                                                        pair<int, int>(2, 3)
                                                     };

                void SetUp() {}
                void TearDown() {}
};

TEST_F (triangles_intersection1, three_triangles)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == intersections);
}