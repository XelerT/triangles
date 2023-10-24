#pragma once

#include <cstdint>
#include <cstddef>

#include "compare.hpp"

typedef enum STATUSES {
        INVALID,
        VALID       
} STATUSES;

typedef enum ERRORS {
        INVALID_POINT = 0xBADA46,
        WRONG_INPUT   = 0xBAD146
} ERRORS;

const uint8_t N_DIMENSIONS            = 3;
const uint8_t N_TRIANGLE_VERTEXES     = 3;
const uint8_t MAX_POINT_NAME_LENGTH   = 8;
const uint8_t MIN_N_TRIANGLES2INPUT   = 1;
const size_t  MAX_N_TRIANGLES2INPUT   = 1'000'000;