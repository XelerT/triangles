cmake_minimum_required(VERSION 3.14)

project(triangles)

set(default_build_type "Debug")
set(GTESTS False CACHE BOOL "To build unitests")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        message(STATUS "Setting build type to '${default_build_type}'.")
        
        set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
                                STRING "Choose the type of build." FORCE)
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
                     "Debug" "Release")
endif()

if (GTESTS)
        message("Building unitests.")

        find_package(GTest REQUIRED)
        include_directories(${GTEST_INCLUDE_DIRS})

        set(UNITESTS "unitests")
        set(TEST_SRC_LIST tests/unitests/main.cpp geometry/geometry.cpp utils/compare.cpp)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++20 -lgtest -lgmock -pthread")
        
        add_executable(${UNITESTS} ${TEST_SRC_LIST})
else()
        message("Building triangles.")
        
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
        set(SRC_LIST main.cpp geometry/geometry.cpp utils/compare.cpp)

        add_executable(${PROJECT_NAME} ${SRC_LIST})
endif()