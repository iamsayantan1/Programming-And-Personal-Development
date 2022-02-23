#include <bits/stdc++.h>
using namespace std;

int printPositions(int a[], int n, int i, int key)
{
    if (i == n)
    {
        return 0;
    }
    else if (a[i] == key)
    {
        return printPositions(a, n, i + 1, key) + 1;
    }
    return printPositions(a, n, i + 1, key);
}

// int lastIndex2(int a[], int n, int key)
// {
//     if (n <= 0)
//     {
//         return -1;
//     }
//     else if (a[n - 1] == key)
//     {
//         return n - 1;
//     }
//     return lastIndex2(a, n, key);
// }

int main()
{
    // cout << "Enter the length of the array: ";
    int n, key;
    cin >> n;
    // cout << "Enter the array: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    // cout << "Enter a key: ";
    cin >> key;
    cout << printPositions(a, n, i, key);
    return 0;
}