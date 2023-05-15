#pragma once

#include <vector>
#include <iostream>
#include <Point.h>

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

template<>
void fillDefault<Point>(std::vector<Point>& vector, uint32_t n)
{
    std::srand(time(0));

    for(uint32_t i = 0; i < n; i++)
        vector.push_back(Point(rand()%101, rand()%101));
}

template<typename T>
void print(const std::vector<T>& vector)
{
    for(uint32_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << std::endl;
}

template<typename T>
std::vector<T> reverse(const std::vector<T>& vector)
{
    std::vector<T> out;

    for(int i = vector.size()-1; i >= 0; i--)
        out.push_back(vector[i]);

    return out;
}

template<typename T>
std::vector<T> mergeVectors(const std::vector<std::vector<T>>& vectorsToMerge)
{
    std::vector<T> out;

    for(const std::vector<T>& vector : vectorsToMerge)
    {
        for(const T& el : vector)
            out.push_back(el);
    }

    return out;
}