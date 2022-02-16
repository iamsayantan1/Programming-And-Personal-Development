#include <bits/stdc++.h>
using namespace std;

bool isPresent(int a[], int n, int key)
{
    if (n <= 0)
    {
        return false;
    }
    else if (a[n - 1] == key)
    {
        return true;
    }
    return isPresent(a, n - 1, key);
}

int main()
{
    cout << "Enter the length of the array: ";
    int n, key;
    cin >> n;
    cout << "Enter the array: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter a key: ";
    cin >> key;
    if (isPresent(a, n, key))
    {
        cout << key << " is present in the array.";
    }
    else
    {
        cout << key << " is not present in the array.";
    }
    return 0;
}