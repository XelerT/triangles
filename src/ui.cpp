#include "ui.hpp"

using namespace std;

pair<size_t, vector<double>> get_user_input ()
{
        size_t n_triangles;
        cin >> n_triangles;
        check_user_input(n_triangles);

        size_t n_coordinates = n_triangles * N_DIMENSIONS * N_TRIANGLE_VERTEXES;

        vector<double> coordinates {};
        double input;

        while (coordinates.size() != n_coordinates && std::cin >> input)
               coordinates.push_back(input);

                if (std::cin.fail() && !std::cin.eof())
                        throw std::runtime_error("You need to enter digits.");

        return {n_triangles, coordinates}; 
}

void check_user_input (size_t n_triangles)
{
        if (n_triangles < MIN_N_TRIANGLES2INPUT || n_triangles > MAX_N_TRIANGLES2INPUT) {
                std::cerr << "You need to input from " 
                          << MIN_N_TRIANGLES2INPUT
                          << " to "
                          << MAX_N_TRIANGLES2INPUT
                          << "\n";
                      throw std::runtime_error("Wrong input.");
        }
}

void print_input (pair<size_t, vector<double>> input)
{
        std::cout << "Number of triangles is " << input.first << "\n";
        std::cout << "Data:\n";

        for (auto elem : input.second)
                std::cout << elem << " ";
}
