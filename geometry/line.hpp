#include "vector.h"

namespace geometry
{
        class line_t                    // set parametrically
        {
                private:
                        double x_coeff = NAN;
                        double x0      = NAN;

                        double y_coeff = NAN;
                        double y0      = NAN;

                        double z_coeff = NAN;
                        double z0      = NAN;

                public:
                        line_t () = default;
                        line_t (const line_t &src) {}
                        line_t (const vector_t &guide_vector_, const point_t &line_point_)
                        {
                                if (line_point_.get_status() == INVALID)
                                        ERROR_EXIT(INVALID_POINT, "Point has invalid coordinates.");

                                x_coeff = guide_vector_.x;
                                x0      = line_point_.x0;

                                y_coeff = guide_vector_.y;
                                y0      = line_point_.y0;

                                z_coeff = guide_vector_.z;
                                z0      = line_point_.z0;
                        };

                        ~line_t () {};

                        double get_x_value (const double parameter_)
                        {
                                return x_coeff * parameter_ + x0;
                        }

                        double get_y_value (const double parameter_)
                        {
                                return y_coeff * parameter_ + y0;
                        }

                        double get_z_value (const double parameter_)
                        {
                                return z_coeff * parameter_ + z0;
                        }

                        point_t* get_point_on_line (const double parameter_)
                        {
                                point_t *point = new point_t {
                                                              get_x_value(parameter_),
                                                              get_y_value(parameter_),
                                                              get_z_value(parameter_)
                                                             };
                                if (point->get_status() == INVALID) {
                                        delete point;
                                        std::cout << parameter_ << " is invalid for this line.\n"; // TODO: write error func
                                        return nullptr;
                                }

                                return point;
                        }
        }
}