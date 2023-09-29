#include "config.hpp"

using namespace geometry;

class triangle1_test : public testing::Test {
        point_t A{0, 0, 4};
        point_t B{0, 5, 0};
        point_t C{4, 0, 0};

        public:
                triangle_t triangle{A, B, C};

                void SetUp() {}
                void TearDown() {}
};

class triangle2_test : public testing::Test {
        point_t A{2.7, 9.88, 0};
        point_t B{0, 0, 0};
        point_t C{-8, 8, 0};

        public:
                triangle_t triangle{A, B, C};

                void SetUp() {}
                void TearDown() {}
};

class triangle3_test : public testing::Test {
        point_t A{0, 0, 0};
        point_t B{0, 0, 6};
        point_t C{-9.23, -7.7, 0};

        public:
                triangle_t triangle{A, B, C};

                void SetUp() {}
                void TearDown() {}
};


TEST_F (triangle1_test, inside_triangle)
{
        point_t point1{0.87, 1.61, 1.84};
        point_t point2{1.99, 0.88, 1.30};
        point_t point3{1.96, 1.94, 0.48};

        ASSERT_TRUE(point_is_inside_triangle(triangle, point1));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point2));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point3));
}

TEST_F (triangle1_test, outside_triangle)
{
        point_t point1{-3, 0, 0};
        point_t point2{2.99, -3.28, 0};
        point_t point3{6.29, 0, 0};

        ASSERT_FALSE(point_is_inside_triangle(triangle, point1));
        ASSERT_FALSE(point_is_inside_triangle(triangle, point2));
        ASSERT_FALSE(point_is_inside_triangle(triangle, point3));
}

TEST_F (triangle2_test, inside_triangle)
{
        point_t point1{0, 8, 0};
        point_t point2{-3.23, 5.4, 0};
        point_t point3{-1.11, 1.68, 0};

        ASSERT_TRUE(point_is_inside_triangle(triangle, point1));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point2));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point3));
}

TEST_F (triangle3_test, inside_triangle)
{
        point_t point1{-1.98, -1.66, 2.57};
        point_t point2{-6.02, -5.03, 0.86};
        point_t point3{-0.65, -0.54, 4.43};

        ASSERT_TRUE(point_is_inside_triangle(triangle, point1));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point2));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point3));
}

TEST_F (triangle3_test, on_triangle_boundary)
{
        point_t point1{-3.15, -2.63, 3.95};
        point_t point2{-3.03, -2.53, 0.00};
        point_t point3{-5.15, -4.30, 0.00};

        ASSERT_TRUE(point_is_inside_triangle(triangle, point1));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point2));
        ASSERT_TRUE(point_is_inside_triangle(triangle, point3));
}

TEST_F (triangle3_test, outside_boundary)
{
        point_t point1{0.00, 10.0, 0.00};
        point_t point2{8.26, 0.00, 0.00};
        point_t point3{0, 0, 8.41};

        ASSERT_FALSE(point_is_inside_triangle(triangle, point1));
        ASSERT_FALSE(point_is_inside_triangle(triangle, point2));
        ASSERT_FALSE(point_is_inside_triangle(triangle, point3));
}