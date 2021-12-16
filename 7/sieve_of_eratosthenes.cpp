#include <iostream>
#include <vector>
#include <math.h>
namespace st = std;

typedef uint64_t Int;

int main()  {
    const Int n = 1000000;
    const Int squareRootN = sqrt(n);
    auto vec = std::vector<bool>(n, true);
    
    for(Int i = 2; i <= squareRootN; i++)   {
        if(vec[i])  {
            Int counter = 0, j = i * i;
            while(j <= n)    {
                vec[j] = false;
                counter++;
                j = i * i + counter * i;
            }
        }
    }

    auto nrOfPrimes = 0;
    Int i = 2;
    while(nrOfPrimes < 10001)  {
        if(vec[i])  {
            nrOfPrimes++;
            
            // st::cout << "prime #: " << nrOfPrimes << "\tnumber: " << i << st::endl;
        }
        i+=1;
    }
    st::cout << "\nThe 10 001st prime:\t" << i - 1;

    return 0;
}