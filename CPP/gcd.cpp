#include<iostream>
using namespace std;

int gcd(int x, int y)    {
    if(y == 0)    {
        return x;
    }
    else    {
        gcd(y,x%y);
    }
}

int main()  {
    cout<<"Enter two numbers: ";
	int x,y;
	cin>>x>>y;
	cout<<"GCD of "<<x<<" and "<<y<<" is: "<<gcd(x,y)<<endl;
    return 0;
}