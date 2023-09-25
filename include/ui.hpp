#pragma once

#include <vector>
#include <iostream>
#include <format>

#include "../include/utils.hpp"

namespace ui
{
        class input_t 
        {
                public:
                        size_t n_triangles   = 0;
                        size_t n_coordinates = 0;
                        std::vector<double> coordinates {};

                        inline input_t    ();
                        inline void print ();
                private:
                        inline void check_user_input ();
        };

        input_t::input_t ()
        {
                double input = 0;
                std::cin >> n_triangles;
                check_user_input();

                n_coordinates = n_triangles * N_DIMENSIONS 
                                            * N_TRIANGLE_VERTEXES;

                while (coordinates.size() != n_coordinates && std::cin >> input)
                        coordinates.push_back(input);

                if (std::cin.fail() && !std::cin.eof())
                        throw std::runtime_error("You need to enter digits.");        
        };

        void input_t::check_user_input ()
        {
                if (n_triangles < MIN_N_TRIANGLES2INPUT ||
                    n_triangles > MAX_N_TRIANGLES2INPUT) {
                        throw std::runtime_error(std::format(
                                                "You need to input from {} to {}",
                                                MIN_N_TRIANGLES2INPUT,
                                                MAX_N_TRIANGLES2INPUT)
                                                );
                }
        }

        void input_t::print ()
        {
                std::cout << "Number of triangles is " << n_triangles << "\n";
                std::cout << "Data:\n";

                for (auto it = coordinates.cbegin(); it != coordinates.cend(); it++)
                        std::cout << *it << " ";
        }
}