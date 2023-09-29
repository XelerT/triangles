#include "config.hpp"
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
                vector<pair<int, int>> inters { pair<int, int>(0, 2),
                                                pair<int, int>(1, 2)
                                                };

                void SetUp() {}
                void TearDown() {}
};

TEST_F (triangles_intersection1, three_triangles_2_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class triangles_intersection2 : public testing::Test {
        point_t A{0, 0, -4};
        point_t B{0, 7, 0};
        point_t C{0, 0, 0};

        point_t D{8, 0, 0};
        point_t E{0, -5, 0};
        point_t F{2, 0, 0};

        point_t G{-8, 0, 0};
        point_t I{0, 9.78, 0};
        point_t H{-4, 0, 0};

        point_t J{0, -10, 0};
        point_t K{0, 0, 4};
        point_t L{0, 0, 7};

        triangle_t triangle1{A, C, B};
        triangle_t triangle2{E, F, D};
        triangle_t triangle3{G, I, H};
        triangle_t triangle4{J, L, K};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2, triangle3, triangle4};
                vector<pair<int, int>> inters {};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (triangles_intersection2, four_triangles_0_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class triangles_intersection3 : public testing::Test {
        point_t A{-10, 0, 0};
        point_t B{5, 0, 0};
        point_t C{0, -5, 0};

        point_t D{0, 0, 0};
        point_t E{10, 0, 0};
        point_t F{0, -10, 0};

        point_t G{0, -15, 0};
        point_t I{-5, 0, 0};
        point_t H{0, 0, 10};

        triangle_t triangle1{A, H, I};
        triangle_t triangle2{I, D, C};
        triangle_t triangle3{D, B, C};
        triangle_t triangle4{G, F, E};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2, triangle3, triangle4};
                vector<pair<int, int>> inters { pair<int, int> {0, 1},
                                                pair<int, int> {1, 2}};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (triangles_intersection3, four_triangles_3_inters_with_1_same_side_and_1_vert)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class triangles_intersection4 : public testing::Test {
        point_t A{0, -20, 0};
        point_t B{30, 0, 0};
        point_t C{0, 0, 0};

        point_t D{0, 20, 0};
        point_t E{0, 0, 20};
        point_t F{-28.63, 0, 0};

        point_t G{13.11, -5.25, 0};
        point_t I{20.42, 15.07, 0};
        point_t H{-18.96, -15.66, 0};

        point_t J{20, -20, 0};

        triangle_t triangle1{A, C, B};
        triangle_t triangle2{H, I, J};
        triangle_t triangle3{D, E, A};
        triangle_t triangle4{G, E, F};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2, triangle3, triangle4};
                vector<pair<int, int>> inters { pair<int, int> {0, 1},
                                                pair<int, int> {0, 2},
                                                pair<int, int> {0, 3},
                                                pair<int, int> {1, 2},
                                                pair<int, int> {1, 3},
                                                pair<int, int> {2, 3}};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (triangles_intersection3, four_triangles_6_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class parallel_triangles_diff_planes : public testing::Test {
        point_t A{1, 1, 5};
        point_t B{-1, -1, 5};
        point_t C{1, -1, 5};

        point_t D{4, 0, 0};
        point_t E{0, 7, 0};
        point_t F{-2.95, -3.68, 0};

        triangle_t triangle1{A, C, B};
        triangle_t triangle2{D, F, E};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2};
                vector<pair<int, int>> inters {};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (parallel_triangles_diff_planes, two_triangles_0_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class parallel_triangles_same_plane : public testing::Test {
        point_t A{0, -7, 0};
        point_t B{7, 0, 0};
        point_t C{0, 0, 0};

        point_t D{-6, 0, 0};
        point_t E{0, 2, 0};
        point_t F{0, 6, 0};

        triangle_t triangle1{A, C, B};
        triangle_t triangle2{D, F, E};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2};
                vector<pair<int, int>> inters {};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (parallel_triangles_same_plane, two_triangles_0_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class triangle_in_triangle : public testing::Test {
        point_t A{-1.81, 0.59, 0};
        point_t B{-1.77, 1.81, 0};
        point_t C{-0.82, 1.09, 0};

        point_t D{-1.6, 0.97, 0};
        point_t E{-1.55, 1.36, 0};
        point_t F{-1.27, 1.15, 0};

        triangle_t triangle1{A, B, C};
        triangle_t triangle2{D, E, F};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2};
                vector<pair<int, int>> inters {pair<int, int> {0, 1}};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (triangle_in_triangle, two_triangles_1_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class same_triangles : public testing::Test {
        point_t A{0, 0, 0};
        point_t B{0, 3, 0};
        point_t C{0, 0, 2};

        triangle_t triangle1{A, C, B};
        triangle_t triangle2{A, C, B};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2};
                vector<pair<int, int>> inters {pair<int, int> {0, 1}};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (same_triangles, two_triangles_1_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class parallel_with_same_side : public testing::Test {
        point_t A{0, 0, 0};
        point_t B{0, 3, 0};
        point_t C{0, 0, 2};

        point_t D{0, 0, 4.15};

        triangle_t triangle1{A, C, B};
        triangle_t triangle2{C, D, B};
        
        public:
                vector<triangle_t> triangles {triangle1, triangle2};
                vector<pair<int, int>> inters {pair<int, int> {0, 1}};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (parallel_with_same_side, two_triangles_1_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}

class triangle_in_two_triangles : public testing::Test {
        point_t A{0, 0, 0};
        point_t B{0, 3, 0};
        point_t C{0, 0, 2};

        point_t D{0, 0, 4.15};

        point_t E{0, 0.67, 0.77};
        point_t F{0, 1.19, 2};
        point_t G{0, 1.57, 0.44};

        triangle_t triangle1{A, C, B};
        triangle_t triangle2{C, D, B};
        triangle_t triangle3{E, F, G};

        public:
                vector<triangle_t> triangles {triangle1, triangle2, triangle3};
                vector<pair<int, int>> inters {pair<int, int> {0, 1},
                                               pair<int, int> {0, 2},
                                               pair<int, int> {1, 2}};

                void SetUp() {}
                void TearDown() {}
};

TEST_F (triangle_in_two_triangles, three_triangles_3_inters)
{
        ASSERT_TRUE(find_triangles_intersections(triangles) == inters);
}