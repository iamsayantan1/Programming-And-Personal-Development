#include<iostream>
using namespace std;

int kthLargestElement(int arr[], int n, int k)  {
    
}

int main()  {
    int length;
    cout<<"Enter length of an array: "<<endl;
    cin>>length;
    cout<<"Enter array: "<<endl;
    int arr[length];

    for(int i=0; i<length; i++)    {
        cin>>arr[length];
    }

    cout<<"Enter which largest element: "<<endl;
    int k;
    cin>>k;

    for(int i=0; i<length; i++)    {
        cout<<arr[length]<<" ";
    }

    int ans = kthLargestElement(arr, length, k);

    cout<<k<<"th largest element: "<<ans<<"."<<endl;

    return 0;
}