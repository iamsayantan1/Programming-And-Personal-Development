#include<iostream>
using namespace std;

int fibonacci(int n)   {
    int a=0;
    int b=1;
    for (int i=0; i<n; i++) {
        // cout<<a<<" ";
        int c = a;
        a = b;
        b = b+c;
    }
    return a;
}

int fib(int n) {
    if(n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}

int fib2(int n, int* a) {
    if(n == 0 || n == 1) return n;

    if(a[n] != 0) return a[n];

    int output = fib2(n-1, a) + fib2(n-2, a);
    a[n] = output;
    return output;
}

int fib3(int n) {
    int* a = new int[n];
    a[0] = 0;
    a[1] = 1;

    for(int i = 2; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
    }

    int ans = a[n];
    delete[] a;
    return ans;  
}

int main()  {
    cout<<"Enter the number for fibonacci: ";
    int n;
    cin>>n;
    int arr[n+1];

    for(int i=0; i<=n; i++)  {
        arr[i] = 0;
    }

    // fibonacci(n);
    cout<<endl;
    // cout<<n<<"th fibonacci is: "<<fib(n)<<endl;
    cout<<n<<"th fibonacci is: "<<fibonacci(n)<<endl;
    cout<<n<<"th fibonacci is: "<<fib2(n, arr)<<endl;
    cout<<n<<"th fibonacci is: "<<fib3(n)<<endl;
    return 0;
}