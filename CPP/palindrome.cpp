#include<iostream>
#include<string>
using namespace std;

int palindrome(int n)   {
    string s = to_string(n);
    int i=0, j=s.length()-1;
    while(i<=j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main()  {
    cout<<"Enter a number: ";
	int n;
	cin>>n;
    if(palindrome(n))    {
        cout<<n<<" is a palindrome."<<endl;
    }
    else{
        cout<<n<<" is not a palindrome."<<endl;
    }
    return 0;
}