#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int x[], int y[], int array[], int s, int e)
{
}

void quickSort(int a[], int s, int e)
{
    int p = a[e];
}

int main()
{
    cout << "Quick Sort" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    cout << "Sorted array is ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}