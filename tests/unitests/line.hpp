#pragma once

#include "config.hpp"
#include "../../geometry/geometry.hpp"

using namespace geometry;

TEST(line_test, init_class)
{
        point_t begin {1, 0.25, 2.5};
        point_t end {5, 6.75, 10};

        vector_t vec {begin, end};
        line_t line {vec, begin};

        EXPECT_NEAR(line.get_x_value(1), 4.0 + 1,    THRESHOLD);
        EXPECT_NEAR(line.get_y_value(1), 6.5 + 0.25, THRESHOLD);
        EXPECT_NEAR(line.get_z_value(1), 7.5 + 2.5,  THRESHOLD);

        point_t *point = line.get_point_on_line(1);
        EXPECT_NEAR(point->x, 4.0 + 1,    THRESHOLD);
        EXPECT_NEAR(point->y, 6.5 + 0.25, THRESHOLD);
        EXPECT_NEAR(point->z, 7.5 + 2.5,  THRESHOLD);
}

struct line_test : public testing::Test {
        point_t begin {1, 0.25, 2.5};
        point_t end   {5, 6.75, 10};

        vector_t vec {begin, end};
        line_t *line;

        void SetUp() { line = new line_t {vec, begin}; }
        void TearDown() { delete line; }
};

class line_mock_t : public line_t {
        public:                                
                MOCK_METHOD(double, get_x_value, (const double));
                MOCK_METHOD(double, get_y_value, (const double));
                MOCK_METHOD(double, get_z_value, (const double));
                
                MOCK_METHOD(point_t*, get_point_on_line, (const double));
};

TEST(line_mock_t, mock_line_get_xyz_line_point) {
        point_t begin {1, 0.25, 2.5};
        point_t end {5, 6.75, 10};

        vector_t vec {begin, end};
        
        line_mock_t line_mock;
        line_t line(vec, begin);

        EXPECT_CALL(line_mock, get_x_value(112)).Times(1);
        EXPECT_CALL(line_mock, get_y_value(143)).Times(1);
        EXPECT_CALL(line_mock, get_z_value(1354)).Times(1);

        EXPECT_CALL(line_mock, get_point_on_line(1123)).Times(1);

        line_mock.get_x_value(112);
        line_mock.get_y_value(143);
        line_mock.get_z_value(1354);

        line_mock.get_point_on_line(1123);
}