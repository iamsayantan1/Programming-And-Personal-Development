#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter how many numbers: ";
    int n = 0;
    cin >> n;
    cout << "Enter the numbers: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    BubbleSort(arr, n);
    sort(arr, arr + n);
    cout << "\n"
         << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}