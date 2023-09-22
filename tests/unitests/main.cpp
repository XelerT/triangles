 
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "point.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "triangle.hpp"

int main(int argc, char **argv)
{
        ::testing::InitGoogleTest(&argc, argv);
        ::testing::InitGoogleMock(&argc, argv);
        
        return RUN_ALL_TESTS();
}