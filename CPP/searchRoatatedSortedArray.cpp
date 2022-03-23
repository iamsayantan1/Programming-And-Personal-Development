#include<bits/stdc++.h>
using namespace std;

int search(int a[], int s, int e, int key)  {
    while(s<=e) {
        int mid = (s + e)/2;
        if(key == a[mid]) {
            return mid;
        }
        if(a[mid]>=a[s])    {
            if(key>=a[s] && key <= a[mid])  {
                e = mid - 1;
            }
            else    {
                s = mid + 1;
            }
        }
        else   {
            if(key<=a[e] && key >= a[mid])  {
                s = mid + 1;
            }
            else    {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int rotatedSortedArray(int a[], int s, int e, int key)  {
    int mid = (s + e)/2;
    if(s>e)    {
        return -1;
    }
    if(key == a[mid]) {
        return mid;
    }
    else if(a[mid]<a[e]) {
        if(key>a[mid] && key < a[e])  {
            return rotatedSortedArray(a, mid+1, e, key);
        }
        else {
            return rotatedSortedArray(a, s, mid-1, key);
        }
    }
    else if(a[mid]>a[s]) {
        if(key<a[mid] && key>a[s]) {
            return rotatedSortedArray(a, s, mid-1, key);
        }
        else    {
            return rotatedSortedArray(a, mid+1, e, key);
        }
    }
}

int main()
{
    //cout << "Search in rotated Sorted Array" << endl;
    int n;
    //cout << "Enter the number of elements in the array: ";
    cin >> n;
    int a[n];
    //cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int key;
    //cout << "Enter the key: ";
    cin >> key;

    //int loc = rotatedSortedArray(a, 0, n-1, key);
    int loc = search(a, 0, n-1, key);

    if(loc == -1)    {
        cout<<key<<" is not present."<< endl;
    }
    else    {
        cout<< key << " is present at "<< loc <<"."<<endl;
    }


    return 0;
}