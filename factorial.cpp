#include<iostream>
using namespace std;

int factorial(int n)    {
    if(n <= 0) return 1;
    else return n*factorial(n-1);
}

int factorial2(int n)    {
    int fact = 1;
    for(int i=2;i<=n;i++) {
        fact *= i;
    } 
    return fact;
}

int main()  {
    cout<<"Enter a number: ";
	int n;
	cin>>n;
	cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<" "<<factorial2(n)<<endl;
    return 0;
}