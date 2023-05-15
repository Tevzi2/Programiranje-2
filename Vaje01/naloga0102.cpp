#include <iostream>
#include <math.h>

#define NEGATIVE_NUMBER -1

int countDigits(const int number)
{
    int counter = 0;
    double cast_number = static_cast<double>(number);

    if(number == 0)
        return 1;

    while(cast_number >= 1)
    {
        counter++;
        cast_number /= 10;
    }

    return counter;
}

void numberOfDiffrentDigits(const int number)
{
    int digits[10] { 0 };

    int numberOfDigits = countDigits(number);

    int number_copy = number;

    for(unsigned char i = numberOfDigits; i > 0; i--)
    {
        int current_most_significant_digit = number_copy - (number_copy % static_cast<int>(pow(10, i - 1)));

        number_copy -= current_most_significant_digit;

        current_most_significant_digit /= pow(10, i - 1);

        digits[current_most_significant_digit]++;
    }

    for(uint32_t i = 0; i < 10; i++)
    {
        std::cout << "Stevilo stevk " << i << " v stevilu je " << digits[i] << std::endl;
    }
}

bool isDisariumNumber(const int number)
{
    int number_copy = number;
    int digits = countDigits(number);
    int disarium_sum = 0;

    for(unsigned char i = digits; i > 0; i--)
    {
        int current_most_significant_digit = number_copy - (number_copy % static_cast<int>(pow(10, i - 1)));

        number_copy -= current_most_significant_digit;

        current_most_significant_digit /= pow(10, i - 1);

        disarium_sum += pow(current_most_significant_digit, digits - (i - 1));
    }

    return number == disarium_sum;
}

int main()
{
    int input;

    std::cout << "Vnesite stevilo: ";
    std::cin >> input;

    do
    {
        if(input >= 0)
            break;

        std::cout << "Vnesite stevilo: ";
        std::cin >> input;

    } while(true);

    if(isDisariumNumber(input))
        std::cout << "Stevilo " << input << " je Disarium stevilo" << std::endl;
    else
        std::cout << "Stevilo " << input << " ni Disarium stevilo" << std::endl;

    numberOfDiffrentDigits(input);

    return 0;
}