#include <bits/stdc++.h>
using namespace std;

void subsequences(string input, string output)
{
    if (input.length() == '\0')
    {
        cout << output << endl;
        return;
    }
    subsequences(input.substr(1), output);
    subsequences(input.substr(1), output + input[0]);
}

int main()
{
    cout << "Enter a string to print subsequences: ";
    string input;
    cin >> input;
    string output = "";
    cout << "subsequences:" << endl;
    subsequences(input, output);
    return 0;
}