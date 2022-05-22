#include<bits/stdc++.h>
using namespace std;

int helper2(int n, int a[])  {
    if(n<1) return 0;
    if(n==1)    return 0;
    if(a[n] != -1) return a[n];
    int x = INT_MAX; 
    int y = INT_MAX; 
    int z = INT_MAX;
    if(n%3 == 0) {
        x = helper2(n/3, a);
    }
    if(n%2 == 0) {
        y = helper2(n/2, a);
    }
    z = helper2(n-1, a);
    
    int op = min(x,min(y,z)) + 1;
    a[n] = op;
    return op;
}

int minStepsTo12(int n)    {
    int *a = new int[n+1];
    for(int i=0; i<=n; i++)  {
        a[i] = -1;
    }
    int ans =  helper2(n, a);
    delete[] a;
    return ans;
}

int minStepsTo13(int n)  {
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i <= n; i++)  {
        int x = INT_MAX;
        int y = INT_MAX;
        if(i%2 == 0)    {
            x = dp[i/2];
        }
        if(i%3 == 0)    {
            y = dp[i/3];
        }
        int z = dp[i-1];

        dp[i] = min(x,min(y,z)) +1;
    }
    int ans = dp[n];
    delete[] dp;
    return ans;
}

int minStepsTo1(int n)  {
    if(n<1) return INT_MIN;
    if(n==1)    return 0;
    int x = INT_MAX; 
    int y = INT_MAX; 
    int z = INT_MAX;
    if(n%3 == 0) {
        x = minStepsTo1(n/3);
    }
    if(n%2 == 0) {
        y = minStepsTo1(n/2);
    }
    z = minStepsTo1(n-1);
    
    return min(x,min(y,z)) + 1;
}

int main()  {
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    // cout<<"Minimum no of steps is: "<<minStepsTo1(n)<<endl;
    cout<<"Minimum no of steps is: "<<minStepsTo12(n)<<endl;
    cout<<"Minimum no of steps is: "<<minStepsTo13(n)<<endl;
    return 0;
}