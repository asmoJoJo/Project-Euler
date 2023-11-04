#include<iostream>
#include<fstream>

double readNumbers(std::ifstream& ifs)
{
    double d = 0;
    double sum = 0;
    while(ifs >> d)
        sum += d;
    return sum;   
}


int main(void)
{
    // read file
    const char* ifname{"input.txt"};
    std::ifstream ifs{ifname};
    ifs.exceptions(ifs.exceptions()|std::ios_base::badbit);

    double sum = readNumbers(ifs);
    
    std::cout.precision(11);
    std::cout << sum << std::endl;

    return 0;
}