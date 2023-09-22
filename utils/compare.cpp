#include "utils.hpp"

#include <cmath>

bool doubles_are_equal (const double a, const double b, const double threshold)
{
        return fabs(a-b) < threshold;
}

bool double_is_equal_greater (const double a, const double b, const double threshold)
{
        if (doubles_are_equal(a, b, threshold))
                return true;
        else
                return a > b;
}

bool double_is_greater (const double a, const double b, const double threshold)
{
        if (doubles_are_equal(a, b, threshold))
                return 0;
        else
                return a > b;
}

bool double_is_equal_lower (const double a, const double b, const double threshold)
{
        if (doubles_are_equal(a, b, threshold))
                return true;
        else
                return a < b;
}

bool double_is_lower (const double a, const double b, const double threshold)
{
        if (doubles_are_equal(a, b, threshold))
                return 0;
        else
                return a < b;
}