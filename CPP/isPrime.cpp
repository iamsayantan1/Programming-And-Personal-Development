#include<iostream>
#include<string>
using namespace std;

int isPrime(int n)   {
    if(n < 2)   {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main()  {
    cout<<"Enter a number: ";
	int n;
	cin>>n;
    if(isPrime(n))    {
        cout<<n<<" is a prime number."<<endl;
    }
    else{
        cout<<n<<" is not a prime number."<<endl;
    }
    return 0;
}