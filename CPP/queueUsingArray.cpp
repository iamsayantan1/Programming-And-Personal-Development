#include<iostream>
using namespace std;

template<typename T>
class Queue {
    T* arr;
    int capacity = 0;
    int t=-1;
    int h=0;
    int length = 0;
    
public:
    Queue(int capacity) : capacity(capacity)    {
        arr = new T[capacity];
    }
    void push(T data) {
        if(length < capacity)    {
            if(t == capacity-1)   {
                t = 0;
                arr[t] = data;
            }
            else{
                t = t+1;
                arr[t] = data;
            }
            length++;
        }
        else    {
            cout<<"Queue is full!"<<endl;
        }
    }
    
    void pop() {
        if(length == 0)  {
            cout<<"Empty Queue!"<<endl;
        }
        else{
            length--;
            h++;
            if(h==capacity) {
                h=0;
            }
        }
    }

    T front() {
        if(length>0)    {
            return arr[h];
        }
        else return 0;
    }

    T back() {
        if(length>0)    {
            return arr[t];
        }
        else return 0;
    }

    int size() {
        return length;
    }

    bool isEmpty() {
        return length == 0;
    }
};

int main()  {
    Queue<int> q(4);
    // q.push(3);
    // q.push(5);
    // q.push(7);
    // q.push(6);
    // q.pop();
    // q.pop();
    // q.push(8);
    // q.push(12);

    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.push(23);
    // q.push(25);
    // q.push(29);
    // q.push(39);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    if(q.isEmpty()) {
        cout<<"Empty Queue!"<<endl;
    }
    else    {
        cout<<"Not Empty"<<endl;
    }
    cout<<endl;
    return 0;
}