#define START 1
#define END 100

#include <iostream>
namespace st = std;

int sumOfSquares()  {
    int sum = 0;
    for(int i = START; i <= END; i++)   {
        sum += i*i;
    }
    return sum;
}

int squareOfSum() {
    int sum = (START + END) * (END / 2);
    return sum * sum;
}

int main()  {
    st::cout << abs(sumOfSquares() - squareOfSum());
}