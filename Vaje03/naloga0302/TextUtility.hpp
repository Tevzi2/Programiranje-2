#pragma once

#include <string>
#include <sstream>
#include <iostream>

class TextUtility
{
    public:
        [[nodiscard]] static bool isAlphanumeric(const std::string &str);

        [[nodiscard]] static std::string difference(const std::string &str1, const std::string &str2);

        [[nodiscard]] static std::string replace(const std::string &str, const std::string &searchStr, const std::string &replaceStr);

        [[nodiscard]] static std::string concat(const std::string &str1, const std::string &str2);

        [[nodiscard]] static std::string longestWord(const std::string &str);

    private:
        TextUtility();

        [[nodiscard]] static inline bool isCharAlphanumeric(const char& c);

        static void replaceAtLocationToLocation(std::string &str, const std::string& replaceStr, uint32_t from, uint32_t to);
};