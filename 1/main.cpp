#include<iostream>

bool isXMultipleOfY(int x, int y)   {
    return !(x % y);
}

int main()  {
    auto sum = 0;
    for(int i = 0; i < 1000; i++) {
        if(isXMultipleOfY(i, 3) || isXMultipleOfY(i, 5))    {
            sum += i;
        }
    }
    std::cout << sum;

    return 0;
}