#include <bits/stdc++.h>
using namespace std;

bool isSortedArray(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    else if (a[n - 1] > a[n - 2])
    {
        return false;
    }
    return (isSortedArray(a, n - 1));
}

bool isSortedArray2(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    else if (a[1] < a[0])
    {
        return false;
    }

    return isSortedArray2(a + 1, n - 1);
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
    if (isSortedArray2(a, n))
    {
        cout << "Array is sorted.";
    }
    else
    {
        cout << "Array is not sorted.";
    }
    return 0;
}