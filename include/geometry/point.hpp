#pragma once

#include <cmath>
#include <iostream>

#include "../utils.hpp"

namespace geometry
{
        class point_t
        {
                public:                        
                        double x = NAN;
                        double y = NAN;
                        double z = NAN;

                        point_t () = default;
                        point_t (const double x_, const double y_, const double z_)
                                : x(x_), y(y_), z(z_)
                                {};

                        void print () const
                        {
                                std::cout << "(" <<
                                               x << ", " <<
                                               y << ", " << 
                                               z << ")\n";
                        }

                        bool is_valid () const 
                        {
                                return !std::isnan(x) && !std::isnan(y) && !std::isnan(z);
                        }

                        void set (const double x_, const double y_, const double z_)
                        {
                                x = x_;
                                y = y_;
                                z = z_;
                        }

                        bool is_equal2 (const point_t &point_) const 
                        {
                                return is_equal(x, point_.x) &&
                                       is_equal(y, point_.y) &&
                                       is_equal(z, point_.z);
                        }
        };
}
