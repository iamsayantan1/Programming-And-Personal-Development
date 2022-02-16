#include <iostream>
using namespace std;

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    return n * power(n, p - 1);
}

int main()
{
    cout << "Enter a number and it's power: ";
    int n, p;
    cin >> n >> p;
    cout << n << " to the power " << p << " is " << power(n, p) << ".";
    return 0;
}