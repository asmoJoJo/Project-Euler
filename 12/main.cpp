#include <iostream>
#include <cmath>

int calculateTriangleNr(int n)
    // returns nth triangle nr
{
    return (int)((n * (n + 1)) / 2);
}

int findNrOfDivisors(int n)
{
    if(n < 1)
        return 0;
    if(n == 1)
        return 1;
    
    int nrOfDivisors = 2; // every n > 1 has 1 and itself as divisors

    for(int i = 2; i <= n/2; ++i)
    {
        if(!(n % i))
            ++nrOfDivisors;
    }

    return nrOfDivisors;
}

int main(void)
{
    int nrOfDivisors = 1;
    int count = 33; // first triangle number thats over 500
    int triangleNr = 0;

    int old = 0;

    while(nrOfDivisors <= 500 && nrOfDivisors > 0)
    {
        triangleNr = calculateTriangleNr(count);
        nrOfDivisors = findNrOfDivisors(triangleNr);

        count++;
    }
    
    std::cout << "Count: " << count << "\t\ttriangleNR: " << triangleNr << "\t#OfDivisors: " << nrOfDivisors;

    return 0;
}
