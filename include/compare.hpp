#pragma once

bool is_equal         (const double a, const double b, const double threshold = 1.e-5);
bool is_equal_greater (const double a, const double b, const double threshold = 1.e-5);
bool is_greater       (const double a, const double b, const double threshold = 1.e-5);
bool is_equal_lower   (const double a, const double b, const double threshold = 1.e-5);
bool is_lower         (const double a, const double b, const double threshold = 1.e-5);
