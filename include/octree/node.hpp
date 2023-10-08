#pragma once

#include <vector>
#include <iostream>

#include "geometry/geometry.hpp"
#include "utils.hpp"

namespace octree
{
        template <typename T>
        class node_t
        {
                std::vector<T> elements {};

                geometry::point_t middle {};
                geometry::point_t vertexes [N_CUBE_VERTEXES] {};
                
                geometry::point_t &up = vertexes[FIRST];
                geometry::point_t &bt = vertexes[SIXTH];

                node_t *children[N_OCTREE_CHILDREN] {};


                double cube_side_length      = 0;
                double cube_side_half_length = 0;

                void calculate_vertexes ()
                {
                        vertexes[FOURTH]     = bt;
                        vertexes[FOURTH].y  += cube_side_length;

                        vertexes[EIGHTH]     = bt;
                        vertexes[EIGHTH].x  += cube_side_length;

                        vertexes[SECOND]     = up;
                        vertexes[SECOND].z  -= cube_side_length;

                        vertexes[THIRD]      = up;
                        vertexes[THIRD].x   -= cube_side_length;

                        vertexes[SEVENTH]    = up;
                        vertexes[SEVENTH].y -= cube_side_length;

                        vertexes[FIFTH]      = bt;
                        vertexes[FIFTH].z   += cube_side_length; 

                }

                void calculate_cube_side_length ()
                {
                        cube_side_length = sqrt(
                                                (up.x - bt.x) * (up.x - bt.x) +
                                                (up.y - bt.y) * (up.y - bt.y) +
                                                (up.z - bt.z) * (up.z - bt.z)
                                                ) / sqrt(3);
                        cube_side_half_length = cube_side_length / 2;
                }

                void calculate_middle ()
                {
                        middle.set(
                                    (up.x + bt.x) / 2,
                                    (up.y + bt.y) / 2,
                                    (up.z + bt.z) / 2
                                );
                }

                geometry::point_t get_sector_bottom_vertex (octosector_t sector)
                {
                        geometry::point_t vertex = middle;

                        switch (sector) {
                        case FIRST:
                                return vertex;
                        case SECOND:
                                vertex.z -= cube_side_half_length;
                                return vertex;
                        case THIRD:
                                vertex.x -= cube_side_half_length;
                                return vertex;
                        case FOURTH:
                                vertex.x -= cube_side_half_length;
                                vertex.z -= cube_side_half_length;
                                return vertex;
                        case FIFTH:
                                vertex.x -= cube_side_half_length;
                                vertex.y -= cube_side_half_length;
                                return vertex;
                        case SIXTH:
                                vertex.x -= cube_side_half_length;
                                vertex.y -= cube_side_half_length;
                                vertex.z -= cube_side_half_length;
                                return vertex;
                        case SEVENTH:
                                vertex.y -= cube_side_half_length;
                                return vertex;
                        case EIGHTH:
                                vertex.y -= cube_side_half_length;
                                vertex.z -= cube_side_half_length;
                                return vertex;
                        default:
                                throw std::runtime_error("Unknown sector.");
                        }
                }

                geometry::point_t get_sector_upper_vertex (octosector_t sector)
                {
                        geometry::point_t vertex = middle;

                        switch (sector) {
                        case FIRST:
                                vertex.x += cube_side_half_length;
                                vertex.y += cube_side_half_length;
                                vertex.z += cube_side_half_length;
                                return vertex;
                        case SECOND:
                                vertex.x += cube_side_half_length;
                                vertex.y += cube_side_half_length;
                                return vertex;
                        case THIRD:
                                vertex.y += cube_side_half_length;
                                vertex.z += cube_side_half_length;
                                return vertex;
                        case FOURTH:
                                vertex.y += cube_side_half_length;
                                return vertex;
                        case FIFTH:
                                vertex.z += cube_side_half_length;
                                return vertex;
                        case SIXTH:
                                return vertex;
                        case SEVENTH:
                                vertex.x += cube_side_half_length;
                                vertex.z += cube_side_half_length;
                                return vertex;
                        case EIGHTH:
                                vertex.x += cube_side_half_length;
                                return vertex;
                        default:
                                throw std::runtime_error("Unknown sector.");
                        } 
                }

                public:        
                        node_t () = default;

                        node_t (const geometry::point_t &middle_,
                                const geometry::point_t &bottom_low_left_vertex_, 
                                const geometry::point_t &upper_top_right_vertex_)
                        {                                
                                middle          = middle_;
                                vertexes[SIXTH] = bottom_low_left_vertex_;
                                vertexes[FIRST] = upper_top_right_vertex_;
                                
                                calculate_cube_side_length();

                                calculate_vertexes();
                        };

                        node_t (T elem_, const geometry::point_t &bottom_low_left_vertex_, 
                                          const geometry::point_t &upper_top_right_vertex_) 
                        {                                
                                vertexes[SIXTH] = bottom_low_left_vertex_;
                                vertexes[FIRST] = upper_top_right_vertex_;

                                add_element(elem_);

                                calculate_cube_side_length();

                                calculate_vertexes();
                                calculate_middle();
                        };

                        ~node_t ()
                        {
                                for (int i = 0; i < N_OCTREE_CHILDREN; i++)
                                        if (children[i])
                                                delete children[i];
                        };

                        void add_element (const T &element_)
                        {
                                elements.push_back(element_);
                        }

                        template <typename F>
                        void insert (const T elem, F select_octangle)
                        {
                                octosector_t sector = select_octangle(elem, middle);
                                if (sector == INVALID || cube_side_length <= MIN_CUBE_SIDE) {
                                        add_element(elem);
                                        return;
                                }

                                if (!(children[sector])) {
                                        geometry::point_t bottom_low_left_vertex = get_sector_bottom_vertex(sector);
                                        geometry::point_t upper_top_right_vertex = get_sector_upper_vertex(sector);

                                        children[sector] = new node_t<T>{elem, bottom_low_left_vertex,
                                                                               upper_top_right_vertex};
                                } else {
                                        children[sector]->insert(elem, select_octangle);
                                }
                        }

                        
                        void insert_elements_by_node(std::vector<std::vector<T>> &divided_elements)
                        {                            
                                for (uint8_t i = 0; i < N_OCTREE_CHILDREN; i++) {
                                        if (children[i]) {

                                                children[i]->insert_elements_by_node(divided_elements);
                                        }
                                }
                                divided_elements.push_back(elements);
                        }

                        void print_tabs (const size_t n_tabs2print) const
                        {
                                for (size_t i = 0; i < n_tabs2print; i++) {
                                        std::cout << "\t";
                                }
                        }

                        void dump (const size_t layer) const
                        {
                                std::cout << "{";
                                std::cout << " n_elems=" << elements.size() << "\n";
                                print_tabs(layer);

                                if (elements.size()) {
                                        std::cout << "triangle=\n";
                                        elements[0].print();
                                }
                                std::cout << "\n";
                                print_tabs(layer);

                                for (int i = 0; i < N_OCTREE_CHILDREN; i++) {
                                        if (children[i]) {
                                                children[i]->dump(layer + 1);
                                                std::cout << "\n";
                                                print_tabs(layer);
                                                std::cout << "}\n";
                                        }
                                }
                        }
        };
}
