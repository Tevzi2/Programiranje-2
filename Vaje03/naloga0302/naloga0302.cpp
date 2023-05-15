#include <iostream>
#include "TextUtility.hpp"

int main()
{
    std::cout << "Aiasdhf123g4auh6 is alphanumaric: " << TextUtility::isAlphanumeric("Aiasdhf123g4auh6") << std::endl;
    std::cout << "a9sudgh! isnt alphanumaric: " << TextUtility::isAlphanumeric("a9sudgh!") << std::endl;
    std::cout << "a9sudgh! isnt alphanumaric: " << TextUtility::isAlphanumeric("a9sudgh!") << std::endl;
    std::cout << "!a9sudgh isnt alphanumaric: " << TextUtility::isAlphanumeric("!a9sudgh") << std::endl;
    std::cout << "a9s!udgh isnt alphanumaric: " << TextUtility::isAlphanumeric("a9s!udgh") << std::endl;
    std::cout << "a9sudgh is alphanumaric: " << TextUtility::isAlphanumeric("a9sudgh") << std::endl;
    std::cout << std::endl;
    std::cout << "Text diffrence of 'This is a big bunny' and 'th2s is a small bunny' is: " << TextUtility::difference("This is a big bunny", "th2s is a small bunny") << std::endl;
    std::cout << std::endl;
    std::cout << "Text replace 'sum' in string 'Lorem ipsum dolor sit amet consumetur sed sumeiusmod' with 'aaaaaaa': " << TextUtility::replace("Lorem ipsum dolor sit amet consumetur sed sumeiusmod", "sum", "aaaaaaa") << std::endl;
    std::cout << "Text replace 'day' in string 'Today is a lovely day and its sunday' with 'bunny': " << TextUtility::replace("Today is a lovely day and its sunday", "day", "bunny") << std::endl;
    std::cout << "Text replace 'world' in string 'Hello, world!' with 'test': " << TextUtility::replace("Hello, world!", "world", "test") << std::endl;
    std::cout << std::endl;
    std::cout << "String concatination example of 'Hello,' and ' world!': " << TextUtility::concat("Hello, ", "World!") << std::endl;
    std::cout << TextUtility::longestWord("Today is a neeeice hhah!");
}