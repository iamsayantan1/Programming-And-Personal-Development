#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()  {
    cout<<"Enter array: ";
    int* arr = new int[5];
    for(int i=0; i<5; i++) {
        cin>>arr[i];
    }
    
    for(int i=0; i<5 ; i++)    {
        cout<<*arr<<" ";
        arr+=1;
    }
    return 0;
}