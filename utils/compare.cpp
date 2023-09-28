#include "../include/utils.hpp"

#include <cmath>

bool is_equal (const double a, const double b, const double threshold)
{
        return fabs(a-b) < threshold;
}

bool is_equal_greater (const double a, const double b, const double threshold)
{
        if (is_equal(a, b, threshold))
                return true;
        else
                return a > b;
}

bool is_greater (const double a, const double b, const double threshold)
{
        if (is_equal(a, b, threshold))
                return false;
        else
                return a > b;
}

bool is_equal_lower (const double a, const double b, const double threshold)
{
        if (is_equal(a, b, threshold))
                return true;
        else
                return a < b;
}

bool is_lower (const double a, const double b, const double threshold)
{
        if (is_equal(a, b, threshold))
                return false;
        else
                return a < b;
}