#include <bits/stdc++.h>
using namespace std;

void firstAndLastOccurance(int a[], int s, int e, int key, int &f, int &l) {
    int mid = (s + e) / 2;
    if(s>e) {
        return;
    }
    if(a[mid] == key) {
        if(f>mid)   {
            f = mid;
        }
        if(l<mid) {
            l = mid;
        }
    }
    if(a[mid] >= key) {
        firstAndLastOccurance(a, s, mid-1, key, f, l);
    }
    if(a[mid] <= key) {
        firstAndLastOccurance(a, mid+1, e, key, f, l);
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

    int f = INT_MAX, l = INT_MIN;

    firstAndLastOccurance(a, 0, n-1, key, f, l);

    if(f == INT_MAX)    {
        cout<<key<<" is not present."<< endl;
    }
    else    {
        cout<<"First occurance of "<< key << " is "<<f<<" and last occurance of "<<key << " is " <<l<<"."<<endl;
    }

    //int bs = binarySearch(a, 0, n-1, key);
    //cout << "Sorted array is ";
    // if(bs == -1)    {
    //     cout<<key<<" is not present."<< endl;
    // }
    // else    {
    //     cout<<key<<" is present at "<<bs<<"."<<endl;
    // }
    return 0;
}