#include "TextUtility.hpp"

[[nodiscard]] bool TextUtility::isAlphanumeric(const std::string &str)
{
    return std::all_of(str.cbegin(), str.cend(), [](char c){
        return isCharAlphanumeric(c);
    });
}

[[nodiscard]] std::string TextUtility::difference(const std::string &str1, const std::string &str2)
{
    size_t biggerSize = str1.size() > str2.size() ? str1.size() : str2.size();
    size_t smallerSize = str1.size() < str2.size() ? str1.size() : str2.size();
    std::string out;

    for(size_t i = 0; i < biggerSize; i++)
    {
        if(i > smallerSize - 1)
        {
            out += '-';
            continue;
        }

        if(str1[i] == str2[i])
            out += str1[i];
        else
            out += '-';
    }

    return out;
}

[[nodiscard]] std::string TextUtility::replace(const std::string &str, const std::string &searchStr, const std::string &replaceStr)
{
    if(str.size() < searchStr.size() || str.size() < replaceStr.size()) return str;

    std::string out = str;
    size_t size = str.size()-searchStr.size();

    for(size_t i = 0; i < size; i++)
    {
        if(std::strcmp(out.substr(i, searchStr.size()).c_str(), searchStr.c_str()) == 0)
        {
            // FIXED: fix for when search word is longer then the replace word
            replaceAtLocationToLocation(out, replaceStr, i, i + searchStr.size());

            // pol ko se zamenjata besedi pristej i velikost zamenjane besede
            i += replaceStr.size()-1;
            // in size spremeni na out.size()-searchStr.size()
            size = out.size()-searchStr.size();
        }
    }

    return out;
}

[[nodiscard]] std::string TextUtility::concat(const std::string &str1, const std::string &str2)
{
    return str1 + str2;
}

[[nodiscard]] std::string TextUtility::longestWord(const std::string &str)
{
    std::string originalCopy = str;
    std::string current;
    size_t pos = 0;

    while((pos = originalCopy.find(' ')) != std::string::npos)
    {
        std::string now = originalCopy.substr(0, pos);
        if(now.size() > current.size())
            current = now;

        originalCopy.erase(0, pos + 1);
    }

    if(originalCopy.size() > current.size()) return originalCopy;

    return current;
}

[[nodiscard]] inline bool TextUtility::isCharAlphanumeric(const char& c)
{
    return (c <= '9' && c >= '0') || (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a');
}

void TextUtility::replaceAtLocationToLocation(std::string &str, const std::string& replaceStr, uint32_t from, uint32_t to)
{
    if(to < from) return;

    std::string left = str.substr(0, from);
    std::string right = str.substr(to, str.size() - to);

    str = left + replaceStr + right;
}