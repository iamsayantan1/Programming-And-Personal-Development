#include <bits/stdc++.h>
using namespace std;

int charLength(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    return charLength(str + 1) + 1;
}

int main()
{
    cout << "Enter a string within 99 char: ";
    char str[100];
    cin >> str;
    cout << "Char length = " << charLength(str) << endl;
    return 0;
}