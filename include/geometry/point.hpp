#pragma once

#include <cmath>
#include <iostream>

#include "../utils.hpp"

namespace geometry
{
        class point_t
        {
                public:
                        char name[MAX_POINT_NAME_LENGTH] = {};
                        
                        double x = NAN;
                        double y = NAN;
                        double z = NAN;

                        point_t () = default;
                        point_t (const double x_, const double y_, const double z_)
                        {
                                x = x_;
                                y = y_;
                                z = z_;
                        };

                        void print () const
                        {
                                std::cout << "point " << name << " is ("  <<
                                                         x << ", " <<  y   <<
                                                         ", " << z << ")\n";
                        }

                        bool is_valid () const 
                        {
                                if (!std::isnan(x) && !std::isnan(y) && !std::isnan(z))
                                        return true;
                                else 
                                        return false;
                        }

                        void set (const double x_, const double y_, const double z_)
                        {
                                x = x_;
                                y = y_;
                                z = z_;
                        }
        };
}
