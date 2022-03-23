#include<iostream>
#include<queue>
using namespace std;

int main()  {
    queue<int> q;
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);
    q.push(55);
    q.push(65);
    // q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    if(q.empty())   {
        cout<<"Empty"<<endl;
    }
    else    {
        cout<<"Not empty"<<endl;
    }
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}