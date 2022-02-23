#include <bits/stdc++.h>
using namespace std;

void removeChar(char str[], char x)
{
    if (str[0] == '\0')
    {
        return;
    }
    else if (str[0] == x)
    {
        for (size_t i = 0; str[i] != '\0'; i++)
        {
            str[i] = str[i + 1];
        }
    }
    removeChar(str + 1, x);
}

int main()
{
    cout << "Enter a string within 99 char: ";
    char str[100], x;
    cin >> str;
    cout << "Enter which character you want to remove: ";
    cin >> x;
    removeChar(str, x);
    cout << str;
    return 0;
}