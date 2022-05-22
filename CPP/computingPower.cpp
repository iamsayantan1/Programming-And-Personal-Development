#include<bits/stdc++.h>
using namespace std;

double power(int n, int p) {
    if(p == 0) return 1;
    else if(p>0) return n * power(n,p-1);
    else if(p<0) return (1.0/n) * power(n,p+1);
}

double power2(int n, int p) {
    if(!p) return 1;
    double temp = power2(n,p/2);
    temp = temp*temp;
    if(p%2 == 0) return temp;
    else return n*temp;
}

double power3(int n, int p) {
    int res = n;
    while(p>0) {
        if(p&1) {
            res *= n;
        }
        res *= res;
        p = (p>>1);
    }
    return res;
}

int main()  {
    cout<<"Enter a number and it's power: ";
	int x,y;
	cin>>x>>y;
	cout<<x<<"^"<<y<<" = "<<power(x,y)<<"\n"<<power2(x,y)<<"\n"<<power3(x,y)<<endl;
    return 0;
}