#include<iostream>
#include<string>
using namespace std;

void allDivisors(int n)   {
    int i;
    for (i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            cout<<i<<" ";
        }
    }
    for (; i*i > 0; i--) {
        if(n%i == 0) {
            cout<<n/i<<" ";
        }
    }
    cout<<endl;
}

int main()  {
    cout<<"Enter a number: ";
	int n;
	cin>>n;
    allDivisors(n);
    return 0;
}