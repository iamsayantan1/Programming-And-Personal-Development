#include <iostream>
using namespace std;

void BubbleSort(int a[], int n)
{
    bool isSorted;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
        }
    }
}

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
    BubbleSort(arr, n);
    cout << "\n"
         << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}