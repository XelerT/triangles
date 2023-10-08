#pragma once

#include <vector>
#include <utility>
#include <iostream>

#include "utils.hpp"

std::pair<size_t, std::vector<double>> get_user_input ();
void check_user_input (size_t n_triangles);
void print_input      (std::pair<size_t, std::vector<double>> &input);
