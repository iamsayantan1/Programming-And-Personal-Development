#include <bits/stdc++.h>
using namespace std;

void subsequences(string input, string output, vector<string> &subs)
{
    if (input.length() == '\0')
    {
        subs.push_back(output);
        return;
    }
    subsequences(input.substr(1), output, subs);
    subsequences(input.substr(1), output + input[0], subs);
}

int main()
{
    cout << "Enter a string to print subsequences: ";
    string input;
    cin >> input;
    string output = "";
    vector<string> subs;
    cout << "subsequences:" << endl;
    subsequences(input, output, subs);
    for (size_t i = 0; i < subs.size(); ++i)
    {
        cout << subs[i] << endl;
    }
    return 0;
}