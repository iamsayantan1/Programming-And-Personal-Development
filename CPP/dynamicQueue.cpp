#include<iostream>
using namespace std;

template<typename T>
class Queue {
    int capacity = 4;
    int t=-1;
    int h=0;
    int length = 0;
    T* arr = new T[capacity];
public:
    void push(T data) {
        if(length < capacity)    {
            if(t == capacity-1)   {
                t = 0;
            }
            else{
                t = t+1;
            }
        }
        else    {
            int i=0;
            T* newArr = new T[2*capacity];
            for(int j=h; j<capacity; j++) {
                newArr[i++] = arr[j];
            }
            for(int j=0; j<=t; j++) {
                newArr[i++] = arr[j];
            }
            delete[] arr;
            arr = newArr;
            capacity = 2*capacity;
            h = 0;
            t = i;
        }
        arr[t] = data;
        length++;
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
            cout<<h<<" ";
            return arr[h];
        }
        else return 0;
    }

    T back() {
        if(length>0)    {
            cout<<t<<" ";
            return arr[t];
        }
        else return 0;
    }

    int size() {
        return length;
    }

    int capa() {
        return capacity;
    }

    bool isEmpty() {
        return length == 0;
    }
};

int main()  {
    Queue<int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(6);
    q.pop();
    q.pop();
    q.push(8);
    q.push(12);

    // q.pop();
    // q.pop();

    q.push(23);

    q.push(25);
    q.pop();
    q.pop();
    q.push(29);
    q.push(39);
    q.pop();
    q.push(56);
    q.push(56);
    q.push(56);
    // q.push(56);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(56);
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Capacity: "<<q.capa()<<endl;
    if(q.isEmpty()) {
        cout<<"Empty Queue!"<<endl;
    }
    else    {
        cout<<"Not Empty"<<endl;
    }
    cout<<endl;
    return 0;
}