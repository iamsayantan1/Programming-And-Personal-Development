#include<bits/stdc++.h>
using namespace std;

vector<int> kSmallest(int* a, int n, int k)  {
    priority_queue<int> pq;
    vector<int> v;

    for (int i = 0; i < k; i++) {
        pq.push(a[i]);
    }

    for (int i = k; i < n; i++) {
        pq.push(a[i]);
        pq.pop();
    }

    while(!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }

    reverse(v.begin(), v.end());

    return v;
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

    cout<<"Enter k: ";
    int k;
    cin>>k;

    vector<int> arr = kSmallest(a, n, k);

    for(int i=0;i< k; i++)  {
        cout<<arr[i]<<" ";
    }  

    return 0;
}