#include "utils.hpp"

#include <cmath>

#ifdef THRESHOLD
const double threshold = THRESHOLD;
#else 
const double threshold = 1.e-5;
#endif /*THRESHOLD*/

bool is_equal (const double a, const double b)
{
        return fabs(a - b) < threshold;
}

bool is_equal_greater (const double a, const double b)
{
        if (is_equal(a, b))
                return true;
        else
                return a > b;
}

bool is_greater (const double a, const double b)
{
        if (is_equal(a, b))
                return false;
        else
                return a > b;
}

bool is_equal_lower (const double a, const double b)
{
        if (is_equal(a, b))
                return true;
        else
                return a < b;
}

bool is_lower (const double a, const double b)
{
        if (is_equal(a, b))
                return false;
        else
                return a < b;
}