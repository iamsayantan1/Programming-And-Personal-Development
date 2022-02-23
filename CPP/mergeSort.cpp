#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int x[], int y[], int array[], int s, int e)
{
    int mid = (s + e) / 2;
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= e)
    {
        if (x[i] < y[j])
        {
            array[k] = x[i];
            i++;
            k++;
        }
        else
        {
            array[k] = y[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        array[k] = x[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        array[k] = y[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    int x[mid + 1];
    int y[e + 1];
    for (int i = 0; i <= mid; i++)
    {
        x[i] = array[i];
    }
    for (int i = mid + 1; i <= e; i++)
    {
        y[i] = array[i];
    }
    mergeSort(x, s, mid);
    mergeSort(y, mid + 1, e);
    mergeArrays(x, y, array, s, e);
}

int main()
{
    cout << "Merge Sort" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int array[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    mergeSort(array, 0, n - 1);
    cout << "Sorted array is ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}