#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int s, int e, int key) {
    int mid = (s + e) / 2;
    if(s>e) {
        return -1;
    }
    else if(a[mid] == key) {
        return mid;
    }
    else if(a[mid] > key) {
        return binarySearch(a, s, mid-1, key);
    }
    else {
        return binarySearch(a, mid+1, e, key);
    }
}

int main()
{
    cout << "Binary Search" << endl;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;
    int bs = binarySearch(a, 0, n-1, key);
    //cout << "Sorted array is ";
    if(bs == -1)    {
        cout<<key<<" is not present."<< endl;
    }
    else    {
        cout<<key<<" is present at "<<bs<<"."<<endl;
    }
    return 0;
}