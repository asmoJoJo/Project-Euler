#include <iostream>
#include <math.h>

bool isPrime(uint64_t n)
{
    if(n < 2)
        return false;
    if(n < 4)
        return true;
    if(!(n % 2))
        return false;
    if(n < 9)
        return true;
    if(!(n % 3))
        return false;

    // All primes greater than 3 can be written in the form 6k+1 or 6k-1
    uint64_t r = sqrt(n);
    for(uint64_t i = 5; i <=r; i += 6)
    {
        if(!(n % i))
            return false;
        if(!(n % (i + 2)))
            return false;
    }

    return true;
}

int main(void)
{
    const uint64_t bound = (uint64_t)2e6;

    uint64_t sum = 2; // first and only even prime

    for(uint64_t i = 3; i < bound; i += 2)
        if(isPrime(i))  sum += i;

    std::cout << sum << std::endl;

    return 0;
}