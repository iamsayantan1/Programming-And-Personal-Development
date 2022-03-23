#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int n) {
    int major = a[0];
    int count = 0;
    for(int i = 0; i < n; i++)  {
        if(a[i] == major) {
            count++;
        }
        else {
            count--;
        }
        if(count == 0) {
            major = a[i];
            count ++;
        }
    }

    int total = 0;
    for(int i = 0; i < n; i++)  {
        if(a[i] == major) {
            total++;
        }
    }

    if(total > n/2) {
        return major;
    }
    else {
        return -1;
    }
    //return major;
}

int main()  {
    cout<<"majority Element: "<<endl;
    int n;
    cout<<"Enter the length of an array: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array: ";
    for(int i=0; i<n; i++)  {
        cin>>a[i];
    }
    int el = majorityElement(a, n);
    if(el == -1)    {
        cout<<"Majority element is not present."<< endl;
    }
    else    {
        cout<<"Majority element is: "<<el<<"."<<endl;
    }
    return 0;
}