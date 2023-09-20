#pragma once

#include "point.hpp"
#include "line.hpp"
#include "vector.hpp"

namespace geometry
{
        class triangle_t 
        {
                public:
                        point_t vertex_a;
                        point_t vertex_c;
                        point_t vertex_b;

                        triangle_t () = default;

                        explicit triangle_t (const point_t vertex_a_,
                                             const point_t vertex_c_,
                                             const point_t vertex_b_)
                                             : 
                                             vertex_a(vertex_c_),
                                             vertex_c(vertex_b_),
                                             vertex_b(vertex_c_)
                        {
                                if (vertex_a_.get_status() == INVALID ||
                                    vertex_c_.get_status() == INVALID ||
                                    vertex_b_.get_status() == INVALID
                                    )
                                        std::runtime_error("Point has invalid coordinates.");

                                set_segments();
                                set_line();
                        };

                        void print_sides () 
                        {
                                std::cout << "side a:\n\t";
                                segment_a_c.print_vector();

                                std::cout << "side c:\n\t";
                                segment_c_b.print_vector();
                                
                                std::cout << "side b:\n\t";
                                segment_b_a.print_vector();
                        }
                        
                private:
                        line_t line_a_c;
                        line_t line_c_b;
                        line_t line_b_a;

                        vector_t segment_a_c;
                        vector_t segment_c_b;
                        vector_t segment_b_a;

                        void set_segments ()
                        {
                                segment_a_c(vertex_a, vertex_c);
                                segment_c_b(vertex_c, vertex_b);
                                segment_b_a(vertex_b, vertex_a);
                        }

                        void set_lines ()
                        {
                                line_a_c(segment_a_c, vertex_a);
                                line_c_b(segment_c_b, vertex_c);
                                line_b_a(segment_b_a, vertex_b);
                        }
        }
}

