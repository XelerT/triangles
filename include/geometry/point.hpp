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
                        {
                                x = x_;
                                y = y_;
                                z = z_;
                        };

                        void print () const
                        {
                                std::cout << "point " << " is ("  <<
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

                        bool is_equal2 (const point_t &point_) const 
                        {
                                // point_.print();
                                // print();
                                if (is_equal(x, point_.x) &&
                                    is_equal(y, point_.y) &&
                                    is_equal(z, point_.z))
                                    return true;

                                return false;
                        }
        };
}
