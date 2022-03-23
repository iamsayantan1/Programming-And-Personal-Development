#include<iostream>
using namespace std;

template<typename T>
class Node  {
public:
    T data;
    Node* next;
    Node(T data) : data(data), next(NULL) {}
};

template<typename T>
class Stack {
    Node<T>* head = NULL;
    Node<T>* temp = NULL;
    int length = 0;

public:
    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode -> next = head;
        head = newNode;
        length++;
    }

    void pop() {
        if(!head) {
            cout<<"Can't pop, Empty stack!"<<endl;
        }
        else {
            temp = head;
            head = head->next;
            temp -> next = NULL;
            delete temp;
            length--;
        }
    }

    void Top() {
        if(!head) {
            cout<<"Stack is empty!"<<endl;
        }
        else    {
            cout<<head->data<<endl;
        }
    }

    int size()    {
        return length;
    }

    bool isEmpty()  {
        return length == 0;
    }
};

int main()  {
    Stack<int> s;
    // s.pop();
    // s.pop();
    s.push(8);
    s.push(9);
    s.push(12);
    s.push(90);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(2);
    
    s.Top();
    cout<<s.size()<<endl;
    if(s.isEmpty()) {
        cout<<"Stack is empty!"<<endl;
    }
    else    {
        cout <<"Stack is not empty!"<<endl;
    }

    return 0;
}