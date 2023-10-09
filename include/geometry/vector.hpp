#pragma once

#include "../utils.hpp"
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
                                // if (!begin_.is_valid() || !end_.is_valid())
                                //         throw std::runtime_error("Point has invalid coordinates to create vector.");

                                x = end_.x - begin_.x;
                                y = end_.y - begin_.y;
                                z = end_.z - begin_.z;
                        };

                        ~vector_t () {};

                        void print () const
                        {
                                std::cout << "[" << x << ", " <<
                                                    y << ", " <<
                                                    z << "]\n";
                        }

                        double scalar_product (vector_t &vec_)
                        {
                                return x * vec_.x + y * vec_.y + z * vec_.z;
                        }

                        void set (const point_t &begin_, const point_t &end_)
                        {
                                // if (!begin_.is_valid() || !end_.is_valid())
                                //         throw std::runtime_error("Point has invalid coordinates to create vector.");

                                x = end_.x - begin_.x;
                                y = end_.y - begin_.y;
                                z = end_.z - begin_.z;
                        }
        };
}

