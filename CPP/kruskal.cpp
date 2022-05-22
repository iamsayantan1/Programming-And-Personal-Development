#include<bits/stdc++.h>
using namespace std;

void makeSet(int n, int parent[])   {
    for(int i=1;i<=n;i++)    {
        parent[i] = i;
    }
}

int find(int i, int parent[]) {
    while(parent[i] != i)   {
        i = parent[i];
    }
    return i;
}

bool cmp(vector<int> A, vector<int> B)  {
    return A[2] < B[2];
}

int solve(int n, vector<vector<int> > &v) {
    sort(v.begin(), v.end(), cmp);  // Sorting edges on the basis of weights

    int parent[n+1];
    makeSet(n, parent);

    int cost = 0;

    for(int i=0;i<v.size();i++)   {
        int s = v[i][0];
        int d = v[i][1];
        int rS = find(s, parent);
        int rD = find(d, parent);
        if(rS != rD)    {
            cost += v[i][2];
            parent[rS] = rD;    // union
        }
    }
    return cost;
}