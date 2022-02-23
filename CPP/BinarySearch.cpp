#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int val)
{
    int s = 0;
    int e = n - 1;
    int middle = 0;
    while (e >= s)
    {
        middle = s + (e - s) / 2;
        if (arr[middle] == val)
        {
            return middle;
        }
        else if (val > arr[middle])
        {
            s = middle + 1;
        }
        else
        {
            e = middle - 1;
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
    int k = BinarySearch(arr, n, val);
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