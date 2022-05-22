#include<bits/stdc++.h>
using namespace std;

bool iskSorted(int a[], int n, int k)  {
    priority_queue<int> pq;
    vector<int> v;
    bool iskSorted = true;

    for(int i=0;i< n; i++)  {
        pq.push(a[i]);
    }

    while(!pq.empty())  {
        v.push_back(pq.top());
        pq.pop();
    }

    for(int i=0;i< n; i++) {
        bool flag = false;
        for(int j=i-k+1;j<i+k;j++) {
            if(j>=0 && j<n) {
                if(a[i] == v[j])    {
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) {
            iskSorted = flag;
            break;
        }
    }
    return iskSorted;
}

void kSort(int a[], int n, int k)   {
    priority_queue<int> pq;
    for(int i=0;i< k; i++)  {
        pq.push(a[i]);
    }

    int s = 0;

    for(int i=k;i< n; i++)  {
        pq.push(a[i]);
        a[s++] = pq.top();
        pq.pop();
    }

    while(!pq.empty())  {
        a[s++] = pq.top();
        pq.pop();
    }
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

    // bool ans = iskSorted(a, n, k);

    // if(ans) {
    //     cout<<"Array is k sorted."<<endl;
    // }
    // else    {
    //     cout<<"Array is not k sorted."<<endl;
    // }

    kSort(a, n, k);

    for(int i=0;i< n; i++)  {
        cout<<a[i]<<" ";
    }  

    return 0;
}