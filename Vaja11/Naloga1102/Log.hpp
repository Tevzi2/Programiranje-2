#pragma once

#include <LogType.hpp>
#include <fstream>
#include <source_location.hpp> // <-- idk somethign is wacky about my stdlibc++ or libc++ version that doesnt support the header
#include <chrono>
#include <ctime>

class Log {
    public:
        explicit Log(LogType type, source_location s = source_location::current());

        ~Log();

        template<typename T>
        Log& operator<<(const T& msg)
        {
            f << msg;

            return *this;
        }
    private:
        std::ofstream f;
        std::string file = "log.txt";
};
