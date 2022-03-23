<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int findCorrectPos(int a[], int s, int e)
{
    int count = s;
    int i=s, j=e;
    for (int i = s; i < e; i++) {
        if(a[e]>a[i])   {
            count++;
        }
    }
    swap(a[count],a[e]);
    while(i<count || j>count)   {
        if(a[i]<a[count]) {
            i++;
        }
        else if(a[j]>a[count])  {
            j--;
        }
        else    {
            swap(a[i],a[j]);
        }
    }
    return count;
}

void quickSort(int a[], int s, int e)
{
    if(s>=e){
        return;
    }
    int key = findCorrectPos(a, s, e);
    quickSort(a, s, key-1);
    quickSort(a,key+1,e);
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
=======
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
>>>>>>> d430e7484d1a6fea6c0fcdb61b54cae3c9cd8776
}