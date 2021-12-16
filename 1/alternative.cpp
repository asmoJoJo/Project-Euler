#include <iostream>
#include <math.h>

int sumDivisibleByN(int n, int target)  {
    int p = target / n;
    return n * (p * (p + 1)) / 2;
}

int main()  {
    int target = 999;

    std::cout << sumDivisibleByN(3, target) + sumDivisibleByN(5, target) - sumDivisibleByN(15, target);
}