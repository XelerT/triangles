#pragma once

#include <vector>
#include <iterator>

template <typename T>
void print (const std::vector<T> &vec)
{
        for (auto it = vec.cbegin(); it != vec.cend(); it++)
                std::cout << *it << " ";

        std::cout << std::endl;
}

template <typename T>
void println (const std::vector<T> &vec)
{
        for (auto it = vec.cbegin(); it != vec.cend(); it++)
                std::cout << *it << "\n";
}

template <typename T>
auto find (const std::vector<T> &vec, const T &elem)
{
        for (auto it = vec.begin(); it != vec.end(); it++)
                if (*it == elem)
                        return it;
        
        return vec.end();
}
