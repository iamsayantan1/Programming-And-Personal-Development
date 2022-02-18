#include <bits/stdc++.h>
using namespace std;

int converter(string input, int i)
{
    if (i < 0)
    {
        return 0;
    }

    return converter(input, i - 1) * 10 + (input.at(i) - '0');
}

int main()
{
    cout << "Enter a string to convert it into an integer: ";
    string input;
    cin >> input;
    int i = input.length() - 1;
    cout << converter(input, i);
    return 0;
}