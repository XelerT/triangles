#pragma once

#include "../include/utils.hpp"
#include "point.hpp"

namespace geometry 
{
        class vector_t
        {
                public:
                        double x = NAN;
                        double y = NAN;
                        double z = NAN;

                        vector_t () = default;
                        vector_t (const point_t &begin_, const point_t &end_)
                        {
                                if (begin_.get_status() == INVALID || end_.get_status() == INVALID)
                                        throw std::runtime_error("Point has invalid coordinates to create vector.");

                                x = end_.x - begin_.x;
                                y = end_.y - begin_.y;
                                z = end_.z - begin_.z;
                        };

                        ~vector_t () {};

                        void print_vector ()
                        {
                                std::cout << "[" << x << ", " <<
                                                    y << ", " <<
                                                    z << "]\n";
                        }
        };
}

