#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
void reverse(queue<T> &q)    {
    stack<T> s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())   {
        q.push(s.top());
        s.pop();
    }
}

int main()  {
    queue<char> q;

    q.push('p');
    q.push('q');
    q.push('r');
    q.push('s');
    q.push('t');
    q.push('u');

    // while(!q.empty()) {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

    cout<<endl;
    reverse(q);
    cout <<"reverse"<<endl;
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}