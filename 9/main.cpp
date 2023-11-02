#include <iostream>
#include <math.h>

bool isPerfectSquare(int n)
/*
    All square numbers end in either 0, 1, 4, 9 in base 16. Source:
    http://www.johndcook.com/blog/2008/11/17/fast-way-to-test-whether-a-number-is-a-square/
*/
{
    int h = n & 0xF; // last hexadecimal "digit"
    if (h > 9)
        return false; // return immediately in 6 cases out of 16.

    // Take advantage of Boolean short-circuit evaluation
    if(h == 0 || h == 1 || h == 4 || h == 9)
    {
        // take square root if you must
        int t = (int) (sqrt((double) n) + 0.5 );
            return t*t == n;
    }
    return false;
}

void findPythagoreanTriplet(int& a, int& b, int& c)
/*
    A < B < C
    A cannot be bigger than 300
    B cannot be bigger than 500
*/
{
    for(a = 1; a < 300; ++a)
    {
        for(b = a + 1; b < 500; ++b)
        {
            int temp = a*a + b*b;
            bool isSquare = isPerfectSquare(temp);
            if(!isSquare)
                continue;
            c = sqrt(temp);
            if(a + b + c == 1000)
                return;
        }
    }
}

int findProduct()
{
    int a = 0, b = 0, c = 0;
    findPythagoreanTriplet(a, b, c);
    std::cout << "a = " << a << '\n'
              << "b = " << b << '\n'
              << "c = " << c << std::endl;
    return a * b * c;
}

int main(void)
{
    std::cout << findProduct() << std::endl;

    return 0;
}