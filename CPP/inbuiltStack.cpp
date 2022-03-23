#include<iostream>
#include<stack>
using namespace std;

int main()  {
    stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    s.push('f');
    
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    cout <<s.size()<<endl;
    cout <<s.empty()<<endl;

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<s.size()<<endl;

    return 0;
}