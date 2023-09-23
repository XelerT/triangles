#pragma once

#include <cmath>

#include "vector.hpp"
#include "point.hpp"
#include "triangle.hpp"

#include "../debug/debug.hpp"

namespace geometry
{                                               // Triangle(s, t) = B + s * vec_e0 + t * vec_e1
        class triangle_point_distance_t         // Q(s, t) = (Triangle(s, t) - Point) ^ 2 =
        {                                       //         = a * s^2 + 2 * b * s * t + c t^2 
                public:                         //           + 2 * d * s + 2 * e * t + f
                        vector_t vec_d;         // = B - P
                        double a = NAN;         // = (vec_e0, vec_e0)
                        double b = NAN;         // = (vec_e0, vec_e1)
                        double c = NAN;         // = (vec_e1, vec_e1)
                        double d = NAN;         // = (vec_e0, vec_d)
                        double e = NAN;         // = (vec_e1, vec_d)
                        double f = NAN;         // = (vec_d,  vec_d)

                        double s0 = NAN;
                        double t0 = NAN;

                        double inv_s0_t0_divisor = NAN;

                        double distance_square = NAN;
                        double gradient_x      = NAN;
                        double gradient_y      = NAN;  

                        triangle_point_distance_t (const triangle_t &triangle_,
                                                   const point_t &point_)
                                                   :
                                                   vec_d(point_, triangle_.get_vertex_a())
                        {
                                if (point_.get_status() == INVALID)
                                        throw std::runtime_error("Point has invalid coordinates"                \
                                                                 " to calculate distance to triangle.");

                                vector_t segment_a_b = triangle_.get_segment_a_b();
                                vector_t segment_a_c = triangle_.get_segment_a_c();

                                // segment_a_b.print_vector();
                                // segment_a_c.print_vector();     
                                // vec_d.print_vector();

                                a = triangle_.get_segment_a_b().scalar_product(segment_a_b);
                                b = triangle_.get_segment_a_b().scalar_product(segment_a_c);
                                c = triangle_.get_segment_a_c().scalar_product(segment_a_c);
                                d = triangle_.get_segment_a_b().scalar_product(vec_d);
                                e = triangle_.get_segment_a_c().scalar_product(vec_d);
                                f = vec_d.scalar_product(vec_d);

                                calculate_inv_s0_t0_divisor();
                                calculate_s0();
                                calculate_t0();
                                
                                // $dump(a)
                                // $dump(b)
                                // $dump(c)
                                // $dump(d)
                                // $dump(e)
                                // $dump(f)
                                // $dump(inv_s0_t0_divisor)
                                // $dump(s0)
                                // $dump(t0)
                        };

                        void calculate_distance_square (double s, double t)
                        {
                                distance_square = a * s * s     +
                                                  2 * b * s * t +
                                                  c * t * t     +
                                                  2 * d * s     +
                                                  2 * e * t     +
                                                  f;                                
                        }

                        void calculate_gradient (double s, double t)
                        {
                                gradient_x = 2 * (a * s + b * t + d);
                                gradient_y = 2 * (b * s + c * t + e);
                        }

                private:
                        void calculate_inv_s0_t0_divisor ()
                        {
                                inv_s0_t0_divisor = 1 / (a * c - b * b);
                        }

                        void calculate_s0 ()
                        {
                                s0  = b * e - c * d;
                                s0 *= inv_s0_t0_divisor;
                        }

                        void calculate_t0 ()
                        {
                                t0  = b * d - a * e;
                                t0 *= inv_s0_t0_divisor;
                        }
        };
}