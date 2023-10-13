#include "config.hpp"

using namespace geometry;

TEST (plain_test, init_class)
{
        point_t point {-1, 2, -3};
        vector_t vec1 {4, 3, 2};
        vector_t vec2 {-5, 7, 1};

        plane_t plane {point, vec2, vec1};

        EXPECT_NEAR(plane.get_A(),  11, threshold);
        EXPECT_NEAR(plane.get_B(),  14, threshold);
        EXPECT_NEAR(plane.get_C(), -43, threshold);
        EXPECT_NEAR(plane.get_D(), -146, threshold);
}
