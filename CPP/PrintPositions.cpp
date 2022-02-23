#include <bits/stdc++.h>
using namespace std;

void printPositions(int a[], int n, int i, int key)
{
    if (i == n)
    {
        return;
    }
    else if (a[i] == key)
    {
        cout << i << " ";
    }
    printPositions(a, n, i + 1, key);
}

void printPositions2(int a[], int n, int key)
{
    if (n <= 0)
    {
        return;
    }
    else if (a[n - 1] == key)
    {
        cout << n - 1 << " ";
    }
    printPositions2(a, n - 1, key);
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
    // printPositions(a, n, i, key);
    printPositions2(a, n, key);
    return 0;
}