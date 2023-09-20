#pragma once

#include <cstdint>

typedef enum STATUSES {
        INVALID,
        VALID       
} STATUSES;

typedef enum ERRORS {
        INVALID_POINT = 0xBADA46
} ERRORS;

const uint8_t MAX_POINT_NAME_LENGTH = 8;