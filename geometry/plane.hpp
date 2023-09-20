#pragma once

#include "point.hpp"
#include "vector.hpp"

namespace geometry
{
        // Plane in form of A * x + B * y + C * z + D = 0;
        class plane_t
        {
                public:
                        double A = 0;
                        double B = 0;
                        double C = 0;
                        double D = 0;
        
                        plane_t () = default;
                        plane_t (const point_t &point_, const vector_t &first_vector_, const vector_t &second_vector_)
                        {
                                if (point_.get_status() == INVALID)
                                        throw std::runtime_error("Point has invalid coordinates to create plane.");

                                A =   first_vector_.y * second_vector_.z - second_vector_.y * first_vector_.z;
                                B = -(first_vector_.x * second_vector_.z - second_vector_.x * first_vector_.z);
                                C =   first_vector_.x * second_vector_.y - second_vector_.x * first_vector_.y;

                                D = - A * point_.x - B * point_.y - C * point_.z; 
                        };
                
                        bool is_equal2 (const plane_t &src_) 
                        {
                                if (A == src_.A && 
                                    B == src_.B &&
                                    C == src_.B &&
                                    D == src_.D
                                )
                                        return true;
                                
                                return false;
                        }

                        bool is_parallel2 (const plane_t &src_)
                        {
                                if (A == src_.A && 
                                    B == src_.B &&
                                    C == src_.B
                                    )
                                        return true;
                                
                                return false;
                        }
        };
}