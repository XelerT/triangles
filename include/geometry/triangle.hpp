#pragma once

#include "../utils.hpp"
#include "point.hpp"
#include "line.hpp"
#include "vector.hpp"
#include "plane.hpp"

namespace geometry
{
        class triangle_t 
        {
                public:
                        triangle_t () = default;

                        explicit triangle_t (const point_t &vertex_a_,
                                             const point_t &vertex_b_,
                                             const point_t &vertex_c_)
                                             : 
                                             vertex_a(vertex_a_),
                                             vertex_c(vertex_c_),
                                             vertex_b(vertex_b_)
                        {
                                // if (!vertex_a_.is_valid() ||
                                //     !vertex_b_.is_valid() ||
                                //     !vertex_c_.is_valid()
                                //     )
                                //         throw std::runtime_error("Point has invalid coordinates to create triangle.");
                                
                                segment_a_b.set(vertex_a, vertex_b);
                                segment_b_c.set(vertex_b, vertex_c);
                                segment_c_a.set(vertex_c, vertex_a);
                                segment_a_c.set(vertex_a, vertex_c);

                                line_a_b.set(segment_a_b, vertex_a);
                                line_b_c.set(segment_b_c, vertex_b);
                                line_c_a.set(segment_c_a, vertex_c);

                                plane.set(vertex_a, segment_a_b, segment_a_c);

                                dot_ab_ab = segment_a_b.scalar_product(segment_a_b);
                                dot_ab_ac = segment_a_b.scalar_product(segment_a_c);
                                dot_ac_ac = segment_a_c.scalar_product(segment_a_c);
                        };

                        void print () const 
                        {
                                std::cout << "side a:\n\t";
                                segment_a_b.print();

                                std::cout << "side c:\n\t";
                                segment_b_c.print();
                                
                                std::cout << "side b:\n\t";
                                segment_c_a.print();
                        }

                        point_t get_vertex_a () const { return vertex_a; }
                        point_t get_vertex_b () const { return vertex_b; }
                        point_t get_vertex_c () const { return vertex_c; }

                        vector_t get_segment_a_b () const { return segment_a_b; }
                        vector_t get_segment_b_c () const { return segment_b_c; }
                        vector_t get_segment_c_a () const { return segment_c_a; }
                        vector_t get_segment_a_c () const { return segment_a_c; }

                        line_t get_line_a_b () const { return line_a_b; }
                        line_t get_line_b_c () const { return line_b_c; }
                        line_t get_line_c_a () const { return line_c_a; }

                        plane_t get_plane () const { return plane; }

                        double get_dot_ab_ab () const { return dot_ab_ab; }
                        double get_dot_ab_ac () const { return dot_ab_ac; }
                        double get_dot_ac_ac () const { return dot_ac_ac; }

                        bool is_equal (const triangle_t &triangle_) const
                        {
                                return vertex_a.is_equal2(triangle_.get_vertex_a()) &&
                                       vertex_b.is_equal2(triangle_.get_vertex_b()) &&
                                       vertex_c.is_equal2(triangle_.get_vertex_c());
                        }

                        bool has_inside (const point_t &point_) const
                        {                                
                                auto s0_t0 = calculate_distance_params2(point_);
                                double s0_t0_sum = s0_t0.first + s0_t0.second;
                                
                                if (is_equal_lower(s0_t0_sum, 1))
                                        if (is_equal_greater(s0_t0.first, 0))
                                                if (is_equal_greater(s0_t0.second, 0))
                                                        return true;
                                
                                return false;
                        }

                        bool line_intersect_in_triangles (const line_t &line_, const triangle_t &triangle_) const
                        {
                                bool intersect = false;

                                point_t point = plane.find_line_plane_intersection(line_);
                                if (point.is_valid()) {
                                        intersect = triangle_.has_inside(point) &&
                                                              has_inside(point);

                                } else if (plane.line_is_in(line_)) {
                                        if (is_equal(triangle_)) {
                                                return true;
                                        }
                                        intersect = line_intersect_triangles(line_, triangle_);
                                }

                                return intersect;
                        }

                        bool intersects (const triangle_t &triangle_) const
                        {
                                plane_t plane_ = triangle_.get_plane();

                                if (plane_.is_parallel2(plane))
                                        return false;

                                if (in(triangle_))
                                        return true;

                                if (triangle_.in(*this))
                                        return true;
                                
                                return false;
                        }

                private:
                        point_t vertex_a;
                        point_t vertex_b;
                        point_t vertex_c;

                        vector_t segment_a_b;
                        vector_t segment_b_c;
                        vector_t segment_c_a;
                        vector_t segment_a_c;
                        
                        line_t line_a_b;
                        line_t line_b_c;
                        line_t line_c_a;

                        plane_t plane;

                        double dot_ab_ab;
                        double dot_ab_ac;
                        double dot_ac_ac;

                        std::pair<double, double>
                        calculate_distance_params2 (const point_t &point_) const
                        {
                                // if (!point_.is_valid())
                                //         throw std::runtime_error("Point has invalid coordinates"                \
                                //                                  " to calculate distance to triangle.");

                                vector_t vec_d (point_, vertex_a);

                                double distance_d = segment_a_b.scalar_product(vec_d);
                                double distance_e = segment_a_c.scalar_product(vec_d);

                                double distance_inv_s0_t0_divisor = calculate_distance_inv_s0_t0_divisor();
                                double s0 = calculate_distance_s0(distance_e, distance_d, distance_inv_s0_t0_divisor);
                                double t0 = calculate_distance_t0(distance_e, distance_d, distance_inv_s0_t0_divisor);

                                return {s0, t0};                             
                        };

                        double calculate_distance_inv_s0_t0_divisor () const
                        {
                                return 1 / (dot_ab_ab * dot_ac_ac - dot_ab_ac * dot_ab_ac);
                        }

                        double calculate_distance_s0 (const double e_, const double d_,
                                                      const double distance_inv_s0_t0_divisor) const
                        {
                                return (dot_ab_ac * e_ - dot_ac_ac * d_) * distance_inv_s0_t0_divisor;
                        }

                        double calculate_distance_t0 (double e_, double d_,
                                                      const double distance_inv_s0_t0_divisor) const
                        {
                                return (dot_ab_ac * d_ - dot_ab_ab * e_) * distance_inv_s0_t0_divisor;
                        }

                        bool line_intersect_triangles (const line_t &line_, const triangle_t  &triangle_) const
                        {
                                bool intersect = false;

                                point_t point = line_.intersects_line_at(triangle_.get_line_a_b());
                                if (point.is_valid())
                                        intersect = triangle_.has_inside(point) &&
                                                              has_inside(point);
                                if (!intersect) {
                                        point = line_.intersects_line_at(triangle_.get_line_b_c());
                                        if (point.is_valid())
                                                intersect = triangle_.has_inside(point) &&
                                                                      has_inside(point);
                                }
                                if (!intersect) {
                                        point = line_.intersects_line_at(triangle_.get_line_c_a());
                                        if (point.is_valid())
                                                intersect = triangle_.has_inside(point) &&
                                                                      has_inside(point);
                                }

                                return intersect;
                        }

                        bool in (const triangle_t &triangle_) const
                        {
                                bool intersect = line_intersect_in_triangles(triangle_.get_line_a_b(), triangle_);
                                if (intersect)
                                        return intersect;

                                intersect = line_intersect_in_triangles(triangle_.get_line_b_c(), triangle_);
                                if (intersect)
                                        return intersect;

                                intersect = line_intersect_in_triangles(triangle_.get_line_c_a(), triangle_);
                                
                                return intersect;
                        }

        };
}

