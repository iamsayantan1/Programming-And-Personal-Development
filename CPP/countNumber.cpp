#include<iostream>
#include<cmath>
using namespace std;

int countDigits(int n)	{
	return 1+floor(log10(n));
}

int countDigits2(int n)	{
    int count = 0;

    while(n>0)  {
        count++;
        n=n/10;
    }

	return count;
}

int countDigits3(int n)	{
    if(n<=0) {
        return 0;
    }
	return 1+countDigits3(n/10);
}

int main()	{
	cout<<"Enter a number: ";
	int n;
	cin>>n;
	cout<<"No. of digits of "<<n<<" is: "<<countDigits(n)<<" "<<countDigits2(n)<<" "<<countDigits3(n)<<endl;
	return 0;
}