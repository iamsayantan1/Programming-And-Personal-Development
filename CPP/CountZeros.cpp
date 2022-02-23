#include <iostream>
using namespace std;

int CountZeros(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n % 10 == 0)
    {
        return CountZeros(n / 10) + 1;
    }
    return CountZeros(n / 10);
}

int main()
{
    cout << "Enter the number to count zeros: ";
    int n;
    cin >> n;
    cout << CountZeros(n);
    return 0;
}