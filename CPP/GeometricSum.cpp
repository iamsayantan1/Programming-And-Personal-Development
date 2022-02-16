#include <bits/stdc++.h>
using namespace std;

double GeometricSum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return GeometricSum(n - 1) + (1.0 / pow(2, n - 1));
}

int main()
{
    cout << "Enter a number for GeometricSum: ";
    int n;
    cin >> n;
    cout << GeometricSum(n);
    return 0;
}