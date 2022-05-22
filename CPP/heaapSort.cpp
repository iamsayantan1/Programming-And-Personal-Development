#include<bits/stdc++.h>
using namespace std;

void insert(int arr[], int n)    {
    for (int i = 1; i < n; i++) {
        int ci = i;
        int pi = (ci-1)/2;
        while(ci > 0 && arr[ci]>arr[pi])    {
            swap(arr[ci],arr[pi]);
            ci = pi;
            pi = (pi-1)/2;
        }
    }
}

void removeMax(int arr[], int n) {
    while(n != 0)   {
        if(n == 0) return;
        swap(arr[0],arr[n-1]);
        n=n-1;

        int pi = 0;
        while(true) {
            int lci = 2*pi+1;
            int rci = 2*pi+2;
            int max = pi;
            if(lci < n && arr[lci] > arr[max])    {
                max = lci;
            }
            if(rci < n && arr[rci] > arr[max]) {
                max = rci;
            }
            if(pi == max)   {
                break;
            }
            swap(arr[pi],arr[max]);
            pi = max;
        }
    }
}

void heapSort(int arr[], int n) {
    insert(arr, n);
    removeMax(arr, n);
}

int main()  {
    cout<<"Enter the length of array: ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the array: ";
    for(int i=0;i< n; i++)  {
        cin>>a[i];
    }

    heapSort(a, n);

    for(int i=0;i< n; i++)  {
        cout<<a[i]<<" ";
    }

    return 0;
}