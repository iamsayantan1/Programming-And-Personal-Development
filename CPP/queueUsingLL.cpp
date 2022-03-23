#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data) : data(data), next(NULL) {}
};

template<typename T>
class Queue {
    int length;
    Node<T>* head;
    Node<T>* tail;
    Node<T>* temp;
    T data;
public:
    Queue() : length(0), head(NULL), tail(NULL), temp(NULL) {}

    void push(T data) {
        length++;
        Node<T> *newNode = new Node<T>(data);
        if(!head)   {
            head = tail= newNode;
        }
        else    {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void pop() {
        if(!head) {
            cout<<"Empty Queue!"<<endl;
        }
        else    {
            length--;
            temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    T front() {
        if(!head)   {
            cout<<"Empty Queue!"<<endl;    
            return 0;
        }
        return head->data; 
    }

    T back() {
        if(!head)   {
            cout<<"Empty Queue!"<<endl;    
            return 0;
        }
        return tail->data; 
    }

    int size() {
        return length;
    }

    bool isEmpty() {
        return !head;
    }
};

int main()  {
    Queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(10);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<"back Element: "<<q.back()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    cout<<"isEmpty? : ";
    if(q.isEmpty()) {
        cout<<"Queue is empty!"<<endl;
    }
    else    {
        cout<<"Queue is not empty!"<<endl;
    }
    return 0;
}