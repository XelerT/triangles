#pragma once

#include <cmath>

#include "vector.hpp"

namespace geometry
{
        class line_t                    // set parametrically
        {
                private:
                        // line<double, 3>
                        double x_coeff = NAN;
                        double x0      = NAN;

                        double y_coeff = NAN;
                        double y0      = NAN;

                        double z_coeff = NAN;
                        double z0      = NAN;

                public:
                        line_t () = default;
                        line_t (const vector_t &guide_vector_, const point_t &line_point_)
                        {
                                if (!line_point_.is_valid())
                                        throw std::runtime_error("Point has invalid coordinates to create line.");

                                x_coeff = guide_vector_.x;
                                x0      = line_point_.x;

                                y_coeff = guide_vector_.y;
                                y0      = line_point_.y;

                                z_coeff = guide_vector_.z;
                                z0      = line_point_.z;
                        };

                        double get_x_value (const double parameter_) const
                        {
                                return x_coeff * parameter_ + x0;
                        }

                        double get_y_value (const double parameter_) const
                        {
                                return y_coeff * parameter_ + y0;
                        }

                        double get_z_value (const double parameter_) const
                        {
                                return z_coeff * parameter_ + z0;
                        }

                        double get_x_coeff () const { return x_coeff; }
                        double get_y_coeff () const { return y_coeff; }
                        double get_z_coeff () const { return z_coeff; }

                        double get_x0      () const { return x0; }
                        double get_y0      () const { return y0; }
                        double get_z0      () const { return z0; }

                        point_t get_point_on_line (const double parameter_) const
                        {
                                point_t point {
                                                get_x_value(parameter_),
                                                get_y_value(parameter_),
                                                get_z_value(parameter_)
                                              };

                                return point;
                        }

                        void print () 
                        {
                                std::cout << "x = " << x_coeff << "t + (" << x0 << ")\n";
                                std::cout << "y = " << y_coeff << "t + (" << y0 << ")\n";
                                std::cout << "z = " << z_coeff << "t + (" << z0 << ")\n";
                        }

                        void set (const vector_t &guide_vector_, const point_t &line_point_)
                        {
                                if (!line_point_.is_valid())
                                        throw std::runtime_error("Point has invalid coordinates to create line.");

                                x_coeff = guide_vector_.x;
                                x0      = line_point_.x;

                                y_coeff = guide_vector_.y;
                                y0      = line_point_.y;

                                z_coeff = guide_vector_.z;
                                z0      = line_point_.z;
                        }

                        point_t intersects_line_at (const line_t &line_) const 
                        {
                                double param = (line_.x0 - x0) / (x_coeff - line_.x_coeff);
                                point_t point = get_point_on_line(param);
                                if (point.is_valid())
                                        return point;

                                param = (line_.y0 - y0) / (y_coeff - line_.y_coeff);
                                point = get_point_on_line(param);
                                if (point.is_valid())
                                        return point;

                                param = (line_.z0 - z0) / (z_coeff - line_.z_coeff);
                                point = get_point_on_line(param);

                                return point;
                        }
        };
}