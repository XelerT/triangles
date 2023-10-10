#pragma once

#include "point.hpp"
#include "vector.hpp"
#include "../compare.hpp"

namespace geometry
{
        // Plane in form of A * x + B * y + C * z + D = 0;
        class plane_t
        {
                private:
                        double A = 0;
                        double B = 0;
                        double C = 0;
                        double D = 0;

                        double proportional_coeff = 0;

                public:
                        plane_t () = default;
                        plane_t (const point_t &point_, const vector_t &vector1_, const vector_t &vector2_)
                        {
                                set(point_, vector1_, vector2_);
                        };

                        double get_A () const { return A; }
                        double get_B () const { return B; }
                        double get_C () const { return C; }
                        double get_D () const { return D; }
                
                        bool is_equal2 (const plane_t &src_) 
                        {
                                set_proportional_coeff(src_);

                                if (is_equal(B, src_.B * proportional_coeff) &&
                                    is_equal(C, src_.C * proportional_coeff) &&
                                    is_equal(D, src_.D * proportional_coeff)
                                )
                                        return true;
                                
                                return false;
                        }

                        bool is_parallel2 (const plane_t &src_)
                        {
                                set_proportional_coeff(src_);
                                
                                if (is_equal( B * proportional_coeff, src_.B) &&
                                    is_equal( C * proportional_coeff, src_.C) &&
                                    !is_equal(D * proportional_coeff, src_.D)
                                )
                                        return true;

                                return false;
                        }

                        void set (const point_t &point_, const vector_t &vector1_, const vector_t &vector2_)
                        {
                                if (!point_.is_valid())
                                        throw std::runtime_error("Point has invalid coordinates to create plane.");

                                A =   vector1_.y * vector2_.z - vector2_.y * vector1_.z;
                                B = -(vector1_.x * vector2_.z - vector2_.x * vector1_.z);
                                C =   vector1_.x * vector2_.y - vector2_.x * vector1_.y;

                                D = - A * point_.x - B * point_.y - C * point_.z; 

                                reduce_zero_plane_coeffs();
                        }

                        double plane_equation_value (const double x,
                                                     const double y,
                                                     const double z) const
                        {
                                return A * x + B * y + C * z + D;
                        }

                        void print () const
                        {
                                std::cout << A << "x + " 
                                          << B << "y + "
                                          << C << "z + "
                                          << D << " = 0\n";
                        }

                        double find_line_plane_intersection_param (const line_t &line) const
                        {
                                double numerator   = - (A * line.get_x0() + 
                                                        B * line.get_y0() + 
                                                        C * line.get_z0() + 
                                                        D);

                                double denominator = A * line.get_x_coeff() + 
                                                     B * line.get_y_coeff() + 
                                                     C * line.get_z_coeff();

                                return numerator / denominator;
                        }

                private:
                        void reduce_zero_plane_coeffs ()
                        {
                                if (are_zero_coeffs(A, B, D))
                                        C = 1;
                                else if (are_zero_coeffs(B, C, D))
                                        A = 1;
                                else if (are_zero_coeffs(A, C, D))
                                        B = 1;
                        }

                        bool are_zero_coeffs (const double coeff1,
                                              const double coeff2,
                                              const double coeff3) 
                        {
                                if (is_equal(coeff1, 0) &&
                                    is_equal(coeff2, 0) &&
                                    is_equal(coeff1, 0)
                                    )
                                        return true;
                                
                                return false;
                        }

                        void set_proportional_coeff (const plane_t &src_)
                        {
                                if (!is_equal(A, 0))
                                        proportional_coeff = src_.A / A;
                                else if (!is_equal(B, 0))
                                        proportional_coeff = src_.B / B;
                                else if (!is_equal(C, 0))
                                        proportional_coeff = src_.C / C;
                        }
        };
}