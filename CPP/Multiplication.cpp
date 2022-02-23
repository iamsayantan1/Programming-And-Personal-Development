#include <iostream>
using namespace std;

int multiply(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
    return multiply(m, n - 1) + m;
}

int main()
{
    cout << "Enter 2 numbers to multiply(using recursion): ";
    int m, n;
    cin >> m >> n;
    cout << m << " * " << n << " = " << multiply(m, n);
    return 0;
}