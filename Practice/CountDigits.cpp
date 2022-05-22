#include<iostream>
#include<cmath>
using namespace std;

int countDigits(int n)	{
	return 1+floor(log10(n));
}

int main()	{
	cout<<"Enter a number: ";
	int n;
	cin>>n;
	cout<<"No. of digits of "<<n<<" is: "<<countDigits(n)<<endl;
	return 0;
}