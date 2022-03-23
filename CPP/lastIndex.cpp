#include <bits/stdc++.h>
using namespace std;

int lastIndex(int a[], int n, int i, int key)
{
    if (i < 0)
    {
        return -1;
    }
    else if (a[i] == key)
    {
        return i;
    }
    return lastIndex(a, n, i - 1, key);
}

int lastIndex2(int a[], int n, int key)
{
    if (n <= 0)
    {
        return -1;
    }
    else if (a[n - 1] == key)
    {
        return n - 1;
    }
    return lastIndex2(a, n - 1, key);
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
    int i = n - 1;
    cout << "Enter a key: ";
    cin >> key;
    // int ans = lastIndex(a, n, i, key);
    int ans = lastIndex2(a, n, key);
    if (ans == -1)
    {
        cout << key << " is not present.";
    }
    else
    {
        cout << "last index of " << key << " is " << ans << ".";
    }
    return 0;
}