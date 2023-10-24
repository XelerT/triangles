#pragma once

#include "octree/node.hpp"

namespace octree
{
        template <typename T>
        class tree_t
        {
                size_t size = 0;

                node_t<T> *root = nullptr;

                node_t<T>* get_root () const { return root; };
                void null_root_ptr  () { root = nullptr; }

                public:
                        tree_t (const geometry::point_t &bottom_low_left_vertex_, 
                                const geometry::point_t &upper_top_right_vertex_)
                        {
                                double middle_x = (bottom_low_left_vertex_.x + upper_top_right_vertex_.x) / 2; 
                                double middle_y = (bottom_low_left_vertex_.y + upper_top_right_vertex_.y) / 2; 
                                double middle_z = (bottom_low_left_vertex_.z + upper_top_right_vertex_.z) / 2; 

                                geometry::point_t middle {middle_x, middle_y, middle_z};

                                root = new node_t<T>{middle, bottom_low_left_vertex_, upper_top_right_vertex_};
                        };

                        ~tree_t ()
                        {
                                delete root;
                        };

                        tree_t (const tree_t &tree_) = delete;

                        tree_t (tree_t &&tree_)
                        {
                                size = tree_.get_size();
                                root = tree_.get_root();

                                tree_.null_root_ptr();   
                        };

                        tree_t& operator= (const tree_t &tree_) = delete;

                        tree_t& operator= (tree_t &&tree_)
                        {
                                *this = tree_;             
                        };

                        size_t get_size () const { return size; };

                        template <typename F>
                        void insert (T elem, F select_octangle)
                        {
                                root->insert(elem, select_octangle);
                                size++;
                        }

                        std::vector<std::vector<T>>
                        get_elements_by_node()
                        {
                                std::vector<std::vector<T>> divided_elements;
                                root->get_elements_by_node(divided_elements);

                                return divided_elements;
                        }

                        void dump () const
                        {
                                std::cout << "Size = " << size << "\n";
                                root->dump(0);     
                        }

                        void find_elems_intersections_indexes (std::vector<std::pair<int, int>> &intersected_triangles_indexes) 
                        {
                                root->find_elements_intersections_indexes(intersected_triangles_indexes);
                        }
        };
}