cmake_minimum_required(VERSION 3.14)

project(triangles)

if (NOT CMAKE_CXX_STANDARD AND NOT CMAKE_CXX_COMPILER)
        set(CMAKE_CXX_STANDARD 20)
endif()

set(default_build_type "Debug")
set(GTESTS False CACHE BOOL "To build unitests")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

if (GTESTS)
        add_subdirectory(tests)
else()
        message("Building triangles.")
        
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
        set(SRC_LIST main.cpp src/geometry.cpp utils/compare.cpp src/triangles.cpp src/octree.cpp src/ui.cpp)

        add_executable(${PROJECT_NAME} ${SRC_LIST})
        target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()