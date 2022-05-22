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
    int lcm = x/gcd(x,y);
    lcm *= y;
	cout<<"LCM of "<<x<<" and "<<y<<" is: "<<lcm<<endl;
    return 0;
}