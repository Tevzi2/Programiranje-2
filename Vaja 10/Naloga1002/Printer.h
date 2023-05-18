#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <concepts>
#include <functional>

template <class From, class To>
concept convertible_to =
std::is_convertible_v<From, To> &&
requires {
    static_cast<To>(std::declval<From>());
};

template<typename T>
concept bool_method = requires(T f)
{
    {f("t")} -> convertible_to<bool>;
};

template<typename T>
concept bool_method_arg = requires(T f)
{
    {f("t", "t")} -> convertible_to<bool>;
};

template<typename T>
concept string_method = requires(T f)
{
    {f("t")} -> convertible_to<std::string>;
};

template<typename T>
concept number_concept = requires(T t)
{
    {t} -> convertible_to<uint32_t>;
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

        template<>
        void add<std::string>(std::string el)
        {
            queue.push_back(el);
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

        void remove(std::function<bool(std::string)> f)
        {
            for(auto it = queue.begin(); it < queue.end(); ++it)
                if(f(*it))
                {
                    queue.erase(it);
                    it--;
                }
        }

        void sort(std::function<bool(std::string, std::string)> f)
        {
            for(size_t i = 0; i < queue.size(); i++)
                for(size_t j = i+1; j < queue.size(); j++)
                    if(f(queue[i], queue[j]))
                        std::swap(queue[i], queue[j]);
        }

        void checkAndCorrect(std::function<bool(std::string)> check, std::function<std::string(std::string)> correct)
        {
            for (auto it = queue.begin(); it < queue.end(); ++it)
                if (check(*it)) *it = correct(*it);
        }

        void printSelect(std::function<bool(std::string)> f)
        {
            for(auto it = queue.begin(); it < queue.end(); ++it)
                if(f(*it)) std::cout << *it << std::endl;

            remove(f);
        }

        void modoifyAll(std::function<std::string(std::string)> f)
        {
            for(auto it = queue.begin(); it < queue.end(); ++it)
                *it = f(*it);
        }

        void removeIndex(uint32_t ind)
        {
            if(ind > queue.size()-1) return;

            queue.erase(queue.begin()+ind);
        }

        template <number_concept... Args>
        void removeIndex(Args... args)
        {
            std::vector<uint32_t> vec;

            ([&]
            {
                vec.push_back(args);
            } (), ...);

            std::sort(vec.begin(), vec.end(), [](uint32_t l, uint32_t r) -> bool { return l > r; });

            for(const auto& el : vec)
                removeIndex(el);
        }

    private:
        std::vector<std::string> queue{};
};
