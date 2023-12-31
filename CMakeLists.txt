cmake_minimum_required(VERSION 3.14)

project(triangles)

if (NOT CMAKE_CXX_STANDARD AND NOT CMAKE_CXX_COMPILER)
        set(CMAKE_CXX_STANDARD 20)
endif()

set(default_build_type "Debug")
set(GTESTS False CACHE BOOL "To build unitests")

set(CMAKE_CXX_FLAGS_DEBUG "-Wall")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

if (GTESTS)
        add_subdirectory(tests)
else()
        message("Building triangles in ${CMAKE_BUILD_TYPE}.")
        
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
        set(SRC_LIST main.cpp src/geometry.cpp utils/compare.cpp src/triangles.cpp src/octree.cpp src/ui.cpp)

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

        add_executable(${PROJECT_NAME} ${SRC_LIST})
        target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()