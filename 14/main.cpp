#include <iostream>

bool isEven(int n)
{
    return (!(n%2));
}

bool isOdd(int n)
{
    return (!(isEven(n)));
}

int findNext(int n, int nrOfTerms)
{
    if(n <= 1)
        return nrOfTerms;
    if(isEven(n))
        findNext(n/2, nrOfTerms+1);
    else if(isOdd(n))
        findNext(3*n+1, nrOfTerms+1);
}

int calculateCollatzSeq(int n)
{
    return findNext(n, 1);
}

int main(void)
{
    int superiorTerm = 0;
    int nrOfTerms = 0;

    for(int i = 1000000; i >= 1; --i)
    {
        int temp = calculateCollatzSeq(i);
        
        if(temp > nrOfTerms)
        {
            nrOfTerms = temp;
            superiorTerm = i;
        }
        
        std::cout << "n = " << i << "\t\tTerms: " << temp << '\n';
    }

    std::cout << "The starting term with the longest sequence is " << superiorTerm << " with " << nrOfTerms << " terms!\n";

    return 0;
}