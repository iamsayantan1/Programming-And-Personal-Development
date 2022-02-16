#include <iostream>
using namespace std;

int NoOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return NoOfDigits(n / 10) + 1;
}

int main()
{
    cout << "Enter a number to count it's digits: ";
    int n;
    cin >> n;
    cout << n << " contains " << NoOfDigits(n) << " digits." << endl;
    return 0;
}