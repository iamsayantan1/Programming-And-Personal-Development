#include <bits/stdc++.h>
using namespace std;

void replaceChar(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    else if (str[0] == str[1])
    {
        for (size_t i = 0; str[i] != '\0'; i++)
        {
            str[i] = str[i + 1];
        }
        replaceChar(str);
    }
    replaceChar(str + 1);
}

int main()
{
    cout << "Enter a string within 99 char: ";
    char str[100];
    cin >> str;
    replaceChar(str);
    cout << str;
    return 0;
}