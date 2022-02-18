#include <bits/stdc++.h>
using namespace std;

void permuteString(char input[], int i)
{
    if (input[i] == '\0')
    {
        cout << input << endl;
        return;
    }
    for (int j = i; input[j] != '\0'; j++)
    {
        swap(input[i], input[j]);
        permuteString(input, i + 1);
        swap(input[i], input[j]);
    }
}

int main()
{
    cout << "Enter a string within 99 char: ";
    char input[100];
    string output = "";
    cin >> input;
    permuteString(input, 0);
    return 0;
}