#include <iostream>
using namespace std;

int print(int n)
{
    if (n == 0)
    {
        return 0;
    }
    print(n - 1);
    cout << n << " ";
    // return 0;
}

int print2(int n)
{
    if (n == 0)
    {
        return 0;
    }
    cout << n << " ";
    print2(n - 1);
    // return 0;
}

int main()
{
    cout << "Enter a number for printing from 1 to the number and from the number to 1: ";
    int n;
    cin >> n;
    cout << "Print number from 1 to " << n << ":\n";
    print(n);
    cout << "\nPrint number from " << n << " to 1:\n";
    print2(n);
    return 0;
}