#include <iostream>
#include <vector>
#include <math.h>
namespace st = std;

typedef  uint64_t Int;

bool isPrime(Int aNumber)   {
    for(Int i = 2; i < aNumber; i++)   {
        if(!(aNumber % i)) return false;
    }
    return true;
}

void addPrimeNumber(st::vector<Int> &list)  {
    auto possiblePrimeNumber = list.back();
    bool found = false;
    while(!found)   {
        ++possiblePrimeNumber;
        found = isPrime(possiblePrimeNumber);
    }
    list.push_back(possiblePrimeNumber);
}

bool isDivisible(Int &bigNumber, const Int &prime, Int &biggestPrimeFactor)  {
    if(!(bigNumber % prime))    {
        bigNumber /= prime;
        biggestPrimeFactor = prime;
        return true;
    }
    return false;
}

int main()  {
    st::vector<Int> primes{2, 3, 5, 7, 11, 13, 17, 19};
    Int bigNumber = 600851475143;
    Int biggestPrimeFactor = primes.back();
    while(!isPrime(bigNumber))    {
        bool division = false;
        for(auto &prime: primes)    {
            division = isDivisible(bigNumber, prime, biggestPrimeFactor);
            if(division) break;
        }
        while(!division)    {
            addPrimeNumber(primes);
            auto prime = primes.back();
            division = isDivisible(bigNumber, prime, biggestPrimeFactor);
        }
    }
    auto finalAmswer = (biggestPrimeFactor > bigNumber) ? biggestPrimeFactor : bigNumber;
    st::cout << finalAmswer;
}