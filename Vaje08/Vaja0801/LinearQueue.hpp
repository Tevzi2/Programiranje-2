#pragma once

#include <vector>
#include <exception>
#include <string>
#include <Time.hpp>
#include <iostream>

template <typename T>
class LinearQueue
{
    public:
        explicit LinearQueue(uint32_t capacity = 10)
            :capacity(capacity)
        {
            ;
        }

        void change_capacity(uint32_t capacity)
        {
            if(capacity == 0) return;

            this->capacity = capacity;

            while(values.size() > capacity)
                values.erase(values.begin());
        }

        [[nodiscard]] bool is_empty() const
        {
            return values.size() == 0;
        }

        [[nodiscard]] size_t size() const
        {
            return values.size();
        }

        [[nodiscard]] const T* element() const
        {
            if(this->size() == 0) return nullptr;

            return &values[0];
        }

        void add(T element)
        {
            if(values.size() == capacity) return;

            values.push_back(element);
        }

        bool remove()
        {
            if(this->size() == 0) return false;

            values.erase(values.begin());

            return true;
        }

        [[nodiscard]] std::string to_string() const
        {
            std::string values_accumulator = "Values: ";

            for(const auto& el : this->values)
                values_accumulator += std::to_string(el) + " ";

            return values_accumulator;
        }



        template<typename F>
        friend void reverse(LinearQueue<F>& queue);

        template<typename F>
        friend F getMax(const LinearQueue<F>& queue);

        template<typename F>
        friend void half(LinearQueue<F>& queue);

        template<typename F>
        friend void removeDuplicates(LinearQueue<F>& queue);

    private:
        uint32_t capacity;
        std::vector<T> values{};
};

template <typename T>
void reverse(LinearQueue<T>& queue)
{
    std::vector<T> out;

    for(int32_t i = queue.values.size() - 1; i >= 0; i--)
        out.push_back(queue.values[i]);

    queue.values = out;
}

template <typename T>
T getMax(const LinearQueue<T>& queue)
{
    T current = queue.values[0];

    for(const auto& el : queue.values)
        if(el > current)
            current = el;

    return current;
}

template<typename T>
void half(LinearQueue<T>& queue)
{
    std::vector<T> out((size_t)queue.values.size()/2);

    for(uint32_t i = 0; i < (size_t)queue.values.size()/2; i++)
        out[i] = queue.values[i];

    queue.values = out;
}

template<typename T>
void removeDuplicates(LinearQueue<T>& queue)
{
    std::vector<T> out;

    for(const auto& el : queue.values)
    {
        if(std::find(out.begin(), out.end(), el) == out.end()) out.push_back(el);
    }

    queue.values = out;
}

template<typename T>
void print(const LinearQueue<T>& queue)
{
    std::cout << queue.to_string() << std::endl;
}

template <>
class LinearQueue<Time>
{
    public:
        explicit LinearQueue(uint32_t capacity = 10)
            :capacity(capacity)
        {
            ;
        }

        void change_capacity(uint32_t capacity)
        {
            if(capacity == 0) return;

            this->capacity = capacity;

            while(values.size() > capacity)
                values.erase(values.begin());
        }

        [[nodiscard]] bool is_empty() const
        {
            return values.size() == 0;
        }

        [[nodiscard]] size_t size() const
        {
            return values.size();
        }

        [[nodiscard]] const Time* element() const
        {
            if(this->size() == 0) return nullptr;

            return &values[0];
        }

        void add(Time element)
        {
            if(values.size() == capacity) return;

            values.push_back(element);
        }

        bool remove()
        {
            if(this->size() == 0) return false;

            values.erase(values.begin());

            return true;
        }

        [[nodiscard]] std::string to_string() const
        {
            std::string values_accumulator = "Values: ";

            for(const auto& el : this->values)
                values_accumulator += el.toString() + " ";

            return values_accumulator;
        }

        template<typename F>
        friend void reverse(LinearQueue<F>& queue);

        template<typename F>
        friend F getMax(const LinearQueue<F>& queue);

        template<typename F>
        friend void half(LinearQueue<F>& queue);

        template<typename F>
        friend void removeDuplicates(LinearQueue<F>& queue);

    private:
        uint32_t capacity;
        std::vector<Time> values{};
};

template <>
Time getMax<Time>(const LinearQueue<Time>& queue)
{
    Time current = queue.values[0];

    for(const auto& el : queue.values)
        if( el.toSeconds() > current.toSeconds())
            current = el;

    return current;
}