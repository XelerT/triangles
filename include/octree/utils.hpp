#pragma once

namespace octree
{
        enum octosector_t
        {
                INVALID = -1,
                FIRST   =  0,
                SECOND  =  1,
                THIRD   =  2,
                FOURTH  =  3,
                FIFTH   =  4,
                SIXTH   =  5,
                SEVENTH =  6,
                EIGHTH  =  7
        };

        const uint8_t N_OCTREE_CHILDREN = 8;
        const uint8_t N_CUBE_VERTEXES   = 8;
        const double  MIN_CUBE_SIDE     = 1;
}