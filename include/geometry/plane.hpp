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
                        double A = NAN;
                        double B = NAN;
                        double C = NAN;
                        double D = NAN;

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
                
                        bool is_equal2 (const plane_t &src_) const
                        {
                                double proportional_coeff = get_proportional_coeff(src_);

                                return is_equal(B, src_.B * proportional_coeff) &&
                                       is_equal(C, src_.C * proportional_coeff) &&
                                       is_equal(D, src_.D * proportional_coeff);
                        }

                        bool is_parallel2 (const plane_t &src_) const
                        {
                                double proportional_coeff = get_proportional_coeff(src_);
                                
                                if (is_equal( B * proportional_coeff, src_.B) &&
                                    is_equal( C * proportional_coeff, src_.C) &&
                                    !is_equal(D * proportional_coeff, src_.D)
                                )
                                        return true;

                                return false;
                        }

                        void set (const point_t &point_, const vector_t &vector1_, const vector_t &vector2_)
                        {
                                // if (!point_.is_valid())
                                //         throw std::runtime_error("Point has invalid coordinates to create plane.");

                                A =   vector1_.y * vector2_.z - vector2_.y * vector1_.z;
                                B = -(vector1_.x * vector2_.z - vector2_.x * vector1_.z);
                                C =   vector1_.x * vector2_.y - vector2_.x * vector1_.y;

                                D = - A * point_.x - B * point_.y - C * point_.z; 

                                reduce_zero_plane_coeffs();
                        }

                        double plane_equation_value (const double x_,
                                                     const double y_,
                                                     const double z_) const
                        {
                                return A * x_ + B * y_ + C * z_ + D;
                        }

                        void print () const
                        {
                                std::cout << A << "x + " 
                                          << B << "y + "
                                          << C << "z + "
                                          << D << " = 0\n";
                        }

                        point_t find_line_plane_intersection (const line_t &line_) const
                        {
                                double numerator   = - (A * line_.get_x0() + 
                                                        B * line_.get_y0() + 
                                                        C * line_.get_z0() + 
                                                        D);

                                double denominator = A * line_.get_x_coeff() + 
                                                     B * line_.get_y_coeff() + 
                                                     C * line_.get_z_coeff();

                                return line_.get_point_on_line(numerator / denominator);
                        }

                        bool line_is_in (const line_t &line_) const
                        {
                                point_t point1 = line_.get_point_on_line(0);
                                point_t point2 = line_.get_point_on_line(1);

                                return is_equal(plane_equation_value(point1.x, point1.y, point1.z), 0) &&
                                       is_equal(plane_equation_value(point2.x, point2.y, point2.z), 0);
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

                        bool are_zero_coeffs (const double coeff1_,
                                              const double coeff2_,
                                              const double coeff3_) const
                        {
                                return is_equal(coeff1_, 0) &&
                                       is_equal(coeff2_, 0) &&
                                       is_equal(coeff3_, 0);
                        }

                        double get_proportional_coeff (const plane_t &src_) const
                        {
                                if (!is_equal(A, 0))
                                        return src_.A / A;
                                else if (!is_equal(B, 0))
                                        return src_.B / B;
                                else if (!is_equal(C, 0))
                                        return src_.C / C;
                                
                                return NAN;
                        }
        };
}