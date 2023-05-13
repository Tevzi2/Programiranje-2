#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

template<typename T>
concept bool_method = requires(T f)
{
    {f("t")} -> std::convertible_to<bool>;
};

template<typename T>
concept bool_method_arg = requires(T f)
{
    {f("t", "t")} -> std::convertible_to<bool>;
};

template<typename T>
concept string_method = requires(T f)
{
    {f("t")} -> std::convertible_to<std::string>;
};

class Printer {
    public:
        [[nodiscard]] std::string toString() const;

        void print();

        template<typename T>
        void add(T el)
        {
            std::stringstream ss;
            std::string out;

            ss << el;
            ss >> out;

            queue.push_back(out);
        }

        template<typename T, typename... Args>
        void add(T first, Args... args)
        {
            add(first);
            add(args...);
        }

        template<typename T>
        void addMultiple(std::vector<T> to_add)
        {
            std::for_each(to_add.begin(), to_add.end(), [this](auto el) {
                this->add(el);
            });
        }

        template<bool_method T>
        void remove(T f)
        {
            for(auto it = queue.begin(); it < queue.end(); it++)
                if(f(*it))
                    queue.erase(it);
        }

        template<bool_method_arg T>
        void sort(T f)
        {
            for(size_t i = 0; i < queue.size(); i++)
                for(size_t j = i+1; j < queue.size(); j++)
                    if(f(queue[i], queue[j]))
                        std::swap(queue[i], queue[j]);
        }

        template<bool_method T, string_method F>
        void checkAndCorrect(T check, F correct)
        {
            for (auto it = queue.begin(); it < queue.end(); it++)
                if (check(*it)) *it = correct(*it);
        }

        template<bool_method T>
        void printSelect(T f)
        {
            for(auto it = queue.begin(); it < queue.end(); it++)
                if(f(*it)) std::cout << *it;

            remove(f);
        }

        template<string_method T>
        void modoifyAll(T f)
        {
            for(auto it = queue.begin(); it < queue.end(); it++)
                *it = f(*it);
        }

    private:
        std::vector<std::string> queue{};
};
