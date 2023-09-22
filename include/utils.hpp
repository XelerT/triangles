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
const double THRESHOLD = 0.e-5;

bool doubles_are_equal       (const double a, const double b, const double threshold);
bool double_is_equal_greater (const double a, const double b, const double threshold);
bool double_is_greater       (const double a, const double b, const double threshold);
bool double_is_equal_lower   (const double a, const double b, const double threshold);
bool double_is_lower         (const double a, const double b, const double threshold);
