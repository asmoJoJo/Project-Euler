#define LIMIT 4000000

#include <iostream>
namespace st = std;

int main()  {
    int sum = 0 , term1 = 1, term2 = 2, term3 = 0;

    while (term2 < LIMIT)   {
        sum += term2;
        term3 = term1 + term2;
        term1 = term3 + term2;
        term2 = term1 + term3;
    }

    st::cout << "sum= " << sum << st::endl;

    return 0;
}