<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int val)
{
    int s = 0;
    int e = n - 1;
    int middle;
    while (e > s)
    {
        middle = (s + e) / 2;
        if (arr[middle] == val)
        {
            return middle;
        }
        else if (arr[middle] > val)
        {
            s = middle + 1;
        }
        else if (arr[middle] < val)
        {
            e = middle - 1;
        }
    }
    return -1;
}

int main()
{
    // cout << "Enter how many numbers: ";
    int val, n = 0;
    cin >> n;
    // cout << "Enter the numbers: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "Enter the value for search: ";
    cin >> val;
    // cout << "\n"<< "After sorting: ";
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
=======
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int val)
{
    int s = 0;
    int e = n - 1;
    int middle;
    while (e > s)
    {
        middle = (s + e) / 2;
        if (arr[middle] == val)
        {
            return middle;
        }
        else if (arr[middle] > val)
        {
            s = middle + 1;
        }
        else if (arr[middle] < val)
        {
            e = middle - 1;
        }
    }
    return -1;
}

int main()
{
    // cout << "Enter how many numbers: ";
    int val, n = 0;
    cin >> n;
    // cout << "Enter the numbers: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "Enter the value for search: ";
    cin >> val;
    // cout << "\n"<< "After sorting: ";
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
>>>>>>> d430e7484d1a6fea6c0fcdb61b54cae3c9cd8776
}