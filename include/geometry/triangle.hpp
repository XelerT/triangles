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
                                if (!vertex_a_.is_valid() ||
                                    !vertex_b_.is_valid() ||
                                    !vertex_c_.is_valid()
                                    )
                                        throw std::runtime_error("Point has invalid coordinates to create triangle.");
                                
                                segment_a_b.set(vertex_a, vertex_b);
                                segment_b_c.set(vertex_b, vertex_c);
                                segment_c_a.set(vertex_c, vertex_a);
                                segment_a_c.set(vertex_a, vertex_c);

                                line_a_b.set(segment_a_b, vertex_a);
                                line_b_c.set(segment_b_c, vertex_b);
                                line_c_a.set(segment_c_a, vertex_c);

                                plane.set(vertex_a, segment_a_b, segment_a_c);
                        };

                        void print ()
                        {
                                std::cout << "side a:\n\t";
                                segment_a_b.print();

                                std::cout << "side c:\n\t";
                                segment_b_c.print();
                                
                                std::cout << "side b:\n\t";
                                segment_c_a.print();
                        }

                        point_t get_vertex_a () const { return vertex_a; }
                        point_t get_vertex_b () const { return vertex_a; }
                        point_t get_vertex_c () const { return vertex_a; }

                        vector_t get_segment_a_b () const { return segment_a_b; }
                        vector_t get_segment_b_c () const { return segment_b_c; }
                        vector_t get_segment_c_a () const { return segment_c_a; }
                        vector_t get_segment_a_c () const { return segment_a_c; }

                        line_t get_line_a_b () const { return line_a_b; }
                        line_t get_line_b_c () const { return line_b_c; }
                        line_t get_line_c_a () const { return line_c_a; }

                        plane_t get_plane () const { return plane; }

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
        };
}

