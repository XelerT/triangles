#pragma once

#include "../include/utils.hpp"

namespace geometry
{
        class point_t
        {
                public:
                        char name_[MAX_POINT_NAME_LENGTH] = {};
                        
                        double x = NAN;
                        double y = NAN;
                        double z = NAN;

                        point_t () = default;
                        point_t (const point_t &src) {}
                        point_t (const double x_, const double y_, const double z_)
                        {
                                x = x_;
                                y = y_;
                                z = z_;
                        };

                        void print_point ()
                        {
                                std::cout << "point " << name_ << " is ("  <<
                                                         x << ", " <<  y   <<
                                                         ", " << z << ")\n";
                        }

                        STATUSES get_status ()
                        {
                                if (x != NAN && y != NAN && z != NAN)
                                        return VALID;
                                else 
                                        return INVALID;
                        }
        }
}
