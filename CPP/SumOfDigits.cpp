#include <iostream>
using namespace std;

int SumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return SumOfDigits(n / 10) + n % 10;
}

int main()
{
    cout << "Enter a number to get the sum of the digits: ";
    int n;
    cin >> n;
    cout << "Sum of the digits of " << n << " is " << SumOfDigits(n) << ".";
    return 0;
}