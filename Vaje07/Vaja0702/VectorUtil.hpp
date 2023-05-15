#pragma once

#include <vector>
#include <iostream>
#include <Point.h>
#include <ColorCode.hpp>
#include <cmath>

template<typename T>
void fillDefault(std::vector<T>& vector, uint32_t n)
{
    for(uint32_t i = 0; i < n; i++)
        vector.push_back(T());
}

template<>
void fillDefault<int>(std::vector<int>& vector, uint32_t n)
{
    std::srand(time(0));

    for(uint32_t i = 0; i < n; i++)
        vector.push_back(static_cast<int>(rand() % 100 + 1));
}

template<typename T>
void print(const std::vector<T>& vector)
{
    for(uint32_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << std::endl;
}

template<typename T>
[[nodiscard]] std::vector<T> reverse(const std::vector<T>& vector)
{
    std::vector<T> out;

    for(int i = vector.size()-1; i >= 0; i--)
        out.push_back(vector[i]);

    return out;
}

template<typename T>
[[nodiscard]] std::vector<T> mergeVectors(const std::vector<std::vector<T>>& vectorsToMerge)
{
    std::vector<T> out;

    for(const std::vector<T>& vector : vectorsToMerge)
    {
        for(const T& el : vector)
            out.push_back(el);
    }

    return out;
}

template<uint32_t C = Green, typename T>
void printColor(const std::vector<T>& vector)
{
    for(const auto& element : vector)
        std::cout << "\033[" << (int)C << "m" << element << "\033[0m" << std::endl;
}

template<typename T>
[[nodiscard]] std::vector<std::vector<T>> slice(const std::vector<T>& vector, uint32_t n)
{
    if(n > vector.size()) return {};

    std::vector<std::vector<T>> out(round((float)vector.size()/2.0f));

    uint32_t counter = 0;
    uint32_t i = 0;

    for(const auto& el : vector)
    {
        out[i].push_back(el);

        counter++;

        if(counter % 2 == 0) i++;
    }

    return out;
}

template<typename T>
[[nodiscard]] std::vector<T> removeDuplicates(const std::vector<T>& vector)
{
    std::vector<T> out;

    for(const auto& el : vector)
    {
        if(std::find(out.begin(), out.end(), el) == out.end()) out.push_back(el);
    }

    return out;
}

template<typename T>
[[nodiscard]] std::vector<T> doubleVector(const std::vector<T>& vector)
{
    std::vector<T> out;

    for(const auto& el : vector)
    {
        out.push_back(el);
        out.push_back(el);
    }

    return out;
}

template<typename T>
[[nodiscard]] std::vector<T> cut(const std::vector<T>& vector, uint32_t start_index, uint32_t end_index)
{
    std::vector<T> out;

    if(start_index >= vector.size() || end_index > vector.size()) return {};

    for(uint32_t i = start_index; i < end_index; i++)
        out.push_back(vector[i]);

    return out;
}

template<typename T, typename F = T>
[[nodiscard]] uint32_t count_type(const std::vector<F>& vector)
{
    uint32_t counter = 0;

    for(const auto& el : vector)
        if(dynamic_cast<T*>(el)) counter++;

    return counter;
}
