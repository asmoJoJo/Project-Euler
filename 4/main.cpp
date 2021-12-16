#include <iostream>
#include <string>
namespace st = std;

st::string swap(st::string string)   {
    char temp = string[2];
    string[2] = string[0];
    string[0] = temp;
    return string;
}

bool isPalindrome(int number) {
    st::string str1 = st::to_string(number).substr(0, 3);
    st::string str2 = st::to_string(number).substr(3, 3); 
    return !(str1.compare(swap(str2)));
}

int main()  {
    int biggestPalindrome = 0;
    int nrOfPalindromesFound = 0;
    for(int i = 999; i > 900; i--)    {
        for(int j = i; j > 900; j--)   {
            int x = i * j;
            if(isPalindrome(x) && x > biggestPalindrome) biggestPalindrome = x;
        }
    }
    st::cout << biggestPalindrome;
    return 0;
}