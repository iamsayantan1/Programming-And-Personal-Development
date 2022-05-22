#include<iostream>
#include<vector>
using namespace std;

void sieve(int n)   {
    vector<bool> v(n+1, true);

    v[0] = false;
    v[1] = false;
    for (int i = 2; i <= n; i++) {
        if(v[i] == true) {
            cout<<i<<" ";
            for(int j = i*i; j <= n; j=j+i) {
                v[j] = false;
            }
        }
    }

    cout<<endl;
}

int main()  {
    cout<<"Enter a number: ";
	int n;
	cin>>n;
    sieve(n);
    return 0;
}