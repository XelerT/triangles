#include "config.hpp"

using namespace geometry;

TEST(vector_test, init_class)
{
        point_t begin {1, 0.25, 2.5};
        point_t end {5, 6.75, 10};

        vector_t vec {begin, end};

        EXPECT_NEAR(vec.x, 4.0);
        EXPECT_NEAR(vec.y, 6.5);
        EXPECT_NEAR(vec.z, 7.5);
}