cmake_minimum_required(VERSION 3.14)

project(triangles_unitests)

set(default_build_type "Debug")

message("Building unitests.")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(UNITESTS "unitests")
set(UNITESTS_SRC unitests/line.cpp  unitests/intersection.cpp unitests/point_in_triangle.cpp 
                 unitests/point.cpp unitests/triangle.cpp     unitests/vector.cpp unitests/intersections_octree.cpp)

set(TEST_SRC_LIST ${UNITESTS_SRC} ../src/geometry.cpp ../src/octree.cpp ../src/ui.cpp ../src/triangles.cpp ../utils/compare.cpp)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(${UNITESTS} ${TEST_SRC_LIST})

target_include_directories(${UNITESTS} PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${UNITESTS} gtest gtest_main gmock)