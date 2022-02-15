// #include <iostream>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << "Enter how many numbers: ";
    int val, n = 0;
    cin >> n;
    cout << "Enter the numbers: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value for search: ";
    cin >> val;
    cout << "\n"
         << "After sorting: ";
    int k = LinearSearch(arr, n, val);
    if (k == -1)
    {
        cout << val << " is not present.";
    }
    else
    {
        cout << "Location of the " << val << " is " << k << ".";
    }
    return 0;
}