#include <bits/stdc++.h>
using namespace std;

void print(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    cout << str[0];
    print(str + 1);
}

void revPrint(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    revPrint(str + 1);
    cout << str[0];
}

int main()
{
    cout << "Enter a string within 99 char: ";
    char str[100];
    cin >> str;
    cout << "Print normally: ";
    print(str);
    cout << endl;
    cout << "Print in reverse: ";
    revPrint(str);
    return 0;
}