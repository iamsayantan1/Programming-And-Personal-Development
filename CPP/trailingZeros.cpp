#include<iostream>
using namespace std;

int trailingZeros(int n)    {
    int count = 0;
    int div = 5;
    while(n/div>0)  {
        count += n/div;
        div *= 5;
    }
    return count;
}

int main()  {
    cout<<"Enter a number: ";
	int n;
	cin>>n;
	cout<<"Trailing zeros of factorial of "<<n<<" is: "<<trailingZeros(n)<<endl;
    return 0;
}