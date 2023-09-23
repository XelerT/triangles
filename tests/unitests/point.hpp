#pragma once

#include "config.hpp"

using namespace geometry;

TEST (point_test, init_class)
{
        point_t point {1, 0.25, -0.999};

        EXPECT_NEAR(point.x,  1.000, THRESHOLD);
        EXPECT_NEAR(point.y,  0.250, THRESHOLD);
        EXPECT_NEAR(point.z, -0.999, THRESHOLD);
}
