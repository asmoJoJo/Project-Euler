#include <iostream>
namespace st = std;

int main()  {
    int multipleOfTwenty = 20;
    bool evenlyDivisibleNumberNotFound = true;

    while(evenlyDivisibleNumberNotFound)  {
        multipleOfTwenty += 20;
        for(auto divisor = 11; divisor < 20; divisor++)    {
            if(multipleOfTwenty % divisor != 0) break;
            if(divisor == 19)  evenlyDivisibleNumberNotFound = false;
        }
    }
    st::cout << multipleOfTwenty;

    return 0;
}