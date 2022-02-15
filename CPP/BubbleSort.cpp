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