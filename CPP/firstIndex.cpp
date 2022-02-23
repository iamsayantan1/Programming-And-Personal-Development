#include <bits/stdc++.h>
using namespace std;

int firstIndex(int a[], int n, int i, int key)
{
    if (n <= i)
    {
        return -1;
    }
    else if (a[i] == key)
    {
        return i;
    }
    return firstIndex(a, n, i + 1, key);
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
    int i = 0;
    cout << "Enter a key: ";
    cin >> key;
    int ans = firstIndex(a, n, i, key);
    if (ans == -1)
    {
        cout << key << " is not present.";
    }
    else
    {
        cout << "1st index of " << key << " is " << ans << ".";
    }
    return 0;
}