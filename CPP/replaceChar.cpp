#include <bits/stdc++.h>
using namespace std;

void replaceChar(char str[], char a, char b)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == a)
    {
        str[0] = b;
    }
    replaceChar(str + 1, a, b);
}

int main()
{
    cout << "Enter a string within 99 char: ";
    char str[100], a, b;
    cin >> str;
    cout << "Enter which character you want to replace by whom: ";
    cin >> a >> b;
    replaceChar(str, a, b);
    cout << str;
    return 0;
}