#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (a[0] != a[n - 1])
    {
        return false;
    }
    return isPalindrome(a + 1, n - 2);
}

int main()
{
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;
    cout << "Enter the array: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (isPalindrome(a, n))
    {
        cout << "Palindrome.";
    }
    else
    {
        cout << "Not palindrome.";
    }

    return 0;
}