#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return -1;
    }
    return n * factorial(n - 1);
}

int main()
{
    cout << "Enter the number to factorial: ";
    int n;
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << ".";
    return 0;
}