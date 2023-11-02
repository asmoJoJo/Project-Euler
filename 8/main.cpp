#include <iostream>

constexpr int nrOfDigits = 1000;
constexpr int nrOfAdjacentDigits = 13;
constexpr int nrOfCalculations = nrOfDigits - nrOfAdjacentDigits + 1;

extern char* s;

int charToInt(char c)
{
    return c - '0';
}

uint64_t findHighestProduct()
{
    uint64_t max = 0;

    for(int i = 0; i < nrOfCalculations; ++i)
    {
        uint64_t product = 1;
        for(int j = 0; j < nrOfAdjacentDigits; ++j)
        {
            product *= (uint64_t)charToInt(s[i + j]);
        }
        max = product > max ? product : max;
    }

    return max;
}

int main(void)
{
    std::cout << "Largest product = " << findHighestProduct() << std::endl;

    return 0;
}