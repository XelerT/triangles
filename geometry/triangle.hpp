#pragma once

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

                        explicit triangle_t (const point_t vertex_a_,
                                             const point_t vertex_b_,
                                             const point_t vertex_c_)
                                             : 
                                             vertex_a(vertex_a_),
                                             vertex_c(vertex_c_),
                                             vertex_b(vertex_b_),

                                             segment_a_b(vertex_a, vertex_b),
                                             segment_b_c(vertex_b, vertex_c),
                                             segment_c_a(vertex_c, vertex_a),
                                             segment_a_c(vertex_a, vertex_c),

                                             line_a_b(segment_a_b, vertex_a),
                                             line_b_c(segment_b_c, vertex_b),
                                             line_c_a(segment_c_a, vertex_c),

                                             plane(vertex_a, segment_a_b, segment_a_c)

                        {
                                if (vertex_a_.get_status() == INVALID ||
                                    vertex_b_.get_status() == INVALID ||
                                    vertex_c_.get_status() == INVALID
                                    )
                                        throw std::runtime_error("Point has invalid coordinates to create triangle.");

                                // set_segments();
                                // set_lines();
                                // set_triangle_plane();
                        };

                        void print_sides () 
                        {
                                std::cout << "side a:\n\t";
                                segment_a_b.print_vector();

                                std::cout << "side c:\n\t";
                                segment_b_c.print_vector();
                                
                                std::cout << "side b:\n\t";
                                segment_c_a.print_vector();
                        }
                        
                private:
                        point_t vertex_a;
                        point_t vertex_b;
                        point_t vertex_c;

                        line_t line_a_b;
                        line_t line_b_c;
                        line_t line_c_a;

                        vector_t segment_a_b;
                        vector_t segment_b_c;
                        vector_t segment_c_a;
                        vector_t segment_a_c;

                        plane_t plane;

                        // void set_segments ()
                        // {
                        //         segment_a_b(vertex_a, vertex_b);
                        //         segment_b_c(vertex_b, vertex_c);
                        //         segment_c_a(vertex_c, vertex_a);
                        //         segment_a_c(vertex_a, vertex_c);
                        // }

                        // void set_lines ()
                        // {
                        //         line_a_b(segment_a_b, vertex_a);
                        //         line_b_c(segment_b_c, vertex_b);
                        //         line_c_a(segment_c_a, vertex_c);
                        // }

                        // void set_triangle_plane ()
                        // {
                        //         plane(vertex_a, segment_a_b, segment_a_c);
                        // }
        };
}

