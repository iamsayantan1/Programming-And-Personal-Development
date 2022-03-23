#include<iostream>
using namespace std;

template<typename T>
class Stack {
    T *stackArray;
    int length;
    T data;
    int i = -1;
public:
    Stack() : length(4)  {
        stackArray = new T[4];
    }
    // Stack(int length) : length(length)   {
    //     stackArray = new int[length];
    // }

    void push(T data) {
        if(i+1<length)    {
            this->data = data;
            stackArray[++i] = data; 
            //cout <<"i = "<<i<<" -> "; 
        }
        else {
            
            T *newArray = new T[2*length];
            for(int j=0; j<length; j++) {
                newArray[j] = stackArray[j];
                j=j+1;
            }
            delete[] stackArray;
            stackArray = newArray;
            length = length*2;

            stackArray[++i] = data;
            //cout <<"i = "<<i<<" Stack is full!"<<endl;
        }
    }

    void pop() {
        if(i >= 0)
            --i;
        else
            cout <<"Stack is empty!"<<endl;
    }

    void top() {
        if(i<0) {
            cout <<"Stack is empty!"<<endl;
        }
        else    {
            cout << stackArray[i]<<endl;
        }
    }

    int size() { 
        return i+1;
    }

    int capacity() { 
        return length;
    }

    bool isEmpty() {
        if(i<0)
            return true;
        else return false;
    }
};

int main()  {
    Stack<char> s;
    s.top();
    if(s.isEmpty()) {
        cout<<"Stack is empty!"<<endl;
    }
    else {
        cout<<"Stack is not empty."<<endl;
    }

    s.push(74);
    s.top();
    s.push(67);
    s.top();
    s.push(83);
    s.top();
    s.push(102);
    s.top();
    s.push(120);
    s.top();

    s.push(84);
    s.top();
    s.push(76);
    s.top();
    s.push(81);
    s.top();
    s.push(106);
    s.top();
    // s.push(12);
    // s.top();
    // s.push(12);
    // s.top();
    
    // s.pop();
    // s.top();
    // s.pop();
    // s.top();
    // s.pop();
    // s.top();
    // s.pop();
    // s.top();
    // s.push(14);
    // s.top();
    // s.push(16);
    // s.top();
    // s.push(2);
    // s.top();

    // cout<<endl;
    // s.top();
    // if(s.isEmpty()) {
    //     cout<<"Stack is empty!"<<endl;
    // }
    // else {
    //     cout<<"Stack is not empty."<<endl;
    // }
    cout<<s.size()<<endl;
    cout<<s.capacity()<<endl;
    return 0;
}